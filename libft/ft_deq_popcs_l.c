/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_popcs_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:49:33 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_deq_popcs_l(t_desdlist **deq)
{
	int			flag;
	t_dlist		*temp;
	size_t		res;

	flag = ((*deq)->start == (*deq)->end) ? 1 : 0;
	res = (*deq)->start->content_size;
	temp = (*deq)->start->next;
	if (temp)
		temp->prev = NULL;
	ft_dlstdelone(&((*deq)->start), ft_content_del);
	(*deq)->start = temp;
	if (flag == 1)
		(*deq)->end = NULL;
	return (res);
}
