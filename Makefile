include incs/corewar.mk

all: corewar disasm

prep:
	echo "PREP"
	@mkdir -p ./.objs/vm ./.objs/disasm
	@make -C libft/ all

corewar: prep
	echo "COREWAR COMPILING OBJS"
	@make -C srcs/vm/ all
	@make -C .objs corewar

disasm: prep
	echo "DISASSEMBLER COMPILING OBJS"
	@make -C srcs/disasm all
	@make -C .objs disasm

clean:
	echo "CLEAN"
	@make -C libft/ clean
	@make -C .objs/ clean

fclean: clean
	echo "FCLEAN"
	@make -C libft/ fclean
	@make -C .objs/ fclean
	rm -rvf corewar
	rm -rf dis_asm

re: fclean all
