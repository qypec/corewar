/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:43:46 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlstdel(t_dlist **dlst, void (*del)(void *, size_t))
{
	t_dlist		*next;
	t_dlist		*prev;
	t_dlist		*cur;

	if (!*dlst)
		return ;
	cur = *dlst;
	prev = cur->prev;
	while (cur)
	{
		next = cur->next;
		ft_dlstdelone(&cur, del);
		cur = next;
	}
	cur = prev;
	while (cur)
	{
		prev = cur->next;
		ft_dlstdelone(&cur, del);
		cur = prev;
	}
	*dlst = NULL;
}
