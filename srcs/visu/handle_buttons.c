/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_buttons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 09:29:21 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/28 13:27:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			handle_buttons(void)
{
	char			key;

	while (1)
	{
		if ((key = getch()) == SPACE_BUTTON)
		{
			if (vm.visu->is_stopped)
			{
				draw_game_status(IS_RUNNING);
				nodelay(stdscr, TRUE);
			}
			else
			{
				draw_game_status(IS_PAUSED);
				nodelay(stdscr, FALSE);
			}
			vm.visu->is_stopped *= (-1);
			break ;
		}
	}
}