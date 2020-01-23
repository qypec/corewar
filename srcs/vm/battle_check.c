/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:24:09 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/23 18:48:55 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void update_cycle_to_die(void)
{
	vm.cycle_current = 0;
	++vm.cycles_to_die_not_updated;
	vm.cycles_to_die_last = vm.cycles_to_die;
	if (vm.lives_in_round >= NBR_LIVE || vm.cycles_to_die_not_updated == MAX_CHECKS)
	{
		vm.cycles_to_die -= CYCLE_DELTA;
		vm.cycles_to_die_not_updated = 0;
		if (DEBUG)
		{
			ft_printf("vm.cycles_all = %d\n", vm.cycles_all);
			ft_printf("vm.cycle_to_die = %d\n", vm.cycles_to_die);
			ft_printf("vm.cycle_to_die_last = %d\n", vm.cycles_to_die_last);
			ft_printf("vm.lives_in_round = %d\n", vm.lives_in_round);
			ft_printf("vm.checks = %d\n", vm.checks);
		}
	}
	else
	{
		if (DEBUG)
		ft_printf("vm.lives_in_round = %d,\n"
			"vm.cycles_to_die_updated = %d\n\n", vm.lives_in_round, vm.cycles_to_die_not_updated);
	}
}

int 	kill_all_procs(void)
{
	t_process *procs;
	t_process *next;

	procs = vm.processes;
	while (procs)
	{
		next = procs->next;
		del_process(procs);
		procs = next;
	}
	return (1);
}

void check_procs(void)
{
	t_process *temp;
	t_process *next;

	temp = vm.processes;
	while (temp)
	{
		if (!temp->live_incycle) // Если не было выполнено операций live за раунд - удалить процесс
		{
				next = temp->next;
				del_process(temp);
				temp = next;
		}
		else
		{
			temp->live_incycle = 0;
			temp = temp->next;
		}
	}
}

void battle_check()
{
	++vm.checks;
	if (vm.cycles_to_die <= 0)
		kill_all_procs();
	update_cycle_to_die();
	check_procs();
	vm.lives_in_round = 0;
}