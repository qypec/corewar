# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 15:30:59 by yquaro            #+#    #+#              #
#    Updated: 2020/02/05 16:43:26 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../incs/corewar.mk

HEADER_H = -I ../../incs/

DIR_O = ../../.objs/disasm
SOURCES = disassemble.c init.c parse_bytecode.c create_asm_file.c \
			convert_player_code.c arg_type.c bytecode_to_int.c interpret_args.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling disasm files

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@