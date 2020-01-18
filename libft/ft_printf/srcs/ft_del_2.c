/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:06:17 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void			over(unsigned char **num, int i)
{
	unsigned char *temp;

	temp = *num;
	if (i > -1)
	{
		if (temp[i] > '9')
		{
			temp[i] -= 10;
			if (temp[i - 1] == '.')
				--i;
			if (i > -1)
				temp[i - 1] += 1;
		}
		over(&temp, i - 1);
	}
}

void			calc_del_handler(unsigned char *num, int len,
		int temp, int flag)
{
	while (len > -1)
	{
		if (num[len] == '.')
		{
			--len;
			continue;
		}
		temp = num[len] - '0';
		num[len] = ((num[len] - '0') / 2) + '0';
		if (num[len + 1] == '.')
		{
			++len;
			flag = 1;
		}
		if (num[len + 1])
			num[len + 1] += ((temp % 2) == 1) ? 5 : 0;
		if (flag == 1)
			--len;
		if (flag == 0 && num[len + 1] > '9')
			over(&num, len + 1);
		if (flag == 1 && num[len + 2] > '9')
			over(&num, len + 2);
		--len;
	}
}

unsigned char	*calc_del(unsigned char *num)
{
	int len;
	int temp;
	int flag;

	flag = 0;
	temp = 0;
	len = ft_strlen((const char*)num) - 1;
	if ((num[len] - '0') % 2 == 1)
	{
		num = (unsigned char *)ft_strrejoin((char *)num, "5");
		num[len] = ((num[len] - '0') / 2) + '0';
		--len;
	}
	calc_del_handler(num, len, temp, flag);
	return (num);
}

unsigned char	*minus_2_pow(unsigned char *s, int pow)
{
	int i;

	i = -1;
	while (++i < pow)
		s = calc_del(s);
	return (s);
}
