/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:14:38 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/15 16:20:39 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		power_dec(int n)
{
	int	i;
	int	del;

	i = 1;
	del = 1;
	while (i < n)
	{
		del *= 10;
		i++;
	}
	return (del);
}

static	int		str_size(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static	char	*str_maker(long nb)
{
	int		str_long;
	char	*str;

	str_long = 0;
	str_long = str_size(nb);
	if (!(str = (char*)malloc(sizeof(char) * (str_long + 1))))
		return (NULL);
	str[str_long] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	int		base;
	long	nb;
	char	*str;

	i = 0;
	base = 1;
	nb = n;
	if (!(str = str_maker(nb)))
		return (NULL);
	if (nb < 0)
	{
		str[i++] = '-';
		base = power_dec(str_size(nb) - 1);
		nb *= -1;
	}
	else
		base = power_dec(str_size(nb));
	while (base != 0)
	{
		str[i++] = nb / base + '0';
		nb = nb % base;
		base = base / 10;
	}
	return (str);
}
