#ifndef COREWAR_H
# define COREWAR_H

#include		<stdio.h>
#include		<unistd.h>
#include		"op.h"
#include		"../libft/libft.h"

# define T_REG_ARG		1
# define T_DIR_ARG		10
# define T_IND_ARG		11

# define SET_BIT(byte, mask) byte |= mask

# define GET_BIT(byte, mask) byte & mask

typedef struct			s_player
{
	int					id;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	char				code[CHAMP_MAX_SIZE];
	int 				code_size;
	short				is_alive;
	ssize_t				lives_all;
	ssize_t				lives_last;
	ssize_t				lives_current;
}						t_player;

typedef struct			s_process
{
    int					proc_id;
    int					player_id;
	int					pos;
    int					pc;
    int					op;
	unsigned char		op_args;
    int					args_value[3];
    unsigned int		args[4];
    int					has_args_code;
    int 				change_carry;
	int					carry;
	int					delay;
	int					live_incycle;
    int					regs[REG_NUMBER];
	struct s_process	*next;
}						t_process;

typedef struct			s_game
{
	t_process 			*processes;
	t_player			*last_alive;
	t_player			players_temp[MAX_PLAYERS];
	t_player			players[MAX_PLAYERS + 1];
	int 				players_sum;
	unsigned char		arena[MEM_SIZE];
	unsigned char		arena_id[MEM_SIZE];
	size_t				cycles_all;
	ssize_t 			cycle_current;
	size_t				lives_in_round;
	int					cycles_to_die;
	int					cycles_to_die_last;
	int					cycles_to_die_updated;
	int					rounds_all;
	int 				checks;
	void 				(*ops[17]) (t_process *proc);
}						t_game;

	t_game				vm;

/*
** -------------------------- Parse args -------------------------------
*/

int						check_args(int ac, char **ag);
int						print_usage(int code, int usage);
int						create_players(char **argv);
int						is_set(int number, int max);
void					set_id(int player_k);

/*
** -------------------------- Parse players -------------------------------
*/

int						check_magic(int fd, int player_k);
int						check_name(int fd, int player_k);
int						check_comment(int fd, int player_k);
int						check_exec_size(int fd, int player_k);
int						check_code(int fd, int player_k);

/*
** -------------------------- Initialization -------------------------------
*/

int						init_game(void);
void					print_process(void);
void					print_arena(void);
t_process				*create_process(int n_player, int position);
void					del_process(t_process *proc);

/*
** -------------------------- Battle -------------------------------
*/

int						battle_check(void);
void					set_args_code(t_process *proc);
int						check_op_args(t_process *proc);
int 					parse_args_values(t_process *proc);
int 					check_regs(t_process *proc);
int 					move_process(t_process *proc);

/*
** -------------------------- Operations -------------------------------
*/

void					live_op(t_process *proc);
void					ld_op(t_process *proc);
void					st_op(t_process *proc);
void					add_op(t_process *proc);
void					sub_op(t_process *proc);
void					and_op(t_process *proc);
void					or_op(t_process *proc);
void					xor_op(t_process *proc);
void					zjmp_op(t_process *proc);
void					ldi_op(t_process *proc);
void					sti_op(t_process *proc);
void					fork_op(t_process *proc);
void					lld_op(t_process *proc);
void					lldi_op(t_process *proc);
void					lfork_op(t_process *proc);
void					aff_op(t_process *proc);

typedef struct			s_op
{
	char				*op_code;
	int					argc;
	int					args_types[3];
	int					op_id;
	int					op_delay;
	char				*op_name;
	int					carry;
	int					dir_size;
	void 				(*ops[17]) (t_process *proc);
}						t_op;

t_op					op_tab[17] =
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
						0},

				{0,
						0,
						{0},
						0,
						0,
						0,
						0,
						0}
		};


#endif