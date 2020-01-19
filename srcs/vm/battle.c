#include "../../incs/corewar.h"


int 	get_op_code(t_process *proc)
{
	proc->op = (int)vm.arena[proc->pos];
	if (proc->op < 1 || proc->op > 16)
		return (0);
	proc->delay = (proc->op == 1 || proc->op == 4
			|| proc->op == 5 || proc->op == 13)
			? 10 : proc->delay;
	proc->delay = (proc->op == 2 || proc->op == 3) ? 5 : proc->delay;
	proc->delay = (proc->op == 6 || proc->op == 7 || proc->op == 8) ? 6 : proc->delay;
	proc->delay = (proc->op == 9) ? 20 : proc->delay;
	proc->delay = (proc->op == 10 || proc->op == 11) ? 25 : proc->delay;
	proc->delay = (proc->op == 12) ? 800 : proc->delay;
	proc->delay = (proc->op == 14) ? 50 : proc->delay;
	proc->delay = (proc->op == 15) ? 1000 : proc->delay;
	proc->delay = (proc->op == 16) ? 2 : proc->delay;
	if (proc->op == 1 || proc->op == 9 || proc->op == 12 || proc->op == 15)
		proc->has_args_code = 0;
	else
		proc->has_args_code = 1;
	if (proc->op == 2 || (proc->op > 3 && proc->op < 9) || proc->op == 13 || proc->op == 14)
		proc->change_carry = 1;
	else
		proc->change_carry = 0;
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
					vm.players[i].id, vm.players[i].code_size, vm.players[i].name, vm.players[i].comment);
	}
}

void	ft_exec_op()
{

}

int 	check_proc(void)
{
	t_process *iter;

	iter = vm.processes;
	while (iter)
	{
		if (!iter->op)
			get_op_code(iter);
		if (!iter->delay)
			ft_exec_op(); // Здесь проверяется, пришло ли время для исолнения операции.
		else
			--iter->delay;
		iter = iter->next;
	}
	return (1);
}

int 	battle_check()
{

}

int 	battle(void)
{
	int i;

	i = 0;
	intro();
	while (++vm.cycles_all)
	{
		check_proc();
		if (vm.cycles_to_die < 1)
			battle_check();
		vm.cycles_to_die -= 1;
	}
	return (0);
}