/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:20:53 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/25 16:59:21 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void                    init_pairs(void)
{
    init_color(COLOR_GRAY, 355, 355, 355);
	init_pair(GRAY, COLOR_GRAY, 0);
	init_pair(GREEN, COLOR_GREEN, 0);
	init_pair(YELLOW, COLOR_YELLOW, 0);
	init_pair(RED, COLOR_RED, 0);
	init_pair(CYAN, COLOR_CYAN, 0);
	init_pair(GRAY_CARRY, COLOR_BLACK, COLOR_GRAY);
	init_pair(GREEN_CARRY, COLOR_BLACK, COLOR_GREEN);
	init_pair(YELLOW_CARRY, COLOR_BLACK, COLOR_YELLOW);
	init_pair(RED_CARRY, COLOR_BLACK, COLOR_RED);
	init_pair(CYAN_CARRY, COLOR_BLACK, COLOR_CYAN);
}

void					init_colors(void)
{
	if (!has_colors())
	{
		delete_visu(&(vm.visu));
		ft_putendl("Your terminal does not support color");
		exit(1);
	}
	start_color();
	init_pairs();
}