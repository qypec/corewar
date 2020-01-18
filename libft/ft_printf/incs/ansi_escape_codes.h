/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi_escape_codes.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:43:45 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_ANSI_ESCAPE_CODES_H
# define FT_PRINTF_ANSI_ESCAPE_CODES_H

/*
** ----------------------- FONT COLORs definition ------------------------------
*/

# define ANSI_BLACK			"\e[30m"
# define ANSI_RED			"\e[31m"
# define ANSI_GREEN			"\e[32m"
# define ANSI_YELLOW		"\e[33m"
# define ANSI_BLUE			"\e[34m"
# define ANSI_MAGENTA		"\e[35m"
# define ANSI_CYAN			"\e[36m"
# define ANSI_COLOR_DEFAULT	"\e[36m"
# define ANSI_WHITE			"\e[37m"
# define ANSI_B_BLACK		"\e[90m"
# define ANSI_B_RED			"\e[91m"
# define ANSI_B_GREEN		"\e[92m"
# define ANSI_B_YELLOW		"\e[93m"
# define ANSI_B_BLUE		"\e[94m"
# define ANSI_B_MAGENTA		"\e[95m"
# define ANSI_B_CYAN		"\e[96m"
# define ANSI_B_WHITE		"\e[97m"

/*
** ----------------------- BG COLORs definition --------------------------------
*/

# define ANSI_BG_BLACK		"\e[40m"
# define ANSI_BG_RED		"\e[41m"
# define ANSI_BG_GREEN		"\e[42m"
# define ANSI_BG_YELLOW		"\e[43m"
# define ANSI_BG_BLUE		"\e[44m"
# define ANSI_BG_MAGENTA	"\e[45m"
# define ANSI_BG_CYAN		"\e[46m"
# define ANSI_BG_WHITE		"\e[47m"
# define ANSI_BG_B_BLACK	"\e[100m"
# define ANSI_BG_B_RED		"\e[101m"
# define ANSI_BG_B_GREEN	"\e[102m"
# define ANSI_BG_B_YELLOW	"\e[103m"
# define ANSI_BG_B_BLUE		"\e[104m"
# define ANSI_BG_B_MAGENTA	"\e[105m"
# define ANSI_BG_B_CYAN		"\e[106m"
# define ANSI_BG_B_WHITE	"\e[107m"

/*
** ----------------------- FORMATs definition ---------------------------------
*/

# define ANSI_BOLD			"\e[1m"
# define ANSI_FAINT			"\e[2m"
# define ANSI_ITALIC		"\e[3m"
# define ANSI_UNDERLINE		"\e[4m"
# define ANSI_S_BLINK		"\e[5m"
# define ANSI_F_BLINK		"\e[6m"
# define ANSI_REVERSE		"\e[7m"
# define ANSI_CONCEAL		"\e[8m"
# define ANSI_CROSSED		"\e[9m"
# define ANSI_NORM_FONT		"\e[10m"
# define ANSI_FONT_1		"\e[11m"
# define ANSI_FONT_2		"\e[12m"
# define ANSI_FONT_3		"\e[13m"
# define ANSI_FONT_4		"\e[14m"
# define ANSI_FONT_5		"\e[15m"
# define ANSI_FONT_6		"\e[16m"
# define ANSI_FONT_7		"\e[17m"
# define ANSI_FONT_8		"\e[18m"
# define ANSI_FONT_9		"\e[19m"
# define ANSI_FRAKTUR		"\e[20m"
# define ANSI_BOLD_OFF		"\e[21m"
# define ANSI_NORM_COLOR	"\e[22m"
# define ANSI_ITALIC_OFF	"\e[23m"
# define ANSI_UNDER_OFF		"\e[24m"
# define ANSI_BLINK_OFF		"\e[25m"
# define ANSI_HZ			"\e[26m"
# define ANSI_INVERSE_OFF	"\e[27m"
# define ANSI_REVEAL		"\e[28m"
# define ANSI_CROSS_OFF		"\e[29m"
# define ANSI_FRAMED		"\e[51m"
# define ANSI_ENCIRCLED		"\e[52m"
# define ANSI_OVERLINED		"\e[53m"
# define ANSI_FRAMED_OFF	"\e[54m"
# define ANSI_OVERLINED_OFF	"\e[55m"

# define ANSI_RESET			"\e[0m"

#endif
