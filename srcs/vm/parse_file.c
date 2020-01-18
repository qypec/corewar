/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:55:56 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/16 19:55:57 by ergottli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/corewar.h"

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
	uint16_t 		buf;

	if (read(fd, &buf, 2) < 2)
		return (0);
	if (buf > CHAMP_MAX_SIZE)
		return (0);
	printf("exec_size - %d\n", buf);
	vm.players[player_k].code_size = buf;
	return (1);
}

int check_code(int fd, int player_k)
{
	int ret;
	char buf[CHAMP_MAX_SIZE + 1];

	ret = -1;
	printf("4.1\n");
	if ((ret = read(fd, &buf, CHAMP_MAX_SIZE + 1)) < 1)
		return (0);
	printf("4.2\n");
	printf("code_size - %d  ret - %d\n", vm.players[player_k].code_size, ret);
	if (ret != vm.players[player_k].code_size)
		return (0);
	printf("4.3\n");
	ft_memcpy(vm.players[player_k].code, buf, vm.players[player_k].code_size);
	return (1);
}

int check_name(int fd, int player_k)
{
	int			ret;
	uint16_t	*buf;

	ret = -1;
	if ((ret = read(fd, &(vm.players[player_k].name), PROG_NAME_LENGTH)) < PROG_NAME_LENGTH)
		return (0);
	vm.players[player_k].name[ret] = '\0';
	if (ft_strlen(vm.players[player_k].name) < 1)
		return (0);
	if (read(fd, &buf, 2) < 2)
		return (0);
	if (buf != 0)
		return (0);
	printf("name - %s\n", vm.players[player_k].name);
	return (1);
}

int check_comment(int fd, int player_k)
{
	int			ret;
	uint16_t	*buf;

	ret = -1;
	if ((ret = read(fd, &(vm.players[player_k].comment), COMMENT_LENGTH)) < COMMENT_LENGTH)
		return (0);
	vm.players[player_k].comment[ret] = '\0';
	if (read(fd, &buf, 2) < 2)
		return (0);
	if (buf != 0)
		return (0);
	printf("comment - %s\n", vm.players[player_k].comment);
	return (1);
}