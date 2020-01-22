/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:24:09 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/22 18:34:19 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

void update_cycle_to_die(void)
{
	if (vm.lives_in_round >= NBR_LIVE)
		vm.cycles_to_die = vm.cycles_to_die_last - CYCLE_DELTA;
	else
		vm.cycles_to_die = vm.cycle_current;
	if (vm.cycles_to_die == vm.cycles_to_die_last)
		vm.cycles_to_die_updated++;
	else
		vm.cycles_to_die_updated = 0;
	if ((vm.cycles_to_die_updated >= MAX_CHECKS))
	{
		vm.cycles_to_die = vm.cycles_to_die_last - CYCLE_DELTA;
		vm.cycles_to_die_updated = 0;
	}
	++vm.checks;
	vm.cycles_to_die_last = vm.cycle_current;
	vm.cycle_current = 0;
}

int 	kill_all_procs(void)
{
	t_process *procs;
	t_process *next;

	procs = vm.processes;
	while (procs)// TODO: Удалить все процессы
	{
		next = procs->next;
		del_process(procs);
		procs = next;
	}
}

int 	check_procs(void)
{
	t_process *temp;
	t_process *next;

	temp = vm.processes;
	while (temp)
	{
		if (!temp->live_incycle) // TODO: Если не было выполнено операций live за раунд - удалить процесс
		{
				next = temp->next;
				del_process(temp);
				temp = next;
		}
		else
			temp = temp->next;
	}
}

int 	battle_check()
{
	update_cycle_to_die();
	check_procs();
	if (vm.cycles_to_die <= 0)
	{
		kill_all_procs();
		vm.cycles_to_die = vm.cycles_to_die_last - CYCLE_DELTA;
	}
}