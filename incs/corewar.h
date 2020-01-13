#ifndef COREWAR_H
# define COREWAR_H

#include		"op.h"
#include		<uchar.h>
#include		<unistd.h>

typedef struct			s_player
{
	int					id;
	char				*name;
	char				*comment;
	char32_t			*code;
	int 				code_size;
	short				is_alive;
	ssize_t				lives_all;
	ssize_t				lives_last;
	ssize_t				lives_current;
	struct s_player		*next;
}						t_player;

typedef struct			s_process
{
    int					proc_id;
    int					player_id;
	int					pos;
    int					pc;
    int					op;
    int					args[3];
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
	t_player			players[MAX_PLAYERS];
	char32_t			arena[MEM_SIZE];
	size_t				cycles_all;
	ssize_t 			cycle_current;
	size_t				lives_in_round;
	int					cycles_to_die;
	int					rounds_all;
}						t_game;

#endif