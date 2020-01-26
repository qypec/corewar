
#include "corewar_ops.h"

void	st_log(t_process *proc)
{
	if (proc->args[1] == T_REG)
		ft_printf("P %d | st %d r%d\n", proc->proc_id,
				  proc->regs[proc->args_value[1] - 1], proc->args_value[1]);
	else
		ft_printf("P %d | st %d %d\n", proc->proc_id,
				  proc->regs[proc->args_value[1] - 1],
				  position_correction(proc->pos + proc->args_value[1] % IDX_MOD));
}

void	and_log(t_process *proc, unsigned int arg1, unsigned int arg2)
{
	ft_printf("P %d | and %d r%d\n", proc->proc_id,
			  proc->regs[proc->args_value[1] - 1], proc->args_value[1]);
	if (proc->args[0] == T_REG)
		ft_printf("r%d ", arg1);
	else
		ft_printf("%d ", arg1);
	if (proc->args[1] == T_REG)
		ft_printf("r%d r%d\n", arg2, proc->args_value[2]);
	else
		ft_printf("%d %d\n", arg2, proc->args_value[2]);
}