/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:33:04 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/04 21:35:24 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dis_asm.h"
#include "corewar.h"

// # define IN_WIP

static void				usage(void)
{
	ft_putendl("./diasm 'filename'");
	exit(0);
}

int						main(int argc, char **argv)
{
	int					fd_cor;
	int					fd_asm;
	t_parser			*parser;
	
	if (argc == 1)
		usage();
	if ((fd_cor = open(argv[1], O_RDONLY)) == -1)
		exit(-1);
	parser = init_parser(fd_cor);
	parse_bytecode(parser);
#ifdef IN_WIP
	fd_asm = init_asm_file(argv[0]);
#endif
	fd_asm = 0; //delete
	dprintf(fd_asm, "%s %s\n%s %s\n\n", NAME_CMD_STRING, parser->name, \
		COMMENT_CMD_STRING, parser->comment); 
	convert_player_code(parser, fd_asm);
	close(fd_asm);
	close(fd_cor);
	delete_parser(&parser);
}
