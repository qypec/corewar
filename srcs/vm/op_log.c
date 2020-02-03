
#include "corewar_ops.h"

void print_proc_movement(int position, int offset)
{
	int byte;

	byte = -1;
	ft_printf("ADV %d (", offset);
	if (!position)
		ft_printf("0x");
	ft_printf("%#.4x -> %#.4x) ",
			  position,
			  position_correction(position + offset));
	while (++byte < offset)
	{
		ft_printf("%.2x", vm.arena[position_correction(position + byte)]);
		if (byte == offset - 1)
			ft_printf("\n");
		else
			ft_printf(" ");
	}
}

void	print_args(t_process *proc, int *arg)
{
	int i;

	i = -1;
	while (++i < op_tab[proc->op - 1].argc)
	{
		if (proc->args[i] == T_REG && !(proc->op == 11 && op_tab[proc->op - 1].argc - 1 == i))
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
			args[1], args[2], args[1] + args[2], proc->pos + (args[1] + args[2]) % IDX_MOD);
	if (proc->op == 14)
		ft_printf("       | -> %s from %d + %d = %d (with pc %d)\n", op_tab[proc->op - 1].op_name,
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