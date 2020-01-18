/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 22:02:40 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			receive_value_ll(long long num)
{
	char		res;
	char		digits[16];

	digits[0] = '0';
	digits[1] = '1';
	digits[2] = '2';
	digits[3] = '3';
	digits[4] = '4';
	digits[5] = '5';
	digits[6] = '6';
	digits[7] = '7';
	digits[8] = '8';
	digits[9] = '9';
	digits[10] = 'a';
	digits[11] = 'b';
	digits[12] = 'c';
	digits[13] = 'd';
	digits[14] = 'e';
	digits[15] = 'f';
	res = digits[num];
	return (res);
}

long long		ft_len_del_ll(long long value, int base, int flag)
{
	long long	del;
	long long	count;

	del = 1;
	count = 1;
	while (value / base >= del)
	{
		del *= base;
		++count;
	}
	if (flag == 1)
		return (count);
	else if (flag == 2)
		return (del);
	return (-1);
}

char			*ft_lltoa_base(long long value, int base)
{
	long long	i;
	long long	sign;
	long long	len;
	char		*str;

	i = 0;
	sign = 0;
	len = 0;
	if (value < 0)
	{
		sign = 1;
		++len;
		value *= -1;
	}
	len += ft_len_del_ll(value, base, 1);
	str = ft_strnew(len);
	(sign == 1) ? str[i++] = '-' : 0;
	sign = ft_len_del_ll(value, base, 2);
	while (i < len)
	{
		str[i++] = receive_value_ll(value / sign);
		value = value % sign;
		sign = sign / base;
	}
	return (str);
}
