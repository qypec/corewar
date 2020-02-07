/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:26:05 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/29 19:59:40 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define START_POSITION (WIN_ARENA_COLS - 31)
#define SPEED "SPEED "
#define SPEED_POINT_ACTIVE (' ' | A_STANDOUT | COLOR_PAIR(CYAN))
#define SPEED_POINT ('_' | COLOR_PAIR(CYAN))

#define GET_COLOR_CARRY(v, i, j) (v.players[v.arena_id[i * 64 + j]].color + 5)
#define GET_COLOR(v, i, j) (v.players[v.arena_id[i * 64 + j]].color)

void				draw_speed_bar(void)
{
	size_t			i;

	wcolor_set(vm.visu->win_arena, CYAN, NULL);
	mvwprintw(vm.visu->win_arena, 1, START_POSITION, SPEED);
	wcolor_set(vm.visu->win_arena, 0, NULL);
	i = 0;
	while (i < vm.visu->speed * 2)
	{
		wmove(vm.visu->win_arena, 1, START_POSITION + ft_strlen(SPEED) + i);
		waddch(vm.visu->win_arena, SPEED_POINT_ACTIVE);
		waddch(vm.visu->win_arena, SPEED_POINT_ACTIVE);
		i += 2;
	}
	while (i < MAX_SPEED_POINT * 2)
	{
		wmove(vm.visu->win_arena, 1, START_POSITION + ft_strlen(SPEED) + i);
		waddch(vm.visu->win_arena, SPEED_POINT);
		waddch(vm.visu->win_arena, SPEED_POINT);
		i += 2;
	}
}

static int			one_of_carriages_pos(t_process *carry, size_t pos)
{
	while (carry != NULL)
	{
		if (pos == carry->pos)
			return (1);
		carry = carry->next;
	}
	return (0);
}

void				draw_arena(void)
{
	int				i;
	int				j;
	t_process		*carry;

	carry = vm.processes;
	i = -1;
	while (++i < 64)
	{
		j = -1;
		wmove(vm.visu->win_arena, i + 2, 5);
		while (++j < 64)
		{
			if (one_of_carriages_pos(carry, i * 64 + j))
				wcolor_set(vm.visu->win_arena, GET_COLOR_CARRY(vm, i, j), NULL);
			else
				wcolor_set(vm.visu->win_arena, GET_COLOR(vm, i, j), NULL);
			wprintw(vm.visu->win_arena, "%.2x", vm.arena[i * 64 + j]);
			wcolor_set(vm.visu->win_arena, 0, NULL);
			waddch(vm.visu->win_arena, ' ');
		}
		wprintw(vm.visu->win_arena, "\n");
	}
	draw_speed_bar();
	box(vm.visu->win_arena, 0, 0);
	wrefresh(vm.visu->win_arena);
}
