/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:00:43 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/27 18:11:52 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

#include <ncurses.h>

# define RUNNING_INFO "Running info"

# define BUTTON_EXIT "Exit - \'Esc\'"
# define BUTTON_PAUSE "Pause / Unpause - \'Space\'"
# define BUTTON_NEXT_CYCLE "Next cycle - \'Right arrow\'"
# define BUTTON_DEFAULT_SPEED "Default speed - \'Left arrow\'"
# define TITLE_SPEED_UP "Speed UP"
# define TITLE_SPEED_DOWN "Speed DOWN"

/*
** Color
*/

# define COLOR_GRAY				8

/*
** Color pairs
*/

# define GRAY					5
# define GREEN					6
# define YELLOW					7
# define RED					8
# define CYAN					9
# define GRAY_CARRY				10
# define GREEN_CARRY			11
# define YELLOW_CARRY			12
# define RED_CARRY				13
# define CYAN_CARRY				14

/*
** Buttons
*/

# define ESC_BUTTON				27
# define SPACE_BUTTON			' '


# define MIN_COLS_TO_VISU 70
# define MIN_LINES_TO_VISU 70

# define WIN_ARENA_LINES (64 + 4)
# define WIN_ARENA_COLS (64 * 3 + 9)
# define WIN_INFO_LINES (WIN_ARENA_LINES)
# define WIN_INFO_COLS (WIN_ARENA_COLS * 0.25)
# define WIN_HELP_LINES (WIN_ARENA_LINES * 0.25)
# define WIN_HELP_COLS (WIN_ARENA_COLS)

typedef struct		s_visu
{
	WINDOW			*win_arena;
	WINDOW			*win_info;
	WINDOW			*win_help;
	size_t			tty_lines;
	size_t			tty_cols;
}					t_visu;

t_visu					*init_visu(void);
void					init_colors(void);
void					delete_visu(t_visu **visu);

void					assign_players_to_color(void);
void                	draw(void);
void					draw_help(t_visu *visu, ...);

#endif
