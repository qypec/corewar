/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:21:07 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/16 17:09:08 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

int print_usage(int code, int usage)
{
	if (!code)
		ft_printf("%s\n", ANSI_B_RED"You didn't pass the program arguments!"ANSI_RESET);
	if (code == -1)
		ft_printf("%s\n", ANSI_B_RED"Only files with the extension .cor are accepted!"ANSI_RESET);
	if (code == -2)
		ft_printf("%s\n", ANSI_B_RED"The-n (1 - MAX_PLAYERS) flag overrides the player's sequence number,"
						  "set before the player's file."ANSI_RESET);
	if (code == -3)
		ft_printf("%s\n", ANSI_B_RED"The-d CYCLE flag prints the state of the arena on the specified cycle.\n"
						  "The CYCLE value can only be a positive natural number\n"ANSI_RESET);
	if (code == -4)
		ft_printf("%s %d\n", ANSI_B_RED"Max number of players is:", MAX_PLAYERS, ANSI_RESET);
	if (usage)
		ft_printf("%s %d\n", ANSI_B_GREEN"USAGE:\n"ANSI_RESET "The virtual machine ./corewar accepts player files as arguments\n"
						 "in the form of \"some_player_name.cor\" separated by a space:\n"
						 "./corewar player1.cor player2.cor player3.cor\n"
						 ANSI_B_GREEN"Max number of players is:", MAX_PLAYERS, ANSI_RESET);
	return (0);
}

int check_flags(int ac, char **ag)
{
	if (!ft_isnum(ag[ac + 1]))
		return (0);
	if (ag[ac][1] == 'n')
	{
		if (ft_atoi(ag[ac + 1]) > MAX_PLAYERS || ag[ac + 1] <= 0)
			return (0);
		else
			vm.players[vm.players_sum].id = ft_atoi(ag[ac + 1]);
	}
	else if (ag[ac][1] == 'd')
		if (ft_atoi(ag[ac + 1]) > CYCLE_TO_DIE || ag[ac + 1] <= 0)
			return (print_usage(-3, 0));
	return (1);
}

int		check_extension(int i, char **file)
{
	int j;

	j = 0;
	while (file[i][++j] != '.')
		;
	if (file[i][j] != '.')
		return (print_usage(-1, 1));
	if (file[i][j] == '.' && ft_strequ(file[i] + j, ".cor"))
		ft_printf("%s %d %s\n", "player", ++vm.players_sum, "checked...");
	else
		return (print_usage(-1, 1));
	return(1);
}

int 	check_args(int ac, char **ag)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (ag[i][0] == '-')
		{
			if (!check_flags(i, ag))
				return (print_usage(-2, 1));;
			i += 2;
		}
		if (!check_extension(i, ag))
			return (0);
		if (vm.players_sum > MAX_PLAYERS)
			return (print_usage(-4, 1));
	}
	return (1);
}