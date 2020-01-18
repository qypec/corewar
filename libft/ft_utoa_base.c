/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 22:14:23 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char			receive_value_u(unsigned long num)
{
	char				res;
	char				digits[16];

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

unsigned long long		ft_len_div_u(unsigned long long value,
		unsigned int base, int flag)
{
	unsigned long long	div;
	unsigned long		count;

	div = 1;
	count = 1;
	while (value / base >= div)
	{
		div *= base;
		++count;
	}
	if (flag == 1)
		return (count);
	else if (flag == 2)
		return (div);
	return (-1);
}

char					*ft_utoa_base(unsigned long long value,
		unsigned int base)
{
	unsigned long		i;
	unsigned long long	div;
	unsigned long		len;
	char				*str;

	i = 0;
	len = ft_len_div_u(value, base, 1);
	str = (char*)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	div = ft_len_div_u(value, base, 2);
	while (i < len)
	{
		str[i++] = receive_value_u(value / div);
		value = value % div;
		div = div / base;
	}
	return (str);
}
