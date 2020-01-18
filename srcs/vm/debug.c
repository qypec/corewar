
#include "../../incs/corewar.h"

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

void		print_arena(void)
{
	int 	i;
	int 	j;

	i = 0;
	ft_printf("\n\n0x");;
	while (i < MEM_SIZE)
	{
		j = -1;
		ft_printf("%#.4X : ", i / 32);
		while (++j < 32)
		{
			ft_printf("%02x ", vm.arena[i]);
			++i;
		}
		ft_printf("\n");
	}
}
