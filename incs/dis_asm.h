/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_asm.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:34:53 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/03 18:31:35 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIS_ASM_H
# define DIS_ASM_H

# include <stdint.h>

# define ERR_READ_FILE "error: read file"
# define ERR_INVALID_FILE "error: invalid file"
# define ERR_INVALID_MAGIC_HEADER "error: invalid magic header"
# define ERR_NO_NULL "error: no null"
# define ERR_INVALID_CODE_SIZE "error: invalid code size"
# define ERR_ALLOCATE "error: allocate"
# define ERR_INVALID_FILE_NAME "error: invalid file name"
# define ERR_CREATE_FILE "error: create file"

# define SIZE_OF_MAGIC 4

# define FILE_EXTENSION ".asm"


typedef struct			s_parser
{
	int					fd;
	char				*name;
	char				*comment;
	int32_t				code_size;
	uint8_t				*code;
}						t_parser;

void					error(const char *error_msg);

t_parser                *init_parser(int fd);
void					delete_parser(t_parser **parser);

void                    parse_bytecode(t_parser *parser);
int						init_asm_file(const char *filename);


#endif