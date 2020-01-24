/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:53:39 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/24 13:04:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void         draw_arena(void)
{
	int				i;
	int				j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		wmove(vm.visu->win_arena, i + 2, 5);
		while (j < 64)
		{
            // wcolor_set(vm.visu->win_arena, vm.players[vm.arena_id[i * 64 + j]].color, NULL);
			wprintw(vm.visu->win_arena, "%.2x", vm.arena[i * 64 + j]);
            // wcolor_set(vm.visu->win_info, 0, NULL);
			waddch(vm.visu->win_arena, ' ');
			j++;
		}
		wprintw(vm.visu->win_arena, "\n");
		i++;
	}
    box(vm.visu->win_arena, 0, 0);
    wrefresh(vm.visu->win_arena);
}

void                draw(void)
{   
    draw_arena();
    getch();
}
