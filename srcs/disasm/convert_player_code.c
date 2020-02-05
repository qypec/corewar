/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_player_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:34:54 by yquaro            #+#    #+#             */
/*   Updated: 2020/02/05 15:07:30 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dis_asm.h"
#include "corewar.h"

# define OP_TAB_SIZE 17
# define MAX_NUMOF_ARGS 3
# define SIZE_OF_ARGTAB 4

# define POSITION(i) ((i == 0))

t_argtab			g_arg[SIZE_OF_ARGTAB] =
{
	{T_REG, 'r', 0b01},
	{T_DIR, DIRECT_CHAR, 0b10},
	{T_IND, '\0', 0b11},
	{0, 0, 0b00}
};

t_optab				g_op[OP_TAB_SIZE] =
{
	{0x01, "live", 1, 4, {T_DIR, 0, 0}},
	{0x02, "ld", 2, 4, {T_DIR | T_IND, T_REG, 0}},
	{0x03, "st", 2, 4, {T_REG, T_IND | T_REG, 0}},
	{0x04, "add", 3, 4, {T_REG, T_REG, T_REG}},
	{0x05, "sub", 3, 4, {T_REG, T_REG, T_REG}},
	{0x06, "and", 3, 4, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}},
	{0x07, "or", 3, 4, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}},
	{0x08, "xor", 3, 4, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}},
	{0x09, "zjmp", 1, 2, {T_DIR, 0, 0}},
	{0x0a, "ldi", 3, 2, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}},
	{0x0b, "sti", 3, 2, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}},
	{0x0c, "fork", 1, 2, {T_DIR, 0, 0}},
	{0x0d, "lld", 2, 4, {T_DIR | T_IND, T_REG, 0}},
	{0x0e, "lldi", 3, 2, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}},
	{0x0f, "lfork", 1, 2, {T_DIR, 0, 0}},
	{0x10, "aff", 1, 4, {T_REG, 0, 0}},
	{0x0, NULL, 0, 0, {0, 0, 0}}
};

static void			fill_args_from_code(int *arg_type, uint8_t num, t_optab tab)
{
	size_t			i;

	i = 0;
	while (i < tab.numof_args)
	{
		/*if ((*/arg_type[i] = get_arg_type(num, i);//) != tab.args[i])
	//		error(ERR_INVALID_CODE);
		i++;
	}
}

static char			get_arg_char(int arg_type)
{
	size_t			i;

	i = 0;
	while (i < SIZE_OF_ARGTAB)
	{
		
		if (g_arg[i].type == arg_type)
			return (g_arg[i].ch);
		i++;
	}
	return ('\0');
}

static void			interpret_args(t_parser *parser, size_t *pos, t_optab tab, int fd)
{
	size_t			i;
	int				arg_type[MAX_NUMOF_ARGS];

	if (tab.numof_args == 1)
		arg_type[0] = tab.args[0];
	else
		fill_args_from_code((int *)arg_type, parser->code[(*pos)++], tab);
	i = 0;
	while (i < tab.numof_args)
	{
		// if (arg_type[i] != tab.args[i])
			// error(ERR_INVALID_CODE);
		dprintf(fd, "%c%d", get_arg_char(arg_type[i]), bytecode_to_int(parser, pos, tab, arg_type[i]));
		i++;
		if (i != tab.numof_args)
			dprintf(fd, "%c ", SEPARATOR_CHAR);
	}
	dprintf(fd, "\n");
}

static size_t		get_tab_index(uint8_t num)
{
	size_t			i;

	i = 0;
	while (i < OP_TAB_SIZE)
	{
		if (g_op[i].code == num)
			return (i);
		i++;
	}
	return (OP_TAB_SIZE - 1);
}

void				convert_player_code(t_parser *parser, int fd)
{
	size_t			pos;
	size_t			tab_index;

	pos = 0;
	while (pos < parser->code_size)
	{
		if ((tab_index = get_tab_index(parser->code[pos++])) == OP_TAB_SIZE - 1)
			error(ERR_INVALID_FILE);
		dprintf(fd, "%s ", g_op[tab_index].name);
		interpret_args(parser, &pos, g_op[tab_index], fd);
	}
}
