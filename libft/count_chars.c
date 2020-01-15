/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:54:36 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/15 16:20:40 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_chars(char *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			++count;
		++str;
	}
	return (count);
}
