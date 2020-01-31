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

	i = -1;
	ft_printf("%s\n", "Introducing contestants...");
	while (++i < MAX_PLAYERS)
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
		proc->args[0] = op_tab[proc->op - 1].args_types[0];
	else
		process_args_code(proc);
	if (proc->op == 8)
		proc->op = 8;
	if (proc->op > 0 && proc->op < 17
		&& parse_args_values(proc, proc->op, proc->pos, 1)
		&& check_regs(proc, proc->op))
	{
		if (position_correction((proc->pos + ((int) get_arg_op(proc, 1) + (int) get_arg_op(proc, 2)) % IDX_MOD)) == 73)
			proc->pos = proc->pos;
		op_tab[proc->op - 1].operations(proc);
		if (vm.log_level & PC && proc->op == 9 && proc->carry == 1)
			print_zjmp_movement(proc);
		else if (vm.log_level & PC)
			print_proc_movement(proc->pos, proc->pc);

		ft_bzero((void*)proc->args, sizeof(int) * 4);
		ft_bzero((void*)proc->args_value, sizeof(int) * 3);
	}
	proc->pos = position_correction(proc->pos + proc->pc);
	proc->pc = 0;
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
			ft_exec_op(proc);
		proc = proc->next;
	}
	return (1);
}

int		battle(void)
{
	intro();
	while (vm.processes)
	{

		check_proc();
		if (vm.log_level & CYCLE)
			ft_printf("It is now cycle %d\n", vm.cycles_all);
		if (vm.cycle_current == vm.cycles_to_die || vm.cycles_to_die <= 0)
			battle_check();
		if (vm.cycles_all == vm.dump_cycle)
			print_arena(0, 0, 0, 0);
        ++vm.cycle_current;
        ++vm.cycles_all;
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
