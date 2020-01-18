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

unsigned char	*plus_2_pow(unsigned char *mantissa, int pow)
{
	int				i;
	unsigned char	*copy;

	i = -1;
	while (++i < pow)
	{
		copy = (unsigned char*)ft_strdup((char*)mantissa);
		mantissa = summator(mantissa, copy);
		free(copy);
	}
	return (mantissa);
}

unsigned char	*obrezanie(unsigned char *s)
{
	int				len;
	int				comp_len;
	unsigned char	*res;

	len = ft_strlen((char*)s);
	comp_len = len;
	while (s[len - 1] == '0' && s[len - 2] != '.')
		--len;
	if (comp_len != len)
	{
		res = (unsigned char*)ft_strnew(len);
		res = (unsigned char*)ft_strncpy((char*)res, (char*)s, len);
		free(s);
		return (res);
	}
	return (s);
}

unsigned char	*bits(unsigned char static_res[80], t_printf *pr)
{
	int				i;
	unsigned char	*mantissa;
	unsigned char	*res;

	mantissa = receive_d_value(static_res, pr);
	i = receive_e(static_res, pr);
	if (i <= 0)
		res = minus_2_pow(mantissa, i * -1);
	else
		res = plus_2_pow(mantissa, i);
	if (static_res[0] == '1')
		SET_BIT(pr->flags, MINUS_FLOAT);
	res = obrezanie(res);
	res = check_infinity_nan(static_res, pr, res);
	res = check_null(static_res, res);
	return (res);
}

unsigned char	*receive_bin(t_printf *pr, unsigned char const *s)
{
	int				i;
	unsigned int	k;
	int				max;
	int				j;
	unsigned char	static_res[80];

	j = 0;
	i = 0;
	max = (pr->specif == 10) ? 10 : 8;
	while (i < max)
	{
		k = 7;
		while (j < (8 * (i + 1)))
		{
			static_res[j] = (s[(max - 1) - i] & (1u << k)) ? '1' : '0';
			--k;
			++j;
		}
		++i;
	}
	static_res[j] = '\0';
	return (bits(static_res, pr));
}

/*
** 	printf("RES = %s\n", static_res);
*/
