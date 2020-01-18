/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:10:18 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*sour;
	size_t	i;

	i = -1;
	dest = (char*)dst;
	sour = (char*)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	if (len == 0)
		return (dst);
	if (dst < src)
	{
		while (++i < len)
			dest[i] = sour[i];
	}
	if (dst > src)
	{
		i = len;
		while ((int)--i >= 0)
			dest[i] = sour[i];
	}
	return (dst);
}
