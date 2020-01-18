/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_bif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:55:23 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp_bif(const char *s1, const char *s2, char symb, int n)
{
	size_t	i;
	size_t	j;
	int		diff;

	i = 0;
	while (s1[i] && s2[i] && s1[i] != symb && s2[i] != symb)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	j = i;
	while (s1[i] && s1[i] != symb)
		++i;
	while (s2[j] && s2[j] != symb)
		++j;
	--n;
	if (n == 0 || !s1[i] || !s2[j])
		return (diff);
	else if (n == 1)
		return (diff && ft_strcmp_bif(s1 + i + 1, s2 + j + 1, 0, n));
	return (diff && ft_strcmp_bif(s1 + i + 1, s2 + j + 1, symb, n));
}
