/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_rounding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:38:45 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int				check_even(unsigned char *str, int last)
{
	int flag;

	flag = 0;
	if (!str[last + 1] && !str[last + 2])
		flag = 1;
	else if (str[last + 1] && str[last + 2]
	&& str[last + 1] == '0' && str[last + 2] == '0')
		flag = 1;
	else if (str[last + 1] && !str[last + 2] && str[last + 1] == '0')
		flag = 1;
	return (flag);
}

unsigned char	*make_round(unsigned char *str, int last)
{
	str[last] = '\0';
	(str[--last] == '.') ? --last : last;
	str[last]++;
	over_plus(&str, last, -1);
	return (str);
}

unsigned char	*round_float(t_printf *pr, unsigned char *str)
{
	int last;

	last = ind_before_len(str) + pr->precision + 1;
	if (str[last] == '5' && str[last - 1] != '.'
	&& ((str[last - 1] - '0') % 2 == 0))
	{
		if (check_even(str, last))
			str[last] = '\0';
		else
			str = make_round(str, last);
	}
	else if (str[last] >= '5')
		str = make_round(str, last);
	else
		str[last] = '\0';
	if (pr->precision == 0 && !(GET_BIT(pr->flags, HASH)))
		str[ind_before_len(str)] = '\0';
	return (str);
}
