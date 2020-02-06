/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:50:11 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/27 08:40:26 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_ops.h"

int		get_op_code(t_process *proc)
{
	proc->op = (int)(vm.arena[proc->pos]);
	if (proc->op < 1 || proc->op > 16)
	{
		proc->op = 17;
		proc->pc = 1;
	}
	else
		proc->delay = op_tab[proc->op - 1].op_delay;
	return (1);
}

void	intro(void)
{
	int		i;

	i = 0;
	ft_printf("%s\n", "Introducing contestants...");
	while (++i <= MAX_PLAYERS)
	{
		if (vm.players[i].id)
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
					vm.players[i].id, vm.players[i].code_size,
					vm.players[i].name, vm.players[i].comment);
	}
}

void	ft_exec_op(t_process *proc)
{

	if (!op_tab[proc->op - 1].has_args_code)
	{
		proc->args[0] = op_tab[proc->op - 1].args_types[0];
		proc->pc += 1 + calc_args_size(0, proc);
	}
	else
		process_args_code(proc);
	parse_args_values(proc);
	if (!proc->op_error)
		if (check_regs(proc))
			op_tab[proc->op - 1].operations(proc);
}

int		check_proc(void)
{
	t_process *proc;

	proc = vm.processes;
	while (proc)
	{
		if (!proc->delay)
			get_op_code(proc);
		proc->delay -= (proc->delay > 0) ? 1 : 0;
		if (!proc->delay)
		{
			if (proc->proc_id == 1)
				proc = proc;
			if (proc->op > 0 && proc->op < 17)
				ft_exec_op(proc);
			if (vm.log_level & PC && proc->pc > 1)
				if (proc->op != 9 || (proc->op == 9 && !proc->carry))
					print_proc_movement(proc->pos, proc->pc);
			proc->pos = position_correction(proc->pos + proc->pc);
			proc->pc = 0;
			proc->op_error = 0;
			ft_bzero((void*)proc->args, sizeof(int) * 4);
			ft_bzero((void*)proc->args_value, sizeof(int) * 3);
		}
		proc = proc->next;
	}
	return (1);
}

int		battle(void)
{
	intro();
	while (vm.processes)
	{
		++vm.cycle_current;
		++vm.cycles_all;
		if (vm.cycles_all == 25902)
			vm.cycles_all = 25902;
		if (vm.log_level & CYCLE)
			ft_printf("It is now cycle %d\n", vm.cycles_all);
		check_proc();
		if (vm.cycle_current == vm.cycles_to_die || vm.cycles_to_die <= 0)
			battle_check();
		if (vm.cycles_all == vm.dump_cycle)
			print_arena(0, 0, 0, 0);
	}
	ft_printf("Contestant %d, \"%s\", has won !\n", vm.last_alive->id, vm.last_alive->name);
    if (DEBUG)
    {
        ft_printf("vm.checks = %d\nvm.cycles_all = %d\nvm.cycle_current = "
                  "%d\nproccesses_count = %d\ncycle_to_die = %d\n",
                  vm.checks, vm.cycles_all, vm.cycle_current, vm.process_count, vm.cycles_to_die);
        int i = 0;
        while (++i < vm.players_sum + 1)
            ft_printf("vm.player[%d].lives_all = %d\n",
                      i, vm.players[i].lives_all);
    }
	return (0);
}
