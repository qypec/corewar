/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:55:13 by yquaro            #+#    #+#             */
/*   Updated: 2020/01/27 19:08:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define NUM_OF_COLUMN (column)

# define MAXLEN_OF_BUTTON_NAME	30
# define MARGIN_BETWEEN_LINES 	2
# define MARGIN_BETWEEN_COLUMNS	(MAXLEN_OF_BUTTON_NAME + 5)
# define MARGIN_TOP				3
# define MARGIN_LEFT			5

# define _INIT_					0
# define _GET_MARGIN_TOP_		1
# define _GET_MARGIN_LEFT_		2
# define _MOVE_TO_NEXT_LINE_	3
# define _MOVE_TO_NEXT_COLUMN_	4
# define _DELETE_				5

static int				ft_round_up(float num)
{
	float				res;

	res = num - (int)num;
	if (res == 0.0)
		return ((int)num);
	else
		return ((int)(num + 1));
}

static void			del_lstcontent(void *content, size_t content_size)
{
	content = NULL;
	content_size = 0;
}

static size_t		layout(int query, size_t column)
{
	static size_t	margin_left = MARGIN_LEFT;
	static size_t	margin_top = MARGIN_TOP;
	
	if (query == _INIT_)
		margin_left = (WIN_HELP_COLS - (NUM_OF_COLUMN * MARGIN_BETWEEN_COLUMNS)) / 2;
	else if (query == _MOVE_TO_NEXT_LINE_)
		margin_top += MARGIN_BETWEEN_LINES;
	else if (query == _MOVE_TO_NEXT_COLUMN_)
	{
		margin_top = MARGIN_TOP;
		margin_left += MARGIN_BETWEEN_COLUMNS;
	}
	else if (query == _GET_MARGIN_TOP_)
		return (margin_top);
	else if (query == _GET_MARGIN_LEFT_)
		return (margin_left);
	else if (query == _DELETE_)
	{
		margin_left = 0;
		margin_top = 0;
	}
	return (0);
}

void				draw_columns(t_visu *visu, t_list *buttons, size_t numof_cols)
{
	size_t			cols_counter;
	size_t			button_counter;

	layout(_INIT_, numof_cols);
	cols_counter = 0;
	while (cols_counter < numof_cols)
	{
		button_counter = 0;
		while (buttons->content != NULL && button_counter < 4)
		{
			mvwprintw(visu->win_help, layout(_GET_MARGIN_TOP_, 0), layout(_GET_MARGIN_LEFT_, 0), buttons->content);
			wrefresh(visu->win_help);
			buttons = buttons->next;
			layout(_MOVE_TO_NEXT_LINE_, 0);
			button_counter++;
		}
		layout(_MOVE_TO_NEXT_COLUMN_, 0);
		cols_counter++;
	}
	layout(_DELETE_, 0);
}

void                draw_help(t_visu *visu, ...)
{
    va_list         factor;
    t_list          *buttons;
    const char		*element;
	size_t			numof_cols;
    
    buttons = NULL;
    va_start(factor, visu);
	element = (const char *)factor;
    while (element != NULL)
    {
		element = va_arg(factor, const char *);
        ft_lst_append(&buttons, ft_lstnew(element, ft_strlen(element) * sizeof(const char *)));
    }
	if ((numof_cols = ft_round_up((float)ft_lstsize(buttons) / 4)) == 0)
		return ;
	draw_columns(visu, buttons, numof_cols);
	ft_lstdel(&buttons, del_lstcontent);
    va_end(factor);
}
