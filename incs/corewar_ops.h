/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_ops.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:26:07 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/21 18:26:07 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_COREWAR_OPS_H
#define COREWAR_COREWAR_OPS_H

#include "corewar.h"

typedef struct			s_op
{
	char				*op_code;
	int					argc;
	int					args_types[3];
	int					op_id;
	int					op_delay;
	char				*op_name;
	int					has_carry;
	int					dir_size;
	void 				(*operations)(t_process *proc);
}						t_op;

static t_op					op_tab[16] =
		{
				{"live",
						1,
						{T_DIR},
						1,
						10,
						"alive",
						0,
						0,
						live_op},

				{"ld",
						2,
						{T_DIR | T_IND, T_REG},
						2,
						5,
						"load",
						1,
						0,
						ld_op},

				{"st",
						2,
						{T_REG,T_IND | T_REG},
						3,
						5,
						"store",
						1,
						0,
						NULL},

				{"add",
						3,
						{T_REG,	T_REG, T_REG},
						4,
						10,
						"addition",
						1,
						0,
						NULL},

				{"sub",
						3,
						{T_REG,	T_REG, T_REG},
						5,
						10,
						"soustraction",
						1,
						0},

				{"and",
						3,
						{T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
						6,
						6,
						"and",
						1,
						0},

				{"or",
						3,
						{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
						7,
						6,
						"or",
						1,
						0},

				{"xor",
						3,
						{T_REG | T_IND | T_DIR,T_REG | T_IND | T_DIR,	T_REG},
						8,
						6,
						"xor",
						1,
						0},

				{"zjmp",
						1,
						{T_DIR},
						9,
						20,
						"jump if zero",
						0,
						1,
						zjmp_op},

				{"ldi",
						3,
						{T_REG | T_DIR | T_IND,T_DIR | T_REG,	T_REG},
						10,
						25,
						"load index",
						1,
						1},

				{"sti",
						3,
						{T_REG,
								T_REG | T_DIR | T_IND,T_DIR | T_REG},
						11,
						25,
						"store index",
						1,
						1},

				{"fork",
						1,
						{T_DIR},
						12,
						800,
						"fork",
						0,
						1},

				{"lld",
						2,
						{T_DIR | T_IND, T_REG},
						13,
						10,
						"long load",
						1,
						0},

				{"lldi",
						3,
						{T_REG | T_DIR | T_IND,T_DIR | T_REG, T_REG},
						14,
						50,
						"long load index",
						1,
						1},

				{"lfork",
						1,
						{T_DIR},
						15,
						1000,
						"long fork",
						0,
						1},

				{"aff",
						1,
						{T_REG},
						16,
						2,
						"aff",
						1,
						0}
		};

#endif //COREWAR_COREWAR_OPS_H
