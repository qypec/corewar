/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:49:10 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int				ft_ind_nzero(unsigned char *str)
{
	int				i;

	i = -1;
	while (str[++i])
	{
		if (str[i] > '0' && str[i] <= '9')
			break ;
	}
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int				e_for_e(t_printf *pr, int first_symb)
{
	int e;
	int k;

	k = 0;
	if (pr->isnegative > first_symb)
		k = -1;
	e = pr->isnegative - first_symb + k;
	return (e);
}

unsigned char	*ft_add_e(unsigned char *new, t_printf *pr)
{
	char *e;

	e = ft_sign_itoa(pr->base);
	e = (pr->type == 'e') ? ft_strrejoin_right("e", e)
			: ft_strrejoin_right("E", e);
	new = (unsigned char*)ft_strjoin_free((char*)new, e);
	return (new);
}

int				ft_flag_e_init(t_printf *pr, unsigned char *temp)
{
	int first_nzero_position;

	pr->isnegative = ind_before_len(temp);
	pr->len = ft_strlen((char*)temp);
	if ((first_nzero_position = ft_ind_nzero(temp)) == -1 ||
	!(pr->base = e_for_e(pr, first_nzero_position)))
		return (0);
	if (pr->isnegative == -2)
		return (0);
	return (first_nzero_position);
}

void			ft_flag_e(unsigned char **res, t_printf *pr)
{
	int				first_nzero_position;
	int				i;
	unsigned char	*temp;
	unsigned char	*new;

	i = 0;
	temp = *res;
	first_nzero_position = ft_flag_e_init(pr, temp);
	new = (unsigned char*)ft_strnew(pr->len - first_nzero_position);
	while (first_nzero_position < pr->len)
	{
		if (temp[first_nzero_position] == '.')
		{
			++first_nzero_position;
			continue ;
		}
		new[i] = (i == 1) ? '.' : temp[first_nzero_position];
		if (i != 1)
			++first_nzero_position;
		++i;
	}
	free(temp);
	*res = new;
}
