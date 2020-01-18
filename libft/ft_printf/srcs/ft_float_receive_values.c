/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_receive_values.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:28:25 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

unsigned char	*make_res(int flag)
{
	unsigned char *res;

	res = (unsigned char*)ft_strnew(3);
	if (flag == 80)
	{
		res[0] = '0';
		res[1] = '.';
		res[2] = '0';
	}
	else
	{
		res[0] = '1';
		res[1] = '.';
		res[2] = '0';
	}
	return (res);
}

unsigned char	*receive_d_value(unsigned char static_res[80], t_printf *pr)
{
	int				i;
	int				k;
	unsigned char	*res;
	unsigned char	*temp;

	i = (pr->specif == 10) ? 15 : 11;
	k = i;
	(k == 15) ? ++k : k;
	pr->specif = (pr->specif == 10) ? 80 : 64;
	res = make_res(pr->specif);
	while (++i < pr->specif)
	{
		if (static_res[i] == '1')
		{
			temp = minus_2_pow(make_res(0), i - k);
			res = summator(res, temp);
			free(temp);
		}
	}
	return (res);
}

/*
** printf("mantissa = %s\n", res);
*/

int				receive_e(unsigned char static_res[80], t_printf *pr)
{
	int		i;
	int		max;
	short	res;

	i = 0;
	res = 0;
	max = (pr->specif == 80) ? 15 : 11;
	while (++i <= max)
	{
		if (static_res[i] == '1')
			res |= (1 << (max - i));
	}
	res -= (pr->specif == 64) ? 1023 : 16383;
	return (res);
}

/*
** printf("e = %d\n", res);
**
**	ft_putstr("e before\n");
**	print_bits(res);
**
**	ft_putstr("e after\n");
**	print_bits(res);
*/
