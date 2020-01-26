# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 18:40:10 by yquaro            #+#    #+#              #
#    Updated: 2020/01/26 03:31:58 by ergottli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include incs/corewar.mk

all:
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
