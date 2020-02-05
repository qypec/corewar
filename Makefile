# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 18:40:10 by yquaro            #+#    #+#              #
#    Updated: 2020/02/05 19:02:01 by ergottli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include incs/corewar.mk

all: corewar

corewar:
	@make -C libft/ all
	@make -C srcs/vm/ all
	@make -C .objs/ all

clean:
	@make -C libft/ clean
	@make -C .objs/ clean

fclean: clean
	@make -C libft/ fclean
	@make -C .objs/ fclean
	rm -rvf .objs/*.o
	rm -rvf srcs/vm/*.o
	rm -rvf corewar

re: fclean all
