/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_add_left_prior.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:47:11 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_left_prior(t_dlist **left, t_dlist **right, t_dlist *new)
{
	t_dlist	*tmp;

	if (!new)
		return ;
	tmp = *left;
	while (tmp && tmp->pr > new->pr)
		tmp = tmp->next;
	if (tmp == *left)
		ft_dlstadd_left(left, new);
	else if (tmp == NULL)
		ft_dlstadd_right(right, new);
	else
	{
		new->next = tmp;
		new->prev = tmp->prev;
		tmp->prev->next = new;
		tmp->prev = new;
	}
}
