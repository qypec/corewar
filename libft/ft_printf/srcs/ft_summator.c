/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   summator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:25:29 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

t_limit			find_limit(unsigned char *s1, unsigned char *s2)
{
	t_limit	limit;
	int		l_ind;

	l_ind = ft_strlen((char*)s2) - 1;
	limit.min_s1 = ind_before_len(s1) - ind_before_len(s2);
	limit.k = limit.min_s1;
	limit.max_s1 = limit.min_s1 + l_ind;
	return (limit);
}

char			*str_zero(int len)
{
	char	*res;

	res = ft_strnew(len);
	ft_memset(res, '0', len);
	return (res);
}

unsigned char	*sum(unsigned char *s1, unsigned char *s2)
{
	t_limit	limit;

	limit = find_limit(s1, s2);
	while (limit.max_s1 >= limit.min_s1)
	{
		if (s1[limit.max_s1] == '.')
		{
			--limit.max_s1;
			continue;
		}
		s1[limit.max_s1] += (s2[limit.max_s1 - limit.k] - '0');
		if (s1[limit.max_s1] > '9' && limit.max_s1 != limit.min_s1)
			over_plus(&s1, limit.max_s1, 0);
		--limit.max_s1;
	}
	if (s1[limit.min_s1] > '9')
	{
		s1 = (unsigned char*)ft_strjoin_free(str_zero(1), (char*)s1);
		over_plus(&s1, 1, -1);
	}
	return (s1);
}

unsigned char	*summator(unsigned char *s1, unsigned char *s2)
{
	int ind1;
	int ind2;

	ind1 = ind_after_len(s1);
	ind2 = ind_after_len(s2);
	if (ind1 < ind2)
		s1 = (unsigned char*)ft_strjoin_free((char*)s1, str_zero(ind2 - ind1));
	ind1 = ind_before_len(s1);
	ind2 = ind_before_len(s2);
	if (ind1 < ind2)
		s1 = (unsigned char*)ft_strjoin_free(str_zero(ind2 - ind1), (char*)s1);
	return (sum(s1, s2));
}
