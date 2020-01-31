/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:04:07 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/31 19:32:41 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dis_asm.h"
#include "corewar.h"

t_parser                *init_parser(int fd)
{
    t_parser            *parser;

    if ((parser = (t_parser *)malloc(sizeof(t_parser))) == NULL)
        exit(-1);
    parser->fd = fd;
    parser->name = NULL;
    parser->comment = NULL;
    parser->code_size = 0;
    parser->code = 0;
    return (parser);
}

void					delete_parser(t_parser **parser)
{
	(*parser)->fd = 0;
	ft_strdel(&((*parser)->name));
	ft_strdel(&((*parser)->comment));
	(*parser)->code_size = 0;
	(*parser)->code = 0;
	free(*parser);
	*parser = NULL;
}