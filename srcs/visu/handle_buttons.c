/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_buttons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:29:21 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/29 13:40:49 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		speed_up(void)
{
	if (vm.visu->delay != 0.0 && vm.visu->speed != MAX_SPEED_POINT)
	{
		vm.visu->speed++;
		vm.visu->delay -= 0.1;
	}
}

static void		speed_down(void)
{
	if (vm.visu->delay != 1.0 && vm.visu->speed != 1)
	{
		vm.visu->speed--;
		vm.visu->delay += 0.1;
	}
}

void			handle_buttons(void)
{
	int			key;

	if ((key = getch()) == SPACE_BUTTON)
	{
		nodelay(stdscr, NODELAY_MACROS);
		vm.visu->is_stopped *= (-1);
		draw_game_status(vm.visu->is_stopped);
	}
	else if (key == ESC_BUTTON)
	{
		delete_visu(&(vm.visu));
		exit(1);
	}
	else if (key == KEY_DOWN)
		speed_down();
	else if (key == KEY_UP)
		speed_up();
	usleep(vm.visu->delay * MAX_DELAY);
}