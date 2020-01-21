/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:28:50 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/21 18:34:38 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	print_bits(unsigned char octet)
{
	int		i;
	char	temp;

	i = 64;
	while (--i >= 0)
	{
		temp = ((octet & (1 << i)) ? '1' : '0');
		write(1, &temp, 1);
	}
	write(1, "\n", 1);
}

void	ft_capitalize(t_printf *pr, char *str)
{
	int i;

	i = -1;
	if (pr->capitalize)
	{
		while (str[++i])
		{
			if (ft_isalpha((int)str[i]))
				str[i] -= 32;
		}
	}
}

void	ft_float(t_printf *pr)
{
	unsigned char	*res;
	double			d;
	long double		ld;

	d = 0;
	ld = 0;
	if (pr->specif == 10)
	{
		ld = va_arg(pr->ap, long double);
		res = receive_bin(pr, (unsigned char*)&ld);
	}
	else
	{
		d = va_arg(pr->ap, double);
		res = receive_bin(pr, (unsigned char*)&d);
	}
	(pr->type == 'e' || pr->type == 'E') ? ft_flag_e(&res, pr) : 0;
	print_float(res, pr);
}
