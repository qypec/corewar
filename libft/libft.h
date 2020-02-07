/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:46:24 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "ft_printf/incs/ft_printf.h"

# define BUFF_SIZE (1)
# define ISINT (1u << 7u)
# define ISCHAR (1u << 6u)
# define ISCHARPTR (1u << 5u)

/*
** -------------------------- Struct's ------------------------------
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	struct s_dlist	*next;
	struct s_dlist	*prev;
	void			*content;
	size_t			content_size;
	size_t			pr;

}					t_dlist;

typedef struct		s_desdlist
{
	t_dlist			*start;
	t_dlist			*end;
	t_dlist			*ptr;
	char			mem;
}					t_desdlist;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

/*
** -------------------------- Type conversion functions --------------------
*/

char				*ft_lltoa_base(long long value, int base);
char				*ft_utoa_base(unsigned long long value, unsigned int base);
int					ft_atoi(const char *str);

/*
** -------------------------- Memory functions ------------------------------
*/

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
** -------------------------- ASCII functions ------------------------------
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isspace(char c);
int					ft_isnum(char *str);
int					ft_isalnumber(char *str);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** -------------------------- Input functions ------------------------------
*/

int					get_next_line(int fd, char **line);

/*
** -------------------------- Output functions -----------------------------
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putsymb_n(char c, int len);

/*
** -------------------------- String functions -----------------------------
*/

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strrejoin(char *s1, char const *s2);
char				*ft_strrejoin_right(const char *s1, char *s2);
char				*ft_strrejoin_left(char *s1, const char *s2);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_sign_itoa(int n);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp_symb(const char *s1, const char *s2, char symb);
int					ft_strcmp_bif(const char *s1,
		const char *s2, char symb, int n);
int					ft_strcmp_turn_double(const char *s1,
		const char *s2, char symb);
int					free_char_ptr(char *ptr, int out);
int					count_chars(char *str, char c);

/*
** -------------------------- Singly-linked list functions -------------------
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_content_del(void *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lst_append(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lst_print(t_list *lst, unsigned char type, char n_flag);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstcmp_cs(t_list *l, t_list *r, size_t end);
int					ft_lst_node_cpy(t_list *lst);
size_t				ft_lstsize(t_list *alst);

/*
** -------------------------- Doubly-linked list functions -------------------
*/

t_dlist				*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstdelone(t_dlist **dlst, void (*del)(void*, size_t));
void				ft_dlstdel(t_dlist **dlst, void (*del)(void *, size_t));
void				ft_dlstadd_left(t_dlist **dlst, t_dlist *new);
void				ft_dlstadd_left_prior(t_dlist **left,
		t_dlist **right, t_dlist *new);
void				ft_dlstadd_right(t_dlist **dlst, t_dlist *new);
t_dlist				*ft_get_left(t_dlist **dlst);
t_dlist				*ft_get_right(t_dlist **dlst);
void				ft_dlstiter_l(t_dlist *dlst, void (*f)(t_dlist *elem));
void				ft_dlstiter_r(t_dlist *dlst, void (*f)(t_dlist *elem));
void				ft_dlst_print_cs(t_dlist *dlst);

/*
** -------------------------- Deq functions ------------------------------
*/

t_desdlist			*ft_create_desdlist(void);
short				ft_init_desdlist(t_desdlist **deq);
short				ft_deq_isempty(t_desdlist *deq);
short				ft_deq_push_l(t_desdlist **deq, void *content, size_t cs);
short				ft_deq_push_l_pr(t_desdlist **deq,
		void *content, size_t cs, size_t pr);
short				ft_deq_push_r(t_desdlist **deq, void *content, size_t cs);
size_t				ft_deq_popcs_l(t_desdlist **deq);
size_t				ft_deq_popcs_r(t_desdlist **deq);
void				ft_deq_del(t_desdlist **deq);

/*
** -------------------------- Sorting functions ------------------------------
*/

void				ft_swap(char *a, char *b);
int					ft_linear_search(const char *s, char c);
int					ft_binary_search(char *s, char c);
void				ft_bubble_sort(char *s);
void				ft_shaker_sort(char *s);

/*
** -------------------------- Math functions ------------------------------
*/

int					ft_sqrt(int nb);

/*
** -------------------------- Matrix functions ------------------------------
*/

int					**new_d_int_arr(int first, int second);
char				**new_d_char_arr(int first, int second);
void				free_d_int_arr(int **arr, int len);
char				*free_d_char_arr(char **arr, int len);
char				**free_d_char_rarr(char **arr, int len);

/*
** -------------------------- Output functions ------------------------------
*/

int					ft_printf(const char *format, ...);;

#endif
