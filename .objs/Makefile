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

all: prep corewar disasm

prep:
	@cp ../libft/$(LIBNAME) ./$(LIBNAME)

corewar: prep
	$(COMPILING) ./vm/*.o $(LIBNAME) -o $(COREWAR)
	@mv $(COREWAR) ../$(COREWAR)
	@echo \*\*\* COREWAR COMPILED!

disasm: prep
	$(COMPILING) ./disasm/*.o $(LIBNAME) -o $(DISASSEMBLER)
	@mv $(DISASSEMBLER) ../$(DISASSEMBLER)
	@echo \*\*\* DISASSEMBLER COMPILED!

clean:
	rm -rvf *.o

fclean: clean
	@rm -rvf $(LIBNAME) $(COREWAR) $(DISASSEMBLER)