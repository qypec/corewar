/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:00:26 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lst_print(t_list *lst, unsigned char type, char n_flag)
{
	if (!lst)
		return ;
	if (type & ISCHARPTR)
	{
		while (lst)
		{
			ft_putstr(lst->content);
			if (n_flag)
				ft_putchar('\n');
			lst = lst->next;
		}
	}
	else if (type & ISINT)
	{
		while (lst)
		{
			ft_putnbr((int)lst->content);
			if (n_flag)
				ft_putchar('\n');
			lst = lst->next;
		}
	}
}
