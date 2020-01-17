/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:24:37 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/17 18:24:39 by ergottli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

void		init_var(t_process **new)
{
	(*new)->pc = 0;
	(*new)->op = 0;
	(*new)->carry = 0;
	(*new)->delay = 0;
	(*new)->live_incycle = 0;
	ft_bzero(((*new)->regs + 1), REG_SIZE - 1);
}

t_process	*create_process(int n_player, int position)
{
	t_process	*new;

	if (!(new = (t_process*)malloc(sizeof(t_process))))
		return (NULL);
	if (vm.processes == NULL)
	{
		new->proc_id = 1;
		new->next = NULL;
	}
	else
	{
		new->proc_id = vm.processes->proc_id + 1;
		new->next = vm.processes;
		vm.processes = new;
	}
	new->player_id = vm.players[n_player].id;
	new->pos = position;
	new->regs[0] = vm.players[n_player].id;
	init_var(&new);
	return (new);
}
