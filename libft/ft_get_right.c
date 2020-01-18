/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:42:16 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist				*ft_get_right(t_dlist **dlst)
{
	t_dlist			*temp;

	if (!*dlst)
		return (NULL);
	if ((*dlst)->prev)
		(*dlst)->prev->next = NULL;
	temp = *dlst;
	*dlst = (*dlst)->prev;
	temp->prev = NULL;
	return (temp);
}
