/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:55:56 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/23 19:21:37 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	check_magic(int fd, int player_k)
{
	unsigned char	buf[4];

	if (read(fd, &buf[3], 1) < 1)
		return (0);
	if (read(fd, &buf[2], 1) < 1)
		return (0);
	if (read(fd, &buf[1], 1) < 1)
		return (0);
	if (read(fd, &buf[0], 1) < 1)
		return (0);
	if (*(unsigned int*)buf != COREWAR_EXEC_MAGIC)
		return (0);
	return (1);
}

int check_exec_size(int fd, int player_k)
{
	char 			buf[4];

	if (read(fd, &buf[3], 1) < 1)
		return (0);
	if (read(fd, &buf[2], 1) < 1)
		return (0);
	if (read(fd, &buf[1], 1) < 1)
		return (0);
	if (read(fd, &buf[0], 1) < 1)
		return (0);
	// printf("exec_size - %d\n", *(int*)buf);
	vm.players_temp[player_k].code_size = *(int*)buf;
	return (1);
}

int check_code(int fd, int player_k)
{
	int ret;
	char buf[CHAMP_MAX_SIZE + 1];

	ret = -1;
	// printf("4.1\n");
	if ((ret = read(fd, &buf, CHAMP_MAX_SIZE + 1)) < 1)
		return (0);
	// printf("4.2\n");
	// printf("code_size - %d  ret - %d\n", vm.players_temp[player_k].code_size, ret);
	if (ret != vm.players_temp[player_k].code_size)
		return (0);
	// printf("4.3\n");
	ft_memcpy(vm.players_temp[player_k].code, buf, vm.players_temp[player_k].code_size);
	return (1);
}

int check_name(int fd, int player_k)
{
	int			ret;
	int			buf;

	if ((ret = read(fd, &(vm.players_temp[player_k].name), PROG_NAME_LENGTH)) < PROG_NAME_LENGTH)
		return (0);
	vm.players_temp[player_k].name[ret] = '\0';
	if (ft_strlen(vm.players_temp[player_k].name) < 1)
		return (0);
	if (read(fd, &buf, 4) < 4)
		return (0);
	if (buf != 0)
		return (0);
	// printf("name - %s after name mem - %d\n", vm.players_temp[player_k].name, buf);
	return (1);
}

int check_comment(int fd, int player_k)
{
	int			ret;
	int			buf;

	if ((ret = read(fd, &(vm.players_temp[player_k].comment), COMMENT_LENGTH)) < COMMENT_LENGTH)
		return (0);
	vm.players_temp[player_k].comment[ret] = '\0';
	if (read(fd, &buf, 4) < 4)
		return (0);
	if (buf != 0)
		return (0);
	return (1);
}