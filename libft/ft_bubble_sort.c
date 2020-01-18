/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:10:53 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubble_sort(char *s)
{
	int i;
	int	max;

	if (!s)
		return ;
	i = 1;
	max = ft_strlen(s);
	while (i < max)
	{
		while (i < max)
		{
			if (s[i - 1] > s[i])
				ft_swap(&s[i - 1], &s[i]);
			i++;
		}
		i = 1;
		max--;
	}
}
