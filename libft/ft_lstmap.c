/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:31:46 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*n_list;
	t_list	*n_temp;

	if (!(lst) || !(f))
		return (NULL);
	if (!(n_list = f(lst)))
		return (NULL);
	lst = lst->next;
	n_temp = n_list;
	while (lst)
	{
		if (!(n_temp->next = f(lst)))
			return (NULL);
		n_temp = n_temp->next;
		lst = lst->next;
	}
	return (n_list);
}
