/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:54:59 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	parse_width(t_printf *pr)
{
	const char	*ptr;
	char		tmp[21];
	int			i;

	ptr = pr->form;
	ft_bzero((void*)tmp, 21);
	i = 0;
	while (*ptr != '%' && *ptr && *ptr != '.'
	&& ((flags_checker(*ptr) || spec_checker(*ptr)) && !types_checker(*ptr)))
		ptr++;
	while (*ptr && ft_isdigit(*ptr))
	{
		tmp[i] = *ptr;
		i++;
		ptr++;
	}
	if (i > 0)
		pr->width = ft_atoi(tmp);
}

void	parse_precision(t_printf *pr)
{
	const char	*ptr;
	char		tmp[21];
	int			i;

	ptr = pr->form;
	ft_bzero((void*)tmp, 21);
	i = -1;
	while ((*ptr != '.') && *ptr && *ptr != '%' && !types_checker(*ptr))
		ptr++;
	if (*ptr == '.')
	{
		ptr++;
		if (!ft_isdigit(*ptr))
			pr->precision = 0;
		while (ft_isdigit(*ptr) && *ptr)
		{
			tmp[++i] = *ptr;
			ptr++;
		}
	}
	if (i >= 0)
		pr->precision = ft_atoi(tmp);
}
