/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:11:37 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/31 20:31:20 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dis_asm.h"
#include "corewar.h"

// # define DEBUG_DISASM

static int32_t			parse_int32(int fd)
{
    int                 ret;
    int32_t             magic;
    unsigned char       buffer[SIZE_OF_MAGIC + 1];
    size_t              i;
    
    if ((ret = read(fd, &buffer, SIZE_OF_MAGIC)) == -1)
        error(ERR_READ_FILE);
	if (ret < SIZE_OF_MAGIC)
		error(ERR_INVALID_FILE);
    magic = 0x0;
    i = 0;
    while (i < SIZE_OF_MAGIC)
    {
        magic <<= 8;
        magic |= buffer[i];
        i++;
    }
    return (magic);
}

static char             *parse_str(int fd, size_t size)
{
    int                 ret;
    unsigned char       buffer[size + 1];
    size_t              i;

    if ((ret = read(fd, &buffer, size)) == -1)
        error(ERR_READ_FILE);
	if (ret < size)
		error(ERR_INVALID_FILE);
    return (ft_strdup((const char *)buffer));
}

static uint8_t			*parse_code(int fd, int32_t size)
{
	int					ret;
	uint8_t				*buffer;
	uint8_t				last_byte;

	if (!(buffer = (uint8_t *)ft_memalloc(size)))
		error(ERR_ALLOCATE);
	ret = read(fd, buffer, size);
	if (ret == -1)
		error(ERR_READ_FILE);
	if (ret < (int)size || read(fd, &last_byte, 1) != 0)
		error(ERR_INVALID_FILE);
	return (buffer);
}

void                    parse_bytecode(t_parser *parser)
{
	if ((parse_int32(parser->fd)) != COREWAR_EXEC_MAGIC)
		error(ERR_INVALID_FILE);
    parser->name = parse_str(parser->fd, PROG_NAME_LENGTH);
# ifdef DEBUG_DISASM
    ft_putendl(parser->name);
#endif
	if ((parse_int32(parser->fd)) != 0)
		error(ERR_NO_NULL);
    if ((parser->code_size = parse_int32(parser->fd)) < 0)
		error(ERR_INVALID_CODE_SIZE);
# ifdef DEBUG_DISASM
	ft_printf("%d\n", parser->code_size);
#endif
    parser->comment = parse_str(parser->fd, COMMENT_LENGTH);
# ifdef DEBUG_DISASM
    ft_putendl(parser->comment);
#endif
	if ((parse_int32(parser->fd)) != 0)
		error(ERR_NO_NULL);
	parser->code = parse_code(parser->fd, parser->code_size);
}