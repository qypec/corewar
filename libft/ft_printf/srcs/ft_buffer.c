/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:58:36 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	print_buf(t_printf *pr)
{
	if (!pr->i)
		return ;
	pr->count += pr->i;
	write(1, &pr->buf, pr->i);
	pr->i = 0;
}

void	buf_symb_xxl(t_printf *pr, char c, int len)
{
	int i;

	i = -1;
	while (++i < len)
	{
		if (i > PF_BUFFER)
			print_buf(pr);
		pr->buf[pr->i] = c;
		++pr->i;
	}
}

void	add_buf_symb(t_printf *pr, char c, int len)
{
	if (len > PF_BUFFER)
	{
		buf_symb_xxl(pr, c, len);
		return ;
	}
	if (pr->i + len > PF_BUFFER)
		print_buf(pr);
	while (--len > -1)
	{
		pr->buf[pr->i] = c;
		++pr->i;
	}
}

void	buf_str_xxl(t_printf *pr, unsigned char const *str)
{
	int i;

	i = -1;
	while (++i < pr->len)
	{
		if (i > PF_BUFFER)
			print_buf(pr);
		pr->buf[pr->i] = str[i];
		++pr->i;
	}
}

void	add_buf_str(t_printf *pr, unsigned char const *str)
{
	int i;

	i = -1;
	if (!str)
		return ;
	if (pr->len > PF_BUFFER)
	{
		buf_str_xxl(pr, str);
		return ;
	}
	if (pr->i + pr->len > PF_BUFFER)
		print_buf(pr);
	while (++i < pr->len)
	{
		pr->buf[pr->i] = str[i];
		++pr->i;
	}
}
