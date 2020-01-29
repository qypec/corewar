/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:00:57 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/29 11:55:04 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void					init_win_arena(t_visu *visu)
{
	visu->win_arena = newwin(WIN_ARENA_LINES, WIN_ARENA_COLS, 0, 0);
	box(visu->win_arena, 0, 0);
	wrefresh(visu->win_arena);
}

void					init_win_info(t_visu *visu)
{
	visu->win_info = newwin(WIN_INFO_LINES, WIN_INFO_COLS, 0, WIN_ARENA_COLS);
	// box(visu->win_info, 0, 0);
	wrefresh(visu->win_info);
}

void					init_win_help(t_visu *visu)
{
	visu->win_help = newwin(WIN_HELP_LINES, WIN_HELP_COLS, WIN_ARENA_LINES, 0);
	// box(visu->win_help, 0, 0);
	draw_help(visu);
	wrefresh(visu->win_help);
}

t_visu					*init_visu(void)
{
	t_visu				*visu;

	if (!(visu = (t_visu *)malloc(sizeof(t_visu))))
		exit(-1);
	if (!initscr())
    {
        ft_putendl("Error initialising ncurses.");
        exit(-1);
    }
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();
	init_colors();
	refresh();
	getmaxyx(stdscr, visu->tty_lines, visu->tty_cols);
	if (visu->tty_lines < MIN_LINES_TO_VISU || visu->tty_cols < MIN_COLS_TO_VISU)
	{
		ft_putendl("Enlarge the terminal window, please");
		exit(0);
	}
	init_win_arena(visu);
	init_win_info(visu);
	init_win_help(visu);
	visu->is_stopped = 1;
	visu->speed = 3;
	assign_players_to_color();
	return (visu);
}

void					delete_visu(t_visu **visu)
{
	delwin((*visu)->win_arena);
	delwin((*visu)->win_info);
	delwin((*visu)->win_help);
	free(*visu);
	*visu = NULL;
	endwin();
}
