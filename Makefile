NAME		=	volarium
CC		=	gcc
C_FLAGS		=	-Wall -Wextra -Werror -ggdb -g3
AR		=	ar -rf

INCLUDE		=	-Iincludes/

SRCS_DNA	=	DNA_rand.c

SRCS_ALL	=	$(addprefix sources/genetics/, $(SRCS_DNA))

OBJS_DIR	=	objs
OBJS_ALL	=	$(addprefix $(OBJS_DIR)/,$(SRCS_ALL:.c=.o))

DNA_RAND_T	=	sources/genetics/tests/DNA_rand.c

all: $(OBJS_ALL) tests

tests: DNA_tests

$(OBJS_DIR)/%.o:%.c
	@mkdir -p $(@D)
	@$(CC) $(C_FLAGS) -c $< -o $@ $(INCLUDE)
	@printf "%-10s\033[0;32m%20s\033[0m\n" "Objects" "Compiled"

DNA_tests: $(OBJS_ALL)
	@$(CC) $(C_FLAGS) $(DNA_RAND_T) $(OBJS_ALL) $(INCLUDE) -o $@
	@printf "%-10s\033[0;32m%20s\033[0m\n" "DNA_tests" "Compiled"

clean:
	@rm -rf $(OBJS_DIR)
	@printf "%-10s\033[0;31m%20s\033[0m\n" "Objects" "Removed"

tests_clean:
	@rm -rf DNA_tests
	@printf "%-10s\033[0;31m%20s\033[0m\n" "Tests" "Removed"

fclean: clean tests_clean
	@rm -rf $(NAME)
	@printf "%-10s\033[0;31m%20s\033[0m\n" "Program" "Removed"

re: fclean all

.PHONY: all tests DNA_tests clean tests_clean fclean re
