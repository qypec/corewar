
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

int 	get_code_code(t_process *proc)
{
	int ps;

	ps = (int)(vm.arena[position_correction(proc->pos + proc->pc)]);
	if (ps < 1 || ps > 16) // TODO: what we should to do if isn't valid?
		ps = 17;
	return (ps);
}

int 		process_args_code_zjmp(t_process *proc, int op_code)
{
	int 			i;

	i = -1;
	while (++i < 4)
	{
		if (!check_args_type((*(vm.arena + position_correction(proc->pos + proc->pc + 1u))
							  & (192u >> (unsigned) (i * 2))) >> (6u - (unsigned) (i * 2)),
							 op_tab[proc->op - 1].args_types + i * 3, proc, i))
			return (0);
	}
	return (op_code);
}

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

void	print_zjmp_movement(t_process *proc)
{
	int 	op_code;
	int 	offset;

	op_code = get_code_code(proc);
	if (!op_tab[op_code - 1].has_args_code)
		proc->args[0] = op_tab[op_code].args_types[0];
	else
		op_code = process_args_code_zjmp(proc, op_code);
	offset = parse_args_values(proc, op_code, position_correction(proc->pos + proc->pc), 0);
	if (op_code == 0) //TODO: we don't know exactly what must be here
		offset = 1;
	if (op_code > 0 && op_code < 17 && check_regs(proc, op_code))
		print_proc_movement(position_correction(proc->pos + proc->pc), offset);
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