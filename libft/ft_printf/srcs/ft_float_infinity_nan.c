/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_infinity_nan.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:32:59 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

unsigned char	*check_null(unsigned char *s, unsigned char *res)
{
	if (!ft_strchr((const char*)s, '1'))
	{
		free(res);
		res = (unsigned char*)ft_strnew(3);
		res[0] = '0';
		res[1] = '.';
		res[2] = '0';
	}
	return (res);
}

unsigned char	*create_infinity_nan(unsigned char *res, t_printf *pr)
{
	if (GET_BIT(pr->flags, INF) || GET_BIT(pr->flags, NAN))
	{
		free(res);
		res = (unsigned char*)ft_strnew(3);
		res[0] = GET_BIT(pr->flags, INF) ? 'i' : 'n';
		res[1] = GET_BIT(pr->flags, INF) ? 'n' : 'a';
		res[2] = GET_BIT(pr->flags, INF) ? 'f' : 'n';
		(pr->type == 'e') ? (pr->type = 'f') : 0;
		(pr->type == 'E') ? (pr->type = 'F') : 0;
	}
	if ((pr->type == 'F') && (GET_BIT(pr->flags, INF)
	|| GET_BIT(pr->flags, NAN)))
	{
		pr->capitalize = 1;
		ft_capitalize(pr, (char*)res);
	}
	return (res);
}

unsigned char	*check_infinity_nan(unsigned const char *s,
		t_printf *pr, unsigned char *res)
{
	int i;

	i = 1;
	while (s[i] == '1' && i <= 12)
	{
		if (i == 11)
		{
			CLEAR_BIT(pr->flags, ZERO);
			SET_BIT(pr->flags, INF);
		}
		if (i == 12)
		{
			CLEAR_BIT(pr->flags, INF);
			CLEAR_BIT(pr->flags, ZERO);
			CLEAR_BIT(pr->flags, PLUS);
			SET_BIT(pr->flags, NAN);
		}
		i++;
	}
	res = create_infinity_nan(res, pr);
	return (res);
}
