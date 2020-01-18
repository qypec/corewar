/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:11:12 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	ft_putstr_pf_flags(t_printf *pr, const char *s)
{
	if (pr->flags & MINUS)
	{
		add_buf_str(pr, (unsigned char*)s);
		print_width(pr);
	}
	else
	{
		print_width(pr);
		add_buf_str(pr, (unsigned char*)s);
	}
}

void	ft_putstr_pf(t_printf *pr, char const *s)
{
	int slen;

	if (!s)
		s = (const char*)"(null)";
	slen = ft_strlen(s);
	if (pr->precision >= 0)
	{
		pr->len = pr->precision;
		if (pr->precision > slen)
			pr->len = slen;
	}
	else
		pr->len = slen;
	if (pr->width > 0)
		ft_putstr_pf_flags(pr, s);
	else
		add_buf_str(pr, (unsigned char*)s);
}

void	ft_putchar_pf(t_printf *pr, unsigned char c)
{
	if (pr->width)
	{
		pr->width--;
		if (pr->flags & MINUS)
		{
			add_buf_symb(pr, c, 1);
			print_width(pr);
		}
		else
		{
			print_width(pr);
			add_buf_symb(pr, c, 1);
		}
	}
	else
		add_buf_symb(pr, c, 1);
}
