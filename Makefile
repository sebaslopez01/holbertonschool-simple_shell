NAME := shell
CC := gcc
DEBUGGER := gdb
LEAK_CHECK := valgrind
C_FLAGS := -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format
V_FLAGS := --leak-check=full --track-origins=yes
SRC := *.c
MAIN = ./tests/main.c
RM := rm

betty:
	@betty $(SRC)
	@betty *.h

build: betty
	$(CC) $(C_FLAGS) $(MAIN) $(SRC) -o $(NAME)

run: betty build
	./$(NAME)
	$(RM) -f $(NAME)

gdb: betty build
	$(DEBUGGER) ./$(NAME)
	$(RM) -f $(NAME)

valgrind: betty build
	$(LEAK_CHECK) $(V_FLAGS) ./$(NAME)
	$(RM) -f $(NAME)

valgrind-q: betty build
	$(LEAK_CHECK) --quiet $(V_FLAGS) ./$(NAME)
	$(RM) -f $(NAME)
