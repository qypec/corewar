/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:53:39 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/25 19:30:25 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			handle_buttons(void)
{
	char			key;
	
	if ((key = getch()) != ERR)
	{
		delete_visu(&(vm.visu));
		exit(1);
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

static void         draw_arena(void)
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
				wcolor_set(vm.visu->win_arena, vm.arena_id[i * 64 + j] + 10, NULL);
           	else
				wcolor_set(vm.visu->win_arena, vm.arena_id[i * 64 + j] + 5, NULL);
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

void                draw(void)
{   
    draw_arena();
	handle_buttons();
}
