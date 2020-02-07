/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:32:28 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/29 19:33:33 by yquaro           ###   ########.fr       */
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
	wrefresh(visu->win_info);
}

void					init_win_help(t_visu *visu)
{
	visu->win_help = newwin(WIN_HELP_LINES, WIN_HELP_COLS, WIN_ARENA_LINES, 0);
	draw_help(visu);
	wrefresh(visu->win_help);
}
