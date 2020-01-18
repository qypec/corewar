/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:03:43 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		str_or_not(char const *s, char c)
{
	if (*s != c)
		return (1);
	else
		return (0);
}

static	int		str_symbols(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

static	int		str_counter(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s != c && *s != '\0')
		{
			count++;
		}
		while (*s != c && *s != '\0')
			s++;
		if (*s == c)
			s++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	int		i;
	int		j;
	int		quan;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	quan = str_counter(s, c);
	if (!(dst = (char**)malloc(sizeof(char*) * (quan + 1))))
		return (NULL);
	while (j < quan)
	{
		while (!(str_or_not(&s[i], c)))
			i++;
		if (!(dst[j] = ft_strsub(s, i, str_symbols(&s[i], c))))
			return (free_d_char_rarr(dst, j));
		i = i + str_symbols(&s[i], c);
		j++;
	}
	dst[quan] = NULL;
	return (dst);
}
