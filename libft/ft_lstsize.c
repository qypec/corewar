/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:05:15 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/27 18:05:35 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns number of items in list
**
** @param 		alst
** @return		len
*/

size_t				ft_lstsize(t_list *alst)
{
	size_t			len;

	len = 0;
	while (alst != NULL)
	{
		len++;
		alst = alst->next;
	}
	return (len);
}
