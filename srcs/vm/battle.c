#include "../../incs/corewar.h"


int 	get_op_code(t_process *proc)
{
	proc->op = (int)(vm.arena[proc->pos]);
	if (proc->op < 1 || proc->op > 16)
		proc->op = 0;
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

void ft_exec_op(t_process *proc)
{
	set_args_code(proc); // запись значений кодов аргументов
	if (proc->op > 0 && proc->op < 17
	&& check_op_args(proc) // проверка валидности кода операции и соответствия кодов аргументов текущей операции
	&& parse_args_values(proc)) // парсинг значений аргументов и валидация регистров при их наличии
		vm.ops[proc->op](proc); // исполнение операции (из массива указателей на функции операций)
	if (proc->args[0] == T_REG_ARG || proc->args[1] == T_REG_ARG || proc->args[2] == T_REG_ARG)
		check_regs(proc);
	proc->pos += proc->pc; // смещение позиции процесса в соотвествии со значением PC
}

int 	check_proc(void)
{
	t_process *iter;

	iter = vm.processes;
	while (iter)
	{
		if (!iter->delay)
			get_op_code(iter); // парсинг кода текущей операции
		iter->delay -= (iter->delay > 0) ? 1 : 0;
		if (!iter->delay)
			ft_exec_op(iter); // парсинг и исполнение операции
		iter = iter->next;
	}
	return (1);
}

int 	battle(void)
{
	int i;

	i = 0;
	intro();
	while (vm.processes) // TODO: add dump function
	{
		check_proc(); // проверка процессов, парсинг и исполнение
		if (vm.cycles_to_die < 1)
			battle_check(); // проверка хода игры
		vm.cycles_to_die -= 1;
		++vm.cycle_current;
		++vm.cycles_all;
	} // TODO: print last alive player
	return (0);
}