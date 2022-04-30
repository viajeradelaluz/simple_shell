# Compilation for the hsh shell
# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -pedantic

# hsh.c
hsh:
	$(CC) $(CFLAGS) *.c -o hsh
	./hsh

clear:
	rm hsh .simple_shell_history
