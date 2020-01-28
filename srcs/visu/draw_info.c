/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 08:47:52 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/28 13:31:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void				draw_game_status(int flag)
{
	if (flag == IS_PAUSED)
	{
		wcolor_set(vm.visu->win_info, RED, NULL);
		mvwprintw(vm.visu->win_info, 1, 5, STOPPED);
		wcolor_set(vm.visu->win_info, 0, NULL);
	}
	else if (flag == IS_RUNNING)
	{
		wcolor_set(vm.visu->win_info, GREEN, NULL);
		mvwprintw(vm.visu->win_info, 1, 5, RUNNING);
		wcolor_set(vm.visu->win_info, 0, NULL);
	}
    wrefresh(vm.visu->win_info);
}

static void			draw_players(size_t line)
{
	size_t			i;

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
		mvwprintw(vm.visu->win_info, line++, 7, "last live: %zu ", vm.players[i].lives_last);
		mvwprintw(vm.visu->win_info, line++, 7, "current live: %zu ", vm.players[i].lives_current);
		i++;
	}
}

void				draw_info(void)
{
	size_t			line;

    draw_game_status(vm.visu->is_stopped);
	line = 3;
	mvwprintw(vm.visu->win_info, line += 2, 5, "Cycles : %zu", vm.cycles_all);
	mvwprintw(vm.visu->win_info, line += 2, 5, "Cycle to die : %zu", vm.cycles_to_die);
	mvwprintw(vm.visu->win_info, line += 2, 5, "Checks : %zu", vm.checks);
	mvwprintw(vm.visu->win_info, line += 2, 5, "Lives in round : %zu", vm.lives_in_round);
	mvwprintw(vm.visu->win_info, line += 2, 5, "Number of cariages : %zu", vm.process_count);
	line += 3;
	draw_players(line);
	wrefresh(vm.visu->win_info);
}
