/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:56:23 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

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
		nb *= -1;
	if (nb == 0)
		return (2);
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	if (nb < 10)
		++count;
	return (count);
}

static	char	*str_maker(long nb)
{
	int		str_long;
	char	*str;

	str_long = 0;
	str_long = str_size(nb) + 1;
	if (!(str = (char*)malloc(sizeof(char) * (str_long + 1))))
		return (NULL);
	str[str_long] = '\0';
	return (str);
}

char			*ft_sign_itoa(int n)
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
	str[i++] = (nb >= 0) ? '+' : '-';
	nb *= (nb < 0) ? -1 : 1;
	if (nb < 10)
		str[i++] = '0';
	base = power_dec(str_size(nb) - 1);
	while (base != 0)
	{
		str[i++] = nb / base + '0';
		nb = nb % base;
		base = base / 10;
	}
	return (str);
}
