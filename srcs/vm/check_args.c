/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:21:07 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/15 18:23:50 by vgerold-         ###   ########.fr       */
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

//int 	parse_vm_flags(char **ag)
//{
//	int i;
//	i = 0;
//	while (ag[++])
//}

int 	check_extension(char *file)
{
	int	i;

	i = -1;
	while (file[++i] != '.')
		;
	if (file[i] == '.' && ft_strequ(file + i, ".cor"))
		return (1);
	else
		return(0);
}

int 	check_args(int ac, char **ag)
{
	int i;
	int j;
	int player;

	i = 0;
	player = 0;
	while (ag[++i] && i <= ac)
	{
		j = 0;
		if (ag[i][0] == '-')
			++i;
		while (ag[i][++j] != '.')
			;
		if (ag[i][j] != '.')
			print_usage(-1, 1);
		else if (ag[i][j] == '.' && ft_strequ(ag[i] + j, ".cor")
			&& check_extension(ag[i]))
			ft_printf("%s %d\n", "player",++player);
		else
			print_usage(-1, 1);
		(player > MAX_PLAYERS) ? print_usage(-4, 1) : 0;
	}
	return (0);
}