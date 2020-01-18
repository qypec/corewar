/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:50:14 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deq_del(t_desdlist **deq)
{
	ft_dlstdel(&(*deq)->start, ft_content_del);
	(*deq)->start = NULL;
	(*deq)->end = NULL;
	(*deq)->ptr = NULL;
	if ((*deq)->mem)
		ft_memdel((void*)deq);
	(*deq) = NULL;
}
