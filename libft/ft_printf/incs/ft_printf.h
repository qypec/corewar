/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:33:56 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <string.h>
# include "ansi_escape_codes.h"
# include "../../libft.h"

/*
** -------------------------- Bit's operations ---------------------------------
*/

# define PLUS 128u
# define MINUS 64u
# define SPACE 32u
# define HASH 16u
# define ZERO 8u
# define MINUS_FLOAT 4u
# define INF 2u
# define NAN 1u
# define POINTER (pr->type == 'p')
# define OCT (pr->type == 'o')
# define HEX (pr->type == 'x' || pr->type == 'X')
# define OCTHEX (OCT || HEX)
# define DECIMAL (pr->type == 'd' || pr->type == 'i' || pr->type == 'u')
# define NUMERIC (DECIMAL || OCTHEX)
# define SIGNED (pr->type == 'd' || pr->type == 'i')
# define UNSIGNED (OCTHEX || pr->type == 'u')

# define SET_BIT(byte, mask) byte |= mask

# define GET_BIT(byte, mask) byte & mask

# define CLEAR_BIT(byte, mask) byte &= ~mask

/*
** -------------------------- Struct definition -------------------------------
*/

# define PF_BUFFER 2048

typedef struct			s_printf
{
	const char			*form;
	va_list				ap;
	void				(*start)();
	char				type;
	int					specif;
	unsigned char		flags;
	int					width;
	int					precision;
	char				toprint;
	int					base;
	short				capitalize;
	short				issigned;
	int					isnegative;
	unsigned long long	count;
	unsigned char		buf[PF_BUFFER];
	ssize_t				i;
	ssize_t				len;
	ssize_t				numlen;
}						t_printf;

typedef	struct			s_limit
{
	int					min_s1;
	int					max_s1;
	int					k;
}						t_limit;

/*
** -------------------------- Printf functions -------------------------------
*/

int						ft_printf(const char *format, ...);
void					parse_width(t_printf *pr);
void					parse_precision(t_printf *pr);
void					parse_types(t_printf *pr);
int						types_checker(char c);
int						spec_checker(char c);
int						flags_checker(char c);
void					parse_flags(t_printf *pr);
void					print_width(t_printf *pr);

/*
** -------------------------- Numbers functions ------------------------------
*/

void					ft_hand_int_cast(t_printf *pr,
		unsigned short base, short capitalize);
char					*null_handle(t_printf *pr, char *str);
char					*negative_handle(t_printf *pr, char *str);
int						max_wlong_check(t_printf *pr, long long num);
char					*ft_handler_precision(t_printf *pr, char *str);
char					*ft_handler_zerowidth(t_printf *pr, char *str);
char					*ft_handler_plus_space(t_printf *pr, char *str);
char					*ft_handler_hash(t_printf *pr, char *str);
void					ft_float(t_printf *pr);
unsigned char			*summator(unsigned char *s1, unsigned char *s2);
unsigned char			*minus_2_pow(unsigned char *s, int pow);
int						ind_after_len(unsigned char *s);
int						ind_before_len(unsigned char *s);
void					over_plus(unsigned char **num, int i, int flag);
unsigned char			*receive_d_value(unsigned char static_res[80],
		t_printf *pr);
int						receive_e(unsigned char *static_res, t_printf *pr);
unsigned char			*receive_bin(t_printf *pr, unsigned char const *s);
void					print_bits(unsigned char octet);
unsigned char			*check_infinity_nan(unsigned const char *s,
		t_printf *pr, unsigned char *res);
unsigned char			*check_null(unsigned char *s, unsigned char *res);
void					print_float(unsigned char *str, t_printf *pr);
unsigned char			*round_float(t_printf *pr, unsigned char *str);
int						receive_e(unsigned char *static_res, t_printf *pr);
unsigned char			*receive_bin(t_printf *pr, unsigned char const *s);
void					ft_flag_e(unsigned char **res, t_printf *pr);
int						ft_ind_nzero(unsigned char *str);
unsigned char			*ft_add_e(unsigned char *new, t_printf *pr);
unsigned char			*obrezanie(unsigned char *s);

/*
** -------------------------- Strings functions ------------------------------
*/

void					ft_putchar_pf(t_printf *pr, unsigned char c);
void					ft_putstr_pf(t_printf *pr, char const *s);
char					*str_zero(int len);
void					ft_capitalize(t_printf *pr, char *str);

int						g_isnull;

/*
** -------------------------- Buffer -------------------------------
*/

void					print_buf(t_printf *pr);
void					add_buf_symb(t_printf *pr, char c, int len);
void					add_buf_str(t_printf *pr, unsigned char const *str);

#endif
