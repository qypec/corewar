/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:47:07 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/25 21:09:15 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void 		redistribution(void)
{
	int 	i;

	i = -1;
	while (++i < vm.players_sum)
		vm.players[vm.players_temp[i].id] = vm.players_temp[i];
}

int		is_set(int number, int max)
{
	int i;

	i = -1;
	while (++i < max)
		if (vm.players_temp[i].id == number)
			return (1);
	return (0);
}

void	set_id(int player_k)
{
	int i;

	i = 1;
	while (is_set(i, vm.players_sum))
		++i;
	vm.players_temp[player_k].id = i;
}

int		load_player(char *player_filename, int player_k)
{
	int fd;

	fd = 0;
	if (vm.players_temp[player_k].id == 0)
		set_id(player_k);
	if ((fd = open(player_filename, O_RDONLY)) < 1)
		return (0);
	if (!check_magic(fd, player_k))
		return (0);
	if (!check_name(fd, player_k)) //check NULL
		return (0);
	if (!check_exec_size(fd, player_k))
		return (0);
	if (!check_comment(fd, player_k)) //check NULL
		return (0);
	if (!check_code(fd, player_k))
		return (0);
	close(fd);
	return (1);
}

int create_players(char **argv)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (argv[++i])
	{
		if (ft_strstr(argv[i], ".cor"))
		{
			if (!load_player(argv[i], k))
				return (0);
			++k;
		}
	}
	redistribution();
	return (1);
}