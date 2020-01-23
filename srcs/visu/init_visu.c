/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:00:57 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/23 19:52:47 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_windows               *init_visu(void)
{
    t_windows			*win;
	struct ttysize		ts;

	if ((win = (t_windows *)malloc(sizeof(t_windows))) == NULL)
		exit(-1);
	initscr();
	curs_set(0);
    noecho();
    ioctl(0, TIOCGSIZE, &ts);
	if (ts.ts_lines < (MAINWIN_LINES + INFO_WIN_LINES) || \
			ts.ts_cols < (MAINWIN_COLS + RUNNING_INFO_WIN_COLS))
	{
		delete_windows(&win);
		ft_putstr("Increase the size of the terminal window, please");
		exit(0);
	}
	// win->arena = newwin(MAINWIN_LINES, MAINWIN_COLS, 0, 0);
	// box(win->arena, 0, 0);
	// win->runing_info = newwin(RUNNING_INFO_WIN_LINES, RUNNING_INFO_WIN_COLS, 0, MAINWIN_COLS);
	// box(win->runing_info, 0, 0); // delete
	// win->user_info = newwin(INFO_WIN_LINES, INFO_WIN_COLS, MAINWIN_LINES, 0);
	// box(win->user_info, 0, 0); // delete
	// refresh();
	// wrefresh(win->arena);
	// wrefresh(win->runing_info);
	// wrefresh(win->user_info);
	return (win);
}

void					delete_windows(t_windows **win)
{
	delwin((*win)->arena);
	delwin((*win)->runing_info);
	delwin((*win)->user_info);
	free(*win);
	*win = NULL;
	endwin();
}
