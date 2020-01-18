/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_summator_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:26:52 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			over_plus(unsigned char **num, int i, int flag)
{
	unsigned char *temp;

	temp = *num;
	if (i > flag)
	{
		if (temp[i] > '9')
		{
			temp[i] -= 10;
			if (temp[i - 1] == '.')
				--i;
			if (i > -1)
				temp[i - 1] += 1;
		}
		over_plus(&temp, i - 1, flag);
	}
}

int				ind_after_len(unsigned char *s)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (*s)
	{
		if (flag == 1)
			++i;
		if (*s == '.')
			flag = 1;
		s++;
	}
	return (i);
}

int				ind_before_len(unsigned char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '.')
		++i;
	return (i);
}
