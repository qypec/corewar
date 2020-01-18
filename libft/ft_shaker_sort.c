/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shaker_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:03:20 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_shaker_sort(char *s)
{
	int i;
	int left;
	int right;

	if (!s)
		return ;
	left = 1;
	right = ft_strlen(s);
	while (left < right)
	{
		i = left - 1;
		while (++i < right)
			if (s[i - 1] > s[i])
				ft_swap(&s[i - 1], &s[i]);
		right--;
		i = right;
		while (left <= --i)
			if (s[i - 1] > s[i])
				ft_swap(&s[i - 1], &s[i]);
		left++;
	}
}
