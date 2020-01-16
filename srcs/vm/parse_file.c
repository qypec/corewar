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
