# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 15:50:14 by ergottli          #+#    #+#              #
#    Updated: 2020/01/31 20:30:23 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_isalpha.c \
    ./ft_isdigit.c \
    ./ft_isalnum.c \
    ./ft_isascii.c \
    ./ft_isprint.c \
    ./ft_toupper.c \
    ./ft_tolower.c \
    ./ft_bzero.c \
    ./ft_strdup.c \
    ./ft_memset.c \
    ./ft_strchr.c \
    ./ft_strrchr.c \
    ./ft_strlen.c \
    ./ft_strcmp.c \
    ./ft_strncmp.c \
    ./ft_strstr.c \
    ./ft_strnstr.c \
    ./ft_memcpy.c \
    ./ft_memccpy.c \
    ./ft_memmove.c \
    ./ft_memchr.c \
    ./ft_memcmp.c \
    ./ft_strcpy.c \
    ./ft_strncpy.c \
    ./ft_strcat.c \
    ./ft_strncat.c \
    ./ft_atoi.c \
    ./ft_memalloc.c \
    ./ft_memdel.c \
    ./ft_strclr.c \
    ./ft_strdel.c \
    ./ft_striter.c \
    ./ft_striteri.c \
    ./ft_strnew.c \
    ./ft_strlcat.c \
    ./ft_putchar.c \
    ./ft_putstr.c \
    ./ft_putnbr.c \
    ./ft_putchar_fd.c \
    ./ft_putchar_fd.c \
    ./ft_putstr_fd.c \
    ./ft_putendl.c \
    ./ft_putendl_fd.c \
    ./ft_putnbr_fd.c \
    ./ft_itoa.c \
    ./ft_strmap.c \
    ./ft_strmapi.c \
    ./ft_strequ.c \
    ./ft_strnequ.c \
    ./ft_strsub.c \
    ./ft_strjoin.c \
	./ft_strjoin_free.c \
    ./ft_strrejoin.c \
    ./ft_strrejoin_right.c \
    ./ft_strrejoin_left.c \
    ./ft_strtrim.c \
    ./ft_strsplit.c \
    ./ft_lstnew.c \
    ./ft_lstdelone.c \
    ./ft_lstdel.c \
    ./ft_content_del.c \
    ./ft_lstadd.c \
    ./ft_lst_append.c \
    ./ft_lstiter.c \
    ./ft_lstmap.c \
    ./ft_swap.c \
    ./ft_binary_search.c \
    ./ft_bruteforce.c \
    ./ft_bubble_sort.c \
    ./ft_shaker_sort.c \
    ./get_next_line.c \
    ./ft_utoa_base.c \
    ./ft_lltoa_base.c \
	./ft_putsymb_n.c \
	./ft_sign_itoa.c \
	./new_d_int_array.c \
	./new_d_char_arr.c \
	./free_d_int_arr.c \
	./free_d_char_arr.c \
	./ft_isnum.c \
	./ft_isalnumber.c \
	./ft_dlstnew.c \
	./ft_create_desdlist.c \
	./ft_deq_isempty.c \
	./ft_deq_push_l.c \
	./ft_deq_push_l.c \
	./ft_deq_popcs_l.c \
	./ft_deq_popcs_r.c \
	./ft_deq_del.c \
	./ft_init_desdlist.c \
	./ft_dlstdelone.c \
	./ft_dlstdel.c \
	./ft_dlstadd_left.c \
	./ft_dlstadd_right.c \
	./ft_get_left.c \
	./ft_get_right.c \
	./ft_dlstiter_l.c \
	./ft_dlstiter_r.c \
	./ft_dlst_print_cs.c \
	./free_d_char_rarr.c \
	./ft_dlst_add_left_prior.c \
	./ft_deq_push_l_pr.c \
	./ft_lstcmp_cs.c \
	./ft_strcmp_symb.c \
	./ft_strcmp_bif.c \
	./ft_strcmp_turn_double.c \
	./ft_lst_node_cpy.c \
	./ft_lst_print.c \
	./free_char_ptr.c \
	./count_chars.c \

SRC_PRINTF = ./ft_printf/srcs/ft_printf.c \
	./ft_printf/srcs/ft_del_2.c \
	./ft_printf/srcs/ft_float.c \
	./ft_printf/srcs/ft_float_infinity_nan.c \
	./ft_printf/srcs/ft_float_print.c \
	./ft_printf/srcs/ft_float_receive_binary.c \
	./ft_printf/srcs/ft_float_receive_values.c \
	./ft_printf/srcs/ft_float_rounding.c \
	./ft_printf/srcs/ft_handler_integer.c \
	./ft_printf/srcs/ft_handler_integer_flags.c \
	./ft_printf/srcs/ft_parse_types_and_flags.c \
	./ft_printf/srcs/ft_parse_width_and_precision.c \
	./ft_printf/srcs/ft_print_flags.c \
	./ft_printf/srcs/ft_putchar_pf.c \
	./ft_printf/srcs/ft_summator.c \
	./ft_printf/srcs/ft_summator_find.c \
	./ft_printf/srcs/ft_buffer.c \
	./ft_printf/srcs/ft_float_types.c

SRCO = $(SRC:.c=.o)

SRCO_PRINTF = ./ft_printf.o \
	./ft_del_2.o \
	./ft_float.o \
	./ft_float_infinity_nan.o \
	./ft_float_print.o \
	./ft_float_receive_binary.o \
	./ft_float_receive_values.o \
	./ft_float_rounding.o \
	./ft_handler_integer.o \
	./ft_handler_integer_flags.o \
	./ft_parse_types_and_flags.o \
	./ft_parse_width_and_precision.o \
	./ft_print_flags.o \
	./ft_putchar_pf.o \
	./ft_summator.o \
	./ft_summator_find.o \
	./ft_buffer.o \
	./ft_float_types.o

HEADER = ./

all: $(NAME)

$(NAME): 
	@gcc -Wall -Wextra -Werror -c $(SRC) $(SRC_PRINTF) -I $(HEADER)
	@ar rc $(NAME) $(SRCO) $(SRCO_PRINTF)
	@ranlib $(NAME)

clean:
	@rm -f $(SRCO) $(SRCO_PRINTF)

fclean: clean
	@rm -f $(NAME)

re: fclean all
