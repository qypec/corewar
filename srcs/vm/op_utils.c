/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:47:21 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/23 18:49:44 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int get_int32_from_mem(int position)
{
	unsigned char buf[4];

	buf[3] = *(vm.arena + position);
	buf[2] = *(vm.arena + position + 1);
	buf[1] = *(vm.arena + position + 2);
	buf[0] = *(vm.arena + position + 3);
	return (*((int*)buf));
}

int get_int16_from_mem(int position)
{
	unsigned char buf[2];

	buf[1] = *(vm.arena + position);
	buf[0] = *(vm.arena + position + 1);
	return (*((int16_t*)buf));
}