/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_d_char_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:36:08 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**new_d_char_arr(int first, int second)
{
	int		i;
	char	**arr;

	i = -1;
	if (!(arr = (char**)malloc(sizeof(char*) * (first + 1))))
		return (NULL);
	arr[first] = NULL;
	while (++i < first)
	{
		if (!(arr[i] = ft_strnew(second)))
		{
			free_d_char_arr(arr, i);
			return (NULL);
		}
	}
	return (arr);
}
