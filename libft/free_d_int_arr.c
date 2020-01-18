/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_d_int_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:37:03 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_d_int_arr(int **arr, int len)
{
	int i;

	i = -1;
	while (++i < len)
		if (arr[i] != NULL)
			free(arr[i]);
	if (arr != NULL)
		free(arr);
}
