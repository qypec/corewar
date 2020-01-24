#ifndef VISU_H
# define VISU_H

#include <ncurses.h>

# define RUNNING_INFO "Running info"

# define BUTTON_EXIT "Exit - \'Esc\'"

# define WIN_ARENA_LINES (visu->tty_lines * 0.75)
# define WIN_ARENA_COLS (visu->tty_cols * 0.75)
# define WIN_INFO_LINES (visu->tty_lines * 0.75)
# define WIN_INFO_COLS (visu->tty_cols * 0.25)
# define WIN_HELP_LINES (visu->tty_lines * 0.25)
# define WIN_HELP_COLS (visu->tty_cols * 0.75)

typedef struct		s_visu
{
	WINDOW			*win_arena;
	WINDOW			*win_info;
	WINDOW			*win_help;
	size_t			tty_lines;
	size_t			tty_cols;
}					t_visu;

t_visu					*init_visu(void);
void					delete_visu(t_visu **visu);

#endif
