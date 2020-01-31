/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:33:04 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/31 16:13:03 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dis_asm.h"
#include "corewar.h"

static void				usage(void)
{
	ft_putendl("./diasm 'filename'");
	exit(0);
}

int						main(int argc, char **argv)
{
	int					fd;
	t_parser			*parser;
	
	if (argc == 1)
		usage();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit(-1);
	parser = init_parser(fd);
	parse_bytecode(parser);
	close(fd);
	delete_parser(&parser);
}
