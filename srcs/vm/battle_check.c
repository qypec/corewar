/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:24:09 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/27 01:13:38 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	update_cycle_to_die(void)
{
	vm.cycle_current = 0;
	++vm.cycles_to_die_not_updated;
	vm.cycles_to_die_last = vm.cycles_to_die;
	if (vm.lives_in_round >= NBR_LIVE ||
	vm.cycles_to_die_not_updated == MAX_CHECKS || vm.cycles_to_die <= 0)
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

int		kill_all_procs(void)
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

void	check_procs(void)
{
	t_process *temp;
	t_process *next;
	int odin;
	int flag;

	temp = vm.processes;
	flag = 0;
	odin = 0;
	while (temp)
	{
		flag = 0;
		if (!temp->live_incycle) // Если не было выполнено операций live за раунд - удалить процесс
		{
//				if (DEBUG_DEL_PROC)
//				{
//					ft_printf(ANSI_B_GREEN"ID_BEFORE_DEL = %d\n"ANSI_RESET, temp->proc_id);
//					if (temp->next)
//					{
//						flag = 1;
//						ft_printf(ANSI_B_CYAN"ID_BEFORE_DEL_NEXT = %d\n"ANSI_RESET, temp->next->proc_id);
//						odin = temp->next->proc_id;
//					}
//				}
				next = temp->next;
				del_process(temp);
				temp = next;
//				ft_printf(ANSI_B_BLUE"ID_AFTER_DEL = %d\n"ANSI_RESET, temp->proc_id);
//				if (DEBUG_DEL_PROC && flag == 1 && odin != temp->proc_id)
//					ft_printf(ANSI_RED"ERROR\n");
		}
		else
		{
			temp->live_incycle = 0;
			temp = temp->next;
		}
	}
}

void	battle_check()
{
	++vm.checks;
	if (vm.cycles_to_die <= 0)
		kill_all_procs();
	update_cycle_to_die();
	check_procs();
	vm.lives_in_round = 0;
	if (vm.log_level & CYCLE && vm.cycles_to_die != vm.cycles_to_die_last)
		ft_printf("Cycle to die is now %d\n", vm.cycles_to_die);
}
