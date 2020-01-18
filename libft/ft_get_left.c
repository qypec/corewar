/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:43:30 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist				*ft_get_left(t_dlist **dlst)
{
	t_dlist			*temp;

	if (!*dlst)
		return (NULL);
	if ((*dlst)->next)
		(*dlst)->next->prev = NULL;
	temp = *dlst;
	*dlst = (*dlst)->next;
	temp->next = NULL;
	return (temp);
}
