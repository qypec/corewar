/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 10:53:39 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/25 21:26:52 by yquaro           ###   ########.fr       */
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

static void			draw_info(void)
{
	size_t			i;
	size_t			line;

	line = 3;
	mvwprintw(vm.visu->win_info, line += 2, 5, "Cycles : %zu", vm.cycles_all);
	mvwprintw(vm.visu->win_info, line += 2, 5, "Cycle to die : %zu", vm.cycles_to_die);
	mvwprintw(vm.visu->win_info, line += 2, 5, "Checks : %zu", vm.checks);
	mvwprintw(vm.visu->win_info, line += 2, 5, "Lives in round : %zu", vm.lives_in_round);
	mvwprintw(vm.visu->win_info, line += 2, 5, "Number of cariages : %zu", vm.process_count);
	line += 3;
	i = 1;
	while (i <= vm.players_sum)
	{
		mvwprintw(vm.visu->win_info, ++line, 5, "Player %d : ", i);
		if (vm.players[i].is_alive)
		{
			wcolor_set(vm.visu->win_info, vm.players[i].color, NULL);
			mvwprintw(vm.visu->win_info, line++, 5 + ft_strlen("Player %d : "), "%s        ", vm.players[i].name);
		}
		else
		{
			wcolor_set(vm.visu->win_info, GRAY, NULL);
			mvwprintw(vm.visu->win_info, line++, 5 + ft_strlen("Player %d : "), "%s is DEAD", vm.players[i].name);
		}
		wcolor_set(vm.visu->win_info, 0, NULL);
		mvwprintw(vm.visu->win_info, line++, 7, "slogan: %s ", vm.players[i].comment);
		i++;
	}
	wrefresh(vm.visu->win_info);
}

void                draw(void)
{   
    draw_arena();
	draw_info();
	handle_buttons();
}
