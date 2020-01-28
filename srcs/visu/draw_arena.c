/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:26:05 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/28 09:29:56 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	size_t			i;
	size_t			j;
	t_process		*carry;

	carry = vm.processes;
	i = 0;
	while (i < 64)
	{
		j = 0;
		wmove(vm.visu->win_arena, i + 2, 5);
		while (j < 64)
		{
			if (one_of_carriages_pos(carry, i * 64 + j))
				wcolor_set(vm.visu->win_arena, vm.players[vm.arena_id[i * 64 + j]].color + 5, NULL);
           	else
				wcolor_set(vm.visu->win_arena, vm.players[vm.arena_id[i * 64 + j]].color, NULL);
			wprintw(vm.visu->win_arena, "%.2x", vm.arena[i * 64 + j]);
            wcolor_set(vm.visu->win_arena, 0, NULL);
			waddch(vm.visu->win_arena, ' ');
			j++;
		}
		wprintw(vm.visu->win_arena, "\n");
		i++;
	}
    box(vm.visu->win_arena, 0, 0);
    wrefresh(vm.visu->win_arena);
}
