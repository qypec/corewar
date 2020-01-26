
#include "corewar.h"

void	print_process(void)
{
	t_process	*temp;
	int 		i;

	temp = vm.processes;
	while (temp)
	{
		ft_printf("\n\n\n");
		ft_printf(ANSI_B_RED"proc_id = %d\n"ANSI_RESET, temp->proc_id);
		ft_printf("player_id = %d\n", temp->player_id);
		ft_printf("pos = %d\n", temp->pos);
		ft_printf("pc = %d\n", temp->pc);
		ft_printf("op = %d\n", temp->op);
		ft_printf(ANSI_B_GREEN"ARGS:\n"ANSI_RESET);
		i = -1;
		while (++i < 3)
			ft_printf("args[%d] = %d\n", i, temp->args[i]);
		ft_printf("carry = %d\n", temp->carry);
		ft_printf("delay = %d\n", temp->delay);
		ft_printf("live_incycle = %d\n", temp->live_incycle);
		ft_printf(ANSI_B_GREEN"REGS:\n"ANSI_RESET);
		i = -1;
		while (++i < REG_NUMBER)
			ft_printf("regs[%d] = %d\n", i, temp->regs[i]);
		ft_printf("\n\n\n");
		temp = temp->next;
	}
}

void print_arena(int pos, int print_op, int op_pos, int size)
{
	int 	i;
	int 	j;
	int 	k;
	int     row;

	i = 0;
	row = 0;
	k = -1;
    if (vm.dump_cycle == vm.cycles_all && DEBUG)
        ft_printf("vm.cycles_all = %d\n\n", vm.cycles_all);
	ft_printf("0x");
	while (i < MEM_SIZE)
	{
		j = -1;
		ft_printf("%#.4x : ", row * 32);
		while (++j < 32)
		{
		    if (DEBUG)
            {
                if (print_op && i >= op_pos && i < op_pos + size)
                    ft_printf(ANSI_B_RED"%02x "ANSI_RESET, vm.arena[i]);
                else if (i >= pos && ++k < 4)
                    ft_printf(ANSI_B_GREEN"%02x "ANSI_RESET, vm.arena[i]);
                else
                    ft_printf("%02x ", vm.arena[i]);
            }
		    else
                ft_printf("%02x ", vm.arena[i]);
			++i;
		}
		ft_printf("\n");
		++row;
	}
	if (vm.dump_cycle == vm.cycles_all)
	    exit(0);
}
