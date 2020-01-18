/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_turn_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:53:05 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_cross_to_cross(const char *s1,
		const char *s2, char symb, t_point sec)
{
	int		diff;
	int		i;

	i = 0;
	while (s1[i + 1] && s1[i + 1] != symb
	&& s2[sec.y + 1] && s2[sec.y + 1] != symb)
	{
		if (s1[i] != s2[sec.y])
			break ;
		++i;
		++sec.y;
	}
	diff = (unsigned char)s1[i] - (unsigned char)s2[sec.y];
	i = 0;
	while (s2[i + 1] && s2[i + 1] != symb
	&& s1[sec.x + 1] && s1[sec.x + 1] != symb)
	{
		if (s2[i] != s1[sec.x])
			break ;
		++i;
		++sec.y;
	}
	return (diff || ((unsigned char)s1[sec.x] - (unsigned char)s2[i]));
}

int			ft_strcmp_turn_double(const char *s1, const char *s2, char symb)
{
	size_t	i;
	size_t	first;
	size_t	second;
	int		diff;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	if (!diff)
		return (diff);
	first = ft_linear_search(s1, '-') + 1;
	second = ft_linear_search(s2, '-') + 1;
	return (ft_cross_to_cross(s1, s2, symb, (t_point){first, second}));
}
