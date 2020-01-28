
#include "corewar_ops.h"

void	st_log(t_process *proc)
{
	if (proc->args[1] == T_REG)
		ft_printf("P %d | st %d r%d\n", proc->proc_id,
				  proc->regs[proc->args_value[1] - 1], proc->args_value[1]);
	else
		ft_printf("P %d | st %d %d\n", proc->proc_id,
				  proc->args_value[1] - 1,
				  position_correction(proc->pos + proc->args_value[1] % IDX_MOD));
}

void	print_args(t_process *proc, int *arg)
{
	int i;

	i = -1;
	while (++i < op_tab[proc->op - 1].argc)
	{
		if (proc->args[i] == T_REG)
			ft_printf("r%d", arg[i]);
		else
			ft_printf("%d", arg[i]);
		if (i != op_tab[proc->op - 1].argc - 1)
			ft_printf(" ");
		else
			ft_printf("\n");
	}
}

void	print_verbose(t_process *proc, int *args)
{
	if (proc->op == 10)
		ft_printf("       | -> %s from %d + %d = %d (with pc and mod %d)\n", op_tab[proc->op - 1].op_name,
				  args[0], args[1], args[0] + args[1], proc->pos + (args[0] + args[1]) % IDX_MOD);
	if (proc->op == 11)
		ft_printf("       | -> %s to %d + %d = %d (with pc and mod %d)\n", op_tab[proc->op - 1].op_name,
			args[0], args[1], args[0] + args[1], proc->pos + (args[0] + args[1]) % IDX_MOD);
	if (proc->op == 14)
		ft_printf("       | -> %s from %d + %d = %d (with pc and mod %d)\n", op_tab[proc->op - 1].op_name,
				  args[0], args[1], args[0] + args[1], proc->pos + (args[0] + args[1]));
}

void	universal_op_log(t_process *proc, int arg0, int arg1, int arg2)
{
	int args[3];

	args[0] = arg0;
	args[1] = arg1;
	args[2] = arg2;
	ft_printf("P%5d | %s ", proc->proc_id, op_tab[proc->op - 1].op_code);
	print_args(proc, args);
	print_verbose(proc, args);
}