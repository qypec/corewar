/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:21:07 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/23 18:49:08 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		print_usage(int code, int usage)
{
	if (code == -1)
		ft_printf("%s\n", ANSI_B_RED"Only files with the extension .cor are accepted!"ANSI_RESET);
	if (code == -2)
		ft_printf("%s\n", ANSI_B_RED"The -n (1 - MAX_PLAYERS) flag overrides the player's sequence number, "
						  "set before the player's file. "ANSI_RESET);
	if (code == -3)
		ft_printf("%s\n", ANSI_B_RED"The-d CYCLE flag prints the state of the arena on the specified cycle.\n"
						  "The CYCLE value can only be a positive natural number\n"ANSI_RESET);
	if (code == -4)
		ft_printf("%s %d\n", ANSI_B_RED"Max number of players is:", MAX_PLAYERS, ANSI_RESET);
	if (code == -5)
		ft_printf("%s\n", ANSI_B_RED"Duplicates in flags"ANSI_RESET);
	if (code == -6)
		ft_printf("%s\n", ANSI_B_RED"You pass flag n as the last argument!"ANSI_RESET);
	if (code == -7)
		ft_printf("%s\n", ANSI_B_RED"Flag value is not a number!"ANSI_RESET);
	if (usage)
		standart_usage();
	return (0);
}

int		check_flags(int i, int ac, char **ag)
{
	int value;

	if (i + 1 == ac)
		return (print_usage(-6, 1));
	if (!ft_isnum(ag[i + 1]))
		return (print_usage(-7, 1));
	value = ft_atoi(ag[i + 1]);
	if (ag[i][1] == 'n')
        if (!check_n(value))
            return (0);
	else if (ag[i][1] == 'd')
	    if (!(check_d(ag, value, i)))
            return (0);
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
		++vm.players_sum;
	else
		return (print_usage(-1, 1));
	return (1);
}

int		check_args(int ac, char **ag)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (ag[i][0] == '-')
		{
			if ((i + 1 < ac && ag[i + 1][0] == '-') ||
			(i + 2 < ac && ag[i + 2][0] == '-'))
				return (print_usage(-5, 1));
			if (!check_flags(i, ac, ag))
				return (0);
			if ((i + 2) < ac)
				i += 2;
			else
				return (print_usage(-2, 1));
		}
		if (!check_extension(i, ag))
			return (0);
		if (vm.players_sum > MAX_PLAYERS)
			return (print_usage(-4, 1));
	}
	return (1);
}
