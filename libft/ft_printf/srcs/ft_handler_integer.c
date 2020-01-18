/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 22:33:35 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

char	*negative_handle(t_printf *pr, char *str)
{
	char	*tmp;

	if (pr->isnegative)
	{
		tmp = ft_strsub(str, 1, pr->numlen - 1);
		free(str);
		SET_BIT(pr->flags, PLUS);
		(pr->flags & SPACE) ? CLEAR_BIT(pr->flags, SPACE) : 0;
		pr->numlen--;
		return (tmp);
	}
	return (str);
}

int		max_wlong_check(t_printf *pr, long long num)
{
	if (num < -9223372036854775807)
	{
		ft_putstr("-9223372036854775808");
		pr->count = 20;
		return (0);
	}
	return (1);
}

void	ft_handle_int(t_printf *pr, long long num)
{
	char	*str;

	if (!max_wlong_check(pr, num))
		return ;
	str = ((SIGNED)) ? ft_lltoa_base(num, pr->base)
			: ft_utoa_base((unsigned long long)num, pr->base);
	pr->toprint = ' ';
	pr->numlen = ft_strlen(str);
	g_isnull = (str[0] == '0' && str[1] == '\0') ? 1 : 0;
	if ((pr->isnegative = (str[0] == '-') ? 1 : 0))
		str = negative_handle(pr, str);
	str = (g_isnull) ? null_handle(pr, str) : str;
	str = ft_handler_precision(pr, str);
	str = (pr->flags & ZERO) ? ft_handler_zerowidth(pr, str) : str;
	str = ((pr->flags & PLUS || pr->flags & SPACE) && SIGNED)
			? ft_handler_plus_space(pr, str) : str;
	str = ((pr->flags & HASH && OCTHEX && !g_isnull) || POINTER)
			? ft_handler_hash(pr, str) : str;
	pr->len = ft_strlen(str);
	ft_capitalize(pr, str);
	(!(pr->flags & MINUS)) ? print_width(pr) : 0;
	add_buf_str(pr, (unsigned char*)str);
	(pr->flags & MINUS) ? print_width(pr) : 0;
	free(str);
}

void	ft_hand_int_init(t_printf *pr)
{
	pr->issigned = (SIGNED) ? 1 : 0;
	pr->specif = (pr->type == 'p') ? 3 : pr->specif;
	if (pr->type == 'U')
	{
		pr->specif = 3;
		pr->type = 'u';
	}
}

void	ft_hand_int_cast(t_printf *pr, unsigned short base, short capitalize)
{
	pr->base = base;
	pr->capitalize = capitalize;
	ft_hand_int_init(pr);
	if (pr->specif == 0)
		(pr->issigned) ? ft_handle_int(pr, va_arg(pr->ap, int)) :
		ft_handle_int(pr, va_arg(pr->ap, unsigned int));
	else if (pr->specif == 1)
		(pr->issigned) ? ft_handle_int(pr, (short)va_arg(pr->ap, int)) :
		ft_handle_int(pr, (unsigned short)va_arg(pr->ap, unsigned int));
	else if (pr->specif == 2)
		(pr->issigned) ? ft_handle_int(pr, (char)va_arg(pr->ap, int)) :
		ft_handle_int(pr, (unsigned char)va_arg(pr->ap, int));
	else if (pr->specif == 3)
		(pr->issigned) ? ft_handle_int(pr, va_arg(pr->ap, long)) :
		ft_handle_int(pr, va_arg(pr->ap, unsigned long));
	else if (pr->specif == 4)
		(pr->issigned) ? ft_handle_int(pr, va_arg(pr->ap, long long)) :
		ft_handle_int(pr, va_arg(pr->ap, unsigned long long));
	else if (pr->specif == 5)
		(pr->issigned) ? ft_handle_int(pr, va_arg(pr->ap, intmax_t)) :
		ft_handle_int(pr, va_arg(pr->ap, uintmax_t));
	else if (pr->specif == 6)
		(pr->issigned) ? ft_handle_int(pr, va_arg(pr->ap, ssize_t)) :
		ft_handle_int(pr, va_arg(pr->ap, size_t));
}
