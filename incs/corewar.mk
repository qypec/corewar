# Base variables for corewar

CC = gcc
CFLAGS = -g -c #-Wall -Wextra -Werror
HEADER_H = -I ../incs/
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)
COREWAR = corewar
DISASSEMBLER = dis_asm
LIBNAME = libft.a