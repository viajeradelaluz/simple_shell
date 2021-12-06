# Compilation for the shell
# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -pedantic

# shell.c
shell:
	$(CC) $(CFLAGS) shell.c parse_functions.c read_functions.c execute_functions.c builtins.c -o shell
	valgrind -s ./shell
	rm shell

# env.c
env:
	$(CC) $(CFLAGS) env.c -o env
	valgrind -s ./env
	rm env

# tokenize_path.c
tokenize_path:
	$(CC) $(CFLAGS) tokenize_path.c -o tokenize_path
	valgrind -s ./tokenize_path
	rm tokenize_path

# fork_execve_wait.c
fork_execve_wait:
	$(CC) $(CFLAGS) fork_execve_wait.c -o fork_execve_wait
	.valgrind -s ./fork_execve_wait
	rm fork_execve_wait

# fork.c
fork:
	$(CC) $(CFLAGS) fork.c -o fork
	.valgrind -s /fork
	rm fork

# execve.c
execve:
	$(CC) $(CFLAGS) execve.c -o execve
	./execve
	rm execve

# array_tokens.c
array_tokens:
	$(CC) $(CFLAGS) array_tokens.c -o array_tokens
	valgrind -s ./array_tokens
	rm array_tokens

# strtok_2.c
strtok_2:
	$(CC) $(CFLAGS) strtok_2.c -o strtok_2
	./strtok_2
	rm strtok_2

# prompt.c
prompt:
	$(CC) $(CFLAGS) prompt.c -o prompt
	valgrind -s ./prompt
	rm prompt

# pid.c
pid:
	$(CC) $(CFLAGS) pid.c -o pid
	./pid

# stat.c
stat:
	$(CC) $(CFLAGS) stat.c -o stat
	./stat
	rm stat
