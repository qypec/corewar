/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_d_int_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:34:52 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**new_d_int_arr(int first, int second)
{
	int i;
	int **arr;

	i = -1;
	if (!(arr = (int**)malloc(sizeof(int*) * first)))
		return (NULL);
	while (++i < first)
	{
		if (!(arr[i] = (int*)malloc(sizeof(int) * second)))
		{
			free_d_int_arr(arr, i);
			return (NULL);
		}
	}
	return (arr);
}
