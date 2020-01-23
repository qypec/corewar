#ifndef VISU_H
# define VISU_H

#include <ncurses.h>
#include <sys/ioctl.h>

# define MAINWIN_LINES 50
# define MAINWIN_COLS 140
# define RUNNING_INFO_WIN_LINES 50
# define RUNNING_INFO_WIN_COLS 50
# define INFO_WIN_LINES 10
# define INFO_WIN_COLS 140

typedef struct		s_windows
{
	WINDOW			*arena;
	WINDOW			*runing_info;
	WINDOW			*user_info;
}					t_windows;

t_windows               *init_visu(void);
void					delete_windows(t_windows **win);

#endif