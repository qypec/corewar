/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:47:53 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	init_pr(t_printf *pr)
{
	pr->len = 0;
	pr->base = 0;
	pr->specif = 0;
	pr->type = 0;
	pr->flags = 0;
	pr->width = 0;
	pr->precision = -1;
	pr->capitalize = 0;
	pr->issigned = 0;
}

int		parse_specificators(t_printf *pr)
{
	const char *ptr;

	ptr = pr->form;
	while ((!types_checker(*ptr)) && *ptr && *ptr != '%')
	{
		pr->specif = (*ptr == 'h' && *(ptr + 1) != 'h' && *(ptr - 1) != 'h')
				? 1 : pr->specif;
		pr->specif = (*ptr == 'h' && *(ptr + 1) == 'h') ? 2 : pr->specif;
		pr->specif = (*ptr == 'l' && *(ptr + 1) != 'l' && *(ptr - 1) != 'l')
				? 3 : pr->specif;
		pr->specif = (*ptr == 'l' && *(ptr + 1) == 'l') ? 4 : pr->specif;
		pr->specif = (*ptr == 'j') ? 5 : pr->specif;
		pr->specif = (*ptr == 'z') ? 6 : pr->specif;
		pr->specif = (*ptr == 'L') ? 10 : pr->specif;
		if (pr->specif == 4 || pr->specif == 5 || pr->specif == 6)
			break ;
		ptr++;
	}
	if (pr->specif)
		return (1);
	return (0);
}

int		parse_conversation(t_printf *pr)
{
	char type;

	type = pr->type;
	if (type == 'c')
		ft_putchar_pf(pr, va_arg(pr->ap, int));
	else if (type == 's')
		ft_putstr_pf(pr, va_arg(pr->ap, char *));
	else if (type == 'd' || type == 'i' || pr->type == 'u' || pr->type == 'U')
		ft_hand_int_cast(pr, 10, 0);
	else if (type == 'p')
		ft_hand_int_cast(pr, 16, 0);
	else if (type == 'o')
		ft_hand_int_cast(pr, 8, 0);
	else if (type == 'x')
		ft_hand_int_cast(pr, 16, 0);
	else if (type == 'X')
		ft_hand_int_cast(pr, 16, 1);
	else if ((type >= 'e' && type <= 'g') || (type >= 'E' && type <= 'G'))
		ft_float(pr);
	else if (type == '%')
		ft_putchar_pf(pr, '%');
	else
		ft_putchar_pf(pr, pr->type);
	return (1);
}

int		parse(t_printf *pr)
{
	pr->start(pr);
	g_isnull = 0;
	pr->form++;
	if (*pr->form == '\0')
		return (0);
	if (!types_checker(*pr->form))
	{
		parse_flags(pr);
		parse_width(pr);
		parse_precision(pr);
		parse_specificators(pr);
	}
	parse_types(pr);
	while ((flags_checker(*pr->form) || ft_isdigit(*pr->form)
	|| spec_checker(*pr->form) || *pr->form == '.')
	&& *pr->form != '%' && *(pr->form))
		pr->form++;
	if (!parse_conversation(pr))
		return (0);
	return (1);
}

int		ft_printf(const char *format, ...)
{
	t_printf	pr;

	pr.i = 0;
	pr.form = format;
	pr.start = &init_pr;
	pr.count = 0;
	va_start(pr.ap, format);
	while (*pr.form)
	{
		if (*pr.form == '%')
		{
			if (parse(&pr))
				pr.form++;
			continue ;
		}
		if (*pr.form == '\0')
			break ;
		add_buf_symb(&pr, pr.form[0], 1);
		pr.form++;
	}
	print_buf(&pr);
	va_end(pr.ap);
	return (pr.count);
}
