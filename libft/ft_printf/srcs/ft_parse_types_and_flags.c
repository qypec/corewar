/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:03:27 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int		types_checker(char c)
{
	int flag;

	flag = 0;
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'f' || c == 'e')
		flag = 1;
	if (c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'F' || c == 'E')
		flag = 1;
	if (c == 's' || c == 'p' || c == '%')
		flag = 1;
	return (flag);
}

int		spec_checker(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L')
		return (1);
	return (0);
}

int		flags_checker(char c)
{
	if (c == '+' || c == '-' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

void	parse_types(t_printf *pr)
{
	const char *ptr;

	ptr = pr->form;
	while ((flags_checker(*ptr) || ft_isdigit(*ptr) || spec_checker(*ptr)
	|| *ptr == '.') && *ptr != '%' && *(ptr + 1))
		ptr++;
	pr->type = *ptr;
}

void	parse_flags(t_printf *pr)
{
	const char *ptr;

	ptr = pr->form;
	pr->flags = 0;
	while (!(types_checker(*ptr)) && *ptr)
	{
		if (flags_checker(*ptr))
		{
			(*ptr == '+') ? SET_BIT(pr->flags, PLUS) : 0;
			(*ptr == '-') ? SET_BIT(pr->flags, MINUS) : 0;
			(*ptr == ' ' && !(GET_BIT(pr->flags, PLUS)))
			? SET_BIT(pr->flags, SPACE) : 0;
			(*ptr == '#') ? SET_BIT(pr->flags, HASH) : 0;
			(*ptr == '0' && *(ptr - 1) != '.') ? SET_BIT(pr->flags, ZERO) : 0;
		}
		if (ft_isdigit(*ptr))
			while (ft_isdigit(*ptr))
				ptr++;
		else
			ptr++;
	}
	(pr->flags & PLUS) ? CLEAR_BIT(pr->flags, SPACE) : 0;
	(pr->flags & MINUS) ? CLEAR_BIT(pr->flags, ZERO) : 0;
}
