#ifndef COREWAR_H
# define COREWAR_H

#include		<stdio.h>
#include		<unistd.h>
#include		"op.h"
#include		"../libft/libft.h"

# DEFINE

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
    int					args[3];
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
	size_t				cycles_all;
	ssize_t 			cycle_current;
	size_t				lives_in_round;
	int					cycles_to_die;
	int					cycles_to_die_last;
	int					cycles_to_die_updated;
	int					rounds_all;
	int 				checks;
	void 				*ops[17];
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

/*
** -------------------------- Battle -------------------------------
*/

int						battle_check(void);

#endif