/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcmp_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:56:25 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstcmp_cs(t_list *l, t_list *r, size_t end)
{
	t_list	*lt;
	t_list	*rt;

	lt = l;
	rt = r;
	while (lt->next && rt->next)
	{
		if (lt->content_size != rt->content_size)
			break ;
		lt = lt->next;
		rt = rt->next;
	}
	if (!lt || !rt)
		return (0);
	if (lt->content_size == end && rt->content_size == end)
		return (1);
	return (0);
}
