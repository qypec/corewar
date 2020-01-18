/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_desdlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:40:19 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short		ft_init_desdlist(t_desdlist **deq)
{
	if (!*deq)
		return (0);
	(*deq)->start = NULL;
	(*deq)->end = NULL;
	(*deq)->ptr = NULL;
	(*deq)->mem = 0;
	return (1);
}
