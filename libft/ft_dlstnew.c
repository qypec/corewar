/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:41:13 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist				*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist			*new;

	if (!(new = (t_dlist*)malloc(sizeof(t_dlist))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->pr = 0;
	if (content && content_size > 0)
	{
		if (!(new->content = malloc(content_size)))
		{
			ft_memdel((void*)&new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = content_size;
	}
	return (new);
}
