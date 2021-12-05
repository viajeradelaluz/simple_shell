# Compilation for the shell
# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -pedantic -std=gnu89

# shell.c
hsh:
	$(CC) $(CFLAGS) *.c -o hsh
	valgrind -s --leak-check=full --show-leak-kinds=all ./hsh
	rm hsh
