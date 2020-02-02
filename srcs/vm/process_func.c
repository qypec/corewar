/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:24:37 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/23 18:49:56 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_var(t_process **new)
{
	(*new)->pc = 0;
	(*new)->op = 0;
	(*new)->carry = 0;
	(*new)->delay = 0;
	(*new)->live_incycle = 0;
	ft_bzero((*new)->regs, REG_SIZE * REG_NUMBER);
	ft_bzero((*new)->args, sizeof(int) * 3);
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
		vm.processes = new;
	}
	else
	{
		new->proc_id = vm.proc_id_count + 1;
		new->next = vm.processes;
		vm.processes = new;
	}
	new->op_error = 0;
	new->player_id = vm.players[n_player].id;
	new->pos = position;
	init_var(&new);
	new->regs[0] = vm.players[n_player].id * -1;
	++vm.process_count;
	++vm.proc_id_count;
	return (new);
}

void		del_process(t_process *proc)
{
	t_process	*iter;
	t_process	*next;

	next = NULL;
	if (proc == vm.processes)
	{
		next = vm.processes->next;
		ft_memdel((void *)&proc);
		vm.processes = next;
		return ;
	}
	iter = vm.processes;
	while (iter && iter->next != proc)
		iter = iter->next;
	if (proc)
	{
		next = proc->next;
		ft_memdel((void *)&proc);
	}
	if (iter)
		iter->next = next;
	--vm.process_count;
}
