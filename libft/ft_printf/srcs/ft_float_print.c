/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:35:14 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void			simple_float_print(unsigned char *str, t_printf *pr, int flag)
{
	if (GET_BIT(pr->flags, MINUS_FLOAT))
		add_buf_symb(pr, '-', 1);
	else if (GET_BIT(pr->flags, SPACE))
		add_buf_symb(pr, ' ', 1);
	else if (GET_BIT(pr->flags, PLUS) && !(GET_BIT(pr->flags, NAN)))
		add_buf_symb(pr, '+', 1);
	if (flag == 1)
		add_buf_str(pr, str);
}

void			hard_float_print(unsigned char *str, t_printf *pr)
{
	if (GET_BIT(pr->flags, MINUS))
	{
		simple_float_print(str, pr, 1);
		add_buf_symb(pr, ' ', pr->width - pr->len);
	}
	else
	{
		CLEAR_BIT(pr->flags, SPACE);
		if (!(GET_BIT(pr->flags, ZERO)))
		{
			(GET_BIT(pr->flags, PLUS) || GET_BIT(pr->flags, MINUS_FLOAT)) ?
			add_buf_symb(pr, ' ', pr->width - pr->len - 1) :
			add_buf_symb(pr, ' ', pr->width - pr->len);
			simple_float_print(str, pr, 1);
		}
		else
		{
			simple_float_print(str, pr, 0);
			(GET_BIT(pr->flags, PLUS) || GET_BIT(pr->flags, MINUS_FLOAT)) ?
			add_buf_symb(pr, '0', pr->width - pr->len - 1) :
			add_buf_symb(pr, ' ', pr->width - pr->len);
			CLEAR_BIT(pr->flags, 255u);
			simple_float_print(str, pr, 1);
		}
	}
}

void			ft_put_float(unsigned char *str, t_printf *pr)
{
	pr->len = (int)ft_strlen((char*)str);
	if (pr->len >= pr->width)
		simple_float_print(str, pr, 1);
	else
		hard_float_print(str, pr);
	free(str);
}

void			print_float(unsigned char *str, t_printf *pr)
{
	int			len;

	pr->precision = (pr->precision == -1) ? 6 : pr->precision;
	len = ind_after_len(str);
	if (pr->precision > len && !((GET_BIT(pr->flags, INF)
	|| (GET_BIT(pr->flags, NAN)))))
		str = (unsigned char*)ft_strjoin_free((char*)str,
			str_zero(pr->precision - len));
	else if (pr->precision < len)
		str = round_float(pr, str);
	if (pr->type == 'e' || pr->type == 'E')
		str = ft_add_e(str, pr);
	ft_put_float(str, pr);
}
