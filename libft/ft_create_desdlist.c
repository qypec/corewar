/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_desdlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:51:38 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_desdlist		*ft_create_desdlist(void)
{
	t_desdlist	*new;

	if (!(new = (t_desdlist*)malloc(sizeof(t_desdlist))))
		return (NULL);
	new->start = NULL;
	new->end = NULL;
	new->ptr = NULL;
	new->mem = 1;
	return (new);
}
