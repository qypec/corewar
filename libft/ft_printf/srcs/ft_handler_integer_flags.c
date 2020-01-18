/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_integer_flags.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:43:46 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

char	*null_handle(t_printf *pr, char *str)
{
	if (pr->precision == 0)
	{
		if (DECIMAL || POINTER || HEX || (OCT && !(pr->flags & HASH)))
		{
			if (POINTER && pr->precision == 0)
				ft_memset((void*)str, '\0', 1);
			if (!POINTER)
				ft_memset((void*)str, '\0', 1);
		}
	}
	return (str);
}

char	*ft_handler_precision(t_printf *pr, char *str)
{
	int		prec;
	char	*nulls;

	if (pr->precision > pr->numlen)
	{
		pr->precision -= ((pr->flags & HASH && OCT && !g_isnull)) ? 1 : 0;
		prec = pr->precision - pr->numlen;
		nulls = ft_strnew(prec);
		ft_memset((void*)nulls, '0', (size_t)prec);
		str = ft_strjoin_free(nulls, str);
	}
	return (str);
}

char	*ft_handler_zerowidth(t_printf *pr, char *str)
{
	int		width;
	char	*nulls;

	if (pr->width > pr->numlen && pr->precision == -1)
	{
		if ((pr->flags & HASH && OCTHEX && !g_isnull)
		|| (POINTER))
			pr->width -= (OCT) ? 1 : 2;
		width = pr->width;
		width -= ((pr->flags & PLUS || pr->flags & SPACE)
			&& !(POINTER || OCTHEX)) ? 1 : 0;
		width -= pr->numlen;
		if (width > 0)
		{
			nulls = ft_strnew(width);
			ft_memset((void*)nulls, '0', (size_t)width);
			str = ft_strjoin_free(nulls, str);
		}
	}
	return (str);
}

char	*ft_handler_plus_space(t_printf *pr, char *str)
{
	char sign[2];

	sign[0] = (!pr->isnegative) ? '+' : '-';
	sign[1] = '\0';
	if (pr->flags & PLUS)
		str = ft_strrejoin_right(sign, str);
	if (pr->flags & SPACE)
		str = ft_strrejoin_right((char*)" ", str);
	return (str);
}

char	*ft_handler_hash(t_printf *pr, char *str)
{
	int len;

	len = ft_strlen(str);
	if (POINTER || (HEX && len))
		str = ft_strrejoin_right((char*)"0x", str);
	if (OCT && len)
		str = ft_strrejoin_right((char*)"0", str);
	return (str);
}
