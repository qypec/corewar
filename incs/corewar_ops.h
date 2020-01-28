/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_ops.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:26:07 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/22 18:07:09 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_COREWAR_OPS_H
#define COREWAR_COREWAR_OPS_H

#include "corewar.h"

typedef struct			s_op
{
	char				*op_code;
	int					argc;
	int					args_types[12];
	int					op_id;
	int					op_delay;
	char				*op_name;
	int					has_carry;
	int					dir_size;
	void 				(*operations)(t_process *proc);
	int 				has_args_code;
}						t_op;

static t_op					op_tab[17] =
		{
				{"live",
						1,
						{T_DIR},
						1,
						10,
						"alive",
						0,
						0,
						live_op,
						0},

				{"ld",
						2,
						{T_DIR, T_IND, 0, T_REG},
						2,
						5,
						"load",
						1,
						0,
						ld_op,
						1},

				{"st",
						2,
						{T_REG, 0, 0, T_IND, T_REG},
						3,
						5,
						"store",
						1,
						0,
						st_op,
						1},

				{"add",
						3,
						{T_REG, 0, 0, T_REG, 0, 0, T_REG, 0, 0},
						4,
						10,
						"addition",
						1,
						0,
						add_op,
						1},

				{"sub",
						3,
						{T_REG, 0, 0, T_REG, 0, 0, T_REG, 0, 0},
						5,
						10,
						"soustraction",
						1,
						0,
						sub_op,
						1},

				{"and",
						3,
						{T_REG, T_DIR, T_IND, T_REG, T_IND, T_DIR, T_REG},
						6,
						6,
						"and",
						1,
						0,
						and_op,
						1},

				{"or",
						3,
						{T_REG, T_IND, T_DIR, T_REG, T_IND, T_DIR, T_REG},
						7,
						6,
						"or",
						1,
						0,
						or_op,
						1},

				{"xor",
						3,
						{T_REG, T_IND, T_DIR, T_REG, T_IND, T_DIR, T_REG},
						8,
						6,
						"xor",
						1,
						0,
						xor_op,
						1},

				{"zjmp",
						1,
						{T_DIR},
						9,
						20,
						"jump if zero",
						0,
						1,
						zjmp_op,
						0},

				{"ldi",
						3,
						{T_REG, T_DIR, T_IND, T_DIR, T_REG,	0, T_REG},
						10,
						25,
						"load",
						1,
						1,
						ldi_op,
						1},

				{"sti",
						3,
						{T_REG, 0, 0, T_REG, T_DIR, T_IND,T_DIR, T_REG},
						11,
						25,
						"store",
						1,
						1,
						sti_op,
						1},

				{"fork",
						1,
						{T_DIR},
						12,
						800,
						"fork",
						0,
						1,
						fork_op,
						0},

				{"lld",
						2,
						{T_DIR, T_IND, 0, T_REG},
						13,
						10,
						"load",
						1,
						0,
						lld_op,
						1},

				{"lldi",
						3,
						{T_REG, T_DIR, T_IND, T_DIR, T_REG, 0, T_REG},
						14,
						50,
						"load",
						1,
						1,
						lldi_op,
						1},

				{"lfork",
						1,
						{T_DIR},
						15,
						1000,
						"long fork",
						0,
						1,
						lfork_op,
						0},

				{"aff",
						1,
						{T_REG},
						16,
						2,
						"aff",
						1,
						0,
						aff_op,
						1},

                {"null",
                        0,
                        {},
                        17,
                        0,
                        "null",
                        0,
                        0,
                        NULL,
                        0}
		};

#endif
