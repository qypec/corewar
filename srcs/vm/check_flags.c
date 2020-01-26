#include "../../incs/corewar.h"

int check_n(int value)
{
    if (value > MAX_PLAYERS || value <= 0)
        return (print_usage(-2, 1));
    else
    {
        if (is_set(value, MAX_PLAYERS))
            return (print_usage(-5, 1));
        vm.players_temp[vm.players_sum].id =
                (!is_set(value, MAX_PLAYERS)) ? value : 0;
    }
    return (1);
}

int check_d(char **av, int value, int i)
{
    vm.dump_64 = (ft_strequ(av[i], "dump")) ? 0 : 1;
    if(av[i + 1] <= 0)
        return (print_usage(-3, 0));
    else
        vm.dump_cycle = value;
    return (1);
}

//int check_s(int ac, char **av, int value);
//int check_v(int ac, char **av);
//int check_a(int ac, char **av);