/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_push_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:44:53 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short			ft_deq_push_r(t_desdlist **deq, void *content, size_t cs)
{
	t_dlist		*new;

	if (!*deq)
		return (0);
	if (!(new = ft_dlstnew(content, cs)))
		return (0);
	if ((*deq)->end == NULL)
	{
		(*deq)->start = new;
		(*deq)->end = (*deq)->start;
		return (1);
	}
	ft_dlstadd_left(&(*deq)->end, new);
	return (1);
}
