# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 18:40:59 by yquaro            #+#    #+#              #
#    Updated: 2020/01/31 19:30:16 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../incs/corewar.mk

CFLAGS = -g -Wall -Wextra -Werror
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)

all:
	@mv ../libft/$(LIBNAME) $(LIBNAME)
	make -C disasm/ all
	$(COMPILING) *.o $(LIBNAME) -o $(EXECUTABLE)
	@mv $(EXECUTABLE) ../$(EXECUTABLE)
	@echo \*\*\* COREWAR COMPILED!

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(LIBNAME)