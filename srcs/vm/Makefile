# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 18:44:31 by yquaro            #+#    #+#              #
#    Updated: 2020/01/28 17:55:30 by vgerold-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../incs/corewar.mk

HEADER_H = -I ../../incs/

DIR_O = ../../.objs/vm
SOURCES = battle.c battle_check.c check_args.c corewar.c create_players.c \
			debug.c init_game.c op_1.c op_2.c op_3.c op_utils.c parse_file.c \
			parse_operations.c process_func.c check_flags.c op_log.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling vm files

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
