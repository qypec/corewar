/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 08:47:52 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/29 16:57:04 by yquaro           ###   ########.fr       */
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

void				draw_player(WINDOW *win, size_t *line, size_t players_counter)
{
	mvwprintw(win, ++(*line), 5, "Player %d : ", players_counter);
	if (vm.players[players_counter].is_alive)
	{
		wcolor_set(win, vm.players[players_counter].color, NULL);
		mvwprintw(win, (*line)++, 5 + ft_strlen("Player %d : "), "%s        ", vm.players[players_counter].name);
	}
	else
	{
		wcolor_set(win, GRAY, NULL);
		mvwprintw(win, (*line)++, 5 + ft_strlen("Player %d : "), "%s is DEAD", vm.players[players_counter].name);
	}
	wcolor_set(win, 0, NULL);
	mvwprintw(win, (*line)++, 7, "slogan: %s ", vm.players[players_counter].comment);
	mvwprintw(win, (*line)++, 7, "last live: %zu ", vm.players[players_counter].lives_last);
	mvwprintw(win, (*line)++, 7, "current live: %zu ", vm.players[players_counter].lives_current);
}

void				draw_info(void)
{
	size_t			line;
	size_t			i;

    draw_game_status(vm.visu->is_stopped);
	line = 3;
	mvwprintw(vm.visu->win_info, line += 2, 5, "Cycles : %zu", vm.cycles_all);
	mvwprintw(vm.visu->win_info, line += 2, 5, "Cycle to die : %zu", vm.cycles_to_die);
	mvwprintw(vm.visu->win_info, line += 2, 5, "Checks : %zu", vm.checks);
	mvwprintw(vm.visu->win_info, line += 2, 5, "Lives in round : %zu", vm.lives_in_round);
	mvwprintw(vm.visu->win_info, line += 2, 5, "Number of cariages : %zu", vm.process_count);
	line += 3;
	draw_winner(_GIVE_NUMOF_LIVE_, line);
	i = 0;
	while (++i <= vm.players_sum)
	{
		draw_player(vm.visu->win_info, &line, i);
		line++;
	}
	wrefresh(vm.visu->win_info);
}
