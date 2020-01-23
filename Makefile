# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 18:40:10 by yquaro            #+#    #+#              #
#    Updated: 2020/01/23 19:01:47 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include incs/corewar.mk

all:
	@make -C libft/ all
	@make -C srcs/vm/ all
	@make -C srcs/visu/ all
	@make -C .objs/ all

clean:
	@make -C libft/ clean
	@make -C .objs/ clean

fclean: clean
	@make -C libft/ fclean
	@make -C .objs/ fclean

re: fclean all