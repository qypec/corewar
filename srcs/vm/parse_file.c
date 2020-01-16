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

int check_magic(int fd, int player_k)
{
	int			*i;
	char			buf[5];
	unsigned char 	*temp;

	if (read(fd, &buf, 4) < 1)
		return (0);
	printf("%u\n", COREWAR_EXEC_MAGIC);
	i = (int*)buf;
//	i[0] = i[0] >> 8u;
	printf("%u\n", i[0]);
	printf("%lu\n", sizeof(COREWAR_EXEC_MAGIC));
	printf("%lu\n", sizeof(i[0]));
	if (i[0] != COREWAR_EXEC_MAGIC)
		return (0);

	return (1);
}