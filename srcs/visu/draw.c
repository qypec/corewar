/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:53:39 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/29 18:03:14 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

# define NUMOF_LINES_FOR_PLAYER 4
# define WINNER "WINNER!"

static void			pause_before_termination(void)
{
	nodelay(stdscr, FALSE);
	getch();
}

void				draw_winner(int flag, size_t line)
{
	static size_t	start_line;

	if (flag == _GIVE_NUMOF_LIVE_)
	{
		start_line = line;
		return ;
	}
	vm.visu->win_winner = newwin(NUMOF_LINES_FOR_PLAYER + 3, \
		WIN_INFO_COLS, start_line - 1, WIN_ARENA_COLS);
	start_line = 1;
	draw_player(vm.visu->win_winner, &start_line, vm.last_alive->id);
	wattron(vm.visu->win_winner, A_BLINK | A_BOLD);
	wcolor_set(vm.visu->win_winner, CYAN, NULL);
	mvwprintw(vm.visu->win_winner, 1, (WIN_INFO_COLS - ft_strlen(WINNER)) / 2, WINNER);
	box(vm.visu->win_winner, 0, 0);
	wcolor_set(vm.visu->win_winner, 0, NULL);
	wattroff(vm.visu->win_winner, A_BLINK | A_BOLD);
	wrefresh(vm.visu->win_winner);
	pause_before_termination();
}

void                draw(void)
{   
    draw_arena();
	draw_info();
	handle_buttons();
}
