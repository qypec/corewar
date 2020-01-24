#ifndef COREWAR_H
# define COREWAR_H

#include		<stdio.h>
#include		<unistd.h>
#include		<inttypes.h>
#include		"op.h"
#include		"../libft/libft.h"
#include		"visu.h"

# define DEBUG 0

typedef struct			s_player
{
	int					id;
	int					color;
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
    int					args_value[3];
    unsigned int		args[4];
	int					carry;
	int					delay;
	int					live_incycle;
    int					regs[REG_NUMBER];
	struct s_process	*next;
}						t_process;

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

int						battle(void);
void					battle_check(void);
void					process_args_code(t_process *proc);
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

int						get_int32_from_mem(int position, int drop_bit);
int						get_int16_from_mem(int position);

typedef struct			s_game
{
	t_visu				*visu;
	int 				process_count;
	t_process 			*processes;
	t_player			*last_alive;
	t_player			players_temp[MAX_PLAYERS];
	t_player			players[MAX_PLAYERS + 1];
	int 				players_sum;
	unsigned char		arena[MEM_SIZE];
	int					arena_id[MEM_SIZE];
	size_t				cycles_all;
	ssize_t 			cycle_current;
	size_t				lives_in_round;
	int					cycles_to_die;
	int					cycles_to_die_last;
	int					cycles_to_die_not_updated;
	int 				checks;
	int 				dump_cycle;
}						t_game;

t_game					vm;

#endif