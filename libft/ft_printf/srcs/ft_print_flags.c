/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:49:53 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	print_width(t_printf *pr)
{
	pr->width -= (pr->width >= pr->len) ? pr->len : pr->width;
	if (NUMERIC || POINTER)
		pr->toprint = (pr->flags & ZERO && pr->precision == -1) ? '0' : ' ';
	else
		pr->toprint = (pr->flags & ZERO) ? '0' : ' ';
	add_buf_symb(pr, pr->toprint, pr->width);
}
