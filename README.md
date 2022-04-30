<br>

<h1 align='center'><img src='https://upload.wikimedia.org/wikipedia/commons/thumb/4/4b/Bash_Logo_Colored.svg/1200px-Bash_Logo_Colored.svg.png' width='120'><br>Simple shell</h1>

<p align='center'><img src='https://img.shields.io/badge/powershell-5391FE?style=for-the-badge&logo=powershell&logoColor=white'><img src='https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black'><img src='https://img.shields.io/badge/GNU%20Bash-4EAA25?style=for-the-badge&logo=GNU%20Bash&logoColor=white'></p>

<br>

This project is an implementation of a simple UNIX command line interpreter. It includes the basic functionality of the stantard functions and system calls, in the tradition of the first shell written by Ken Thompson.

## Overview

Holberton School teaches Full-Stack Software Engineering with a project-based approach. *Simple Shell* is the final project of the first trimester that covers the Low-level programming of Software Engineering.

## Requirements

Compile all ```*.c``` files using GNU Compiler Collection (GCC) and run under linux environments like ```Ubuntu 20.04 LTS```.

### Invocation

#### *GCC command to compile:*
```sh
~$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

#### *Run the shell in interactive mode:*
```sh
~$ ./hsh
```

#### *Or run the shell in non-interactive mode:*
```sh
~$ echo "ls -l" | ./hsh
```

#### *The magic of Makefile:*

You can compile and run the *simple shell* with the Makefile using the command below. **Note: This only works for the interactive mode.**
```sh
~$ make hsh
($) 
```
## Usage

Execute commands in a similar manner to *sh*. However *simple shell* has more limited functionality. It's development is ongoing.

### Interative mode:

```sh
~$ ./hsh
($) cd simple_shell
($) pwd
/home/simple_shell
($) ls -go
total 76
-rwxrwxrwx 1     9 Dec  7 12:53 AUTHORS
-rwxrwxrwx 1  1122 Dec  7 12:35 README.md
-rwxrwxrwx 1   900 Dec  7 09:08 _strtok.c
-rwxrwxrwx 1  2154 Dec  7 23:48 builtins.c
-rwxrwxrwx 1  2756 Dec  7 19:15 execute.c
-rwxrwxrwx 1   453 Dec  7 18:42 history.c
-rwxrwxrwx 1 40832 Dec  8 01:52 hsh
-rwxrwxrwx 1  1343 Dec  7 23:43 main.h
-rwxrwxrwx 1   256 Dec  7 19:17 makefile
-rwxrwxrwx 1  1229 Dec  7 18:42 man_1_simple_shell
-rwxrwxrwx 1  1812 Dec  7 12:28 parse.c
-rwxrwxrwx 1  1360 Dec  8 01:49 read.c
-rwxrwxrwx 1   696 Dec  7 23:09 shell.c
-rwxrwxrwx 1  2002 Dec  8 01:09 strings.c
drwxrwxrwx 1  4096 Dec  8 01:57 test
($) exit
~$ 
```

### Non-interactive mode:

```sh
~$ echo "cat AUTHORS" | ./hsh
# This file lists all indivual contributions to the repository.
# It is generated using the `test/generate-authors.sh` script.

Johanna Alfonso <jonna.alfonso@gmail.com>
Cesar Molina <cesaruxfxtx@gmail.com>
pipeleon <oflg94@gmail.com>
~$ 
```

## File Description

- ``AUTHORS`` — Contributions to the repository.
- ``README.md`` — Project's description.
- ``_strtok.c`` — Implementation of strtok function.
- ``builtins.c`` — Parse if a command should be execute as a built-in function: ``_cd``, ``_help``, ``__exit``, ``_env``.
- ``execute.c`` — Main track process of the shell. Where the input line is readed, the arguments are parsed and the commands are executed.
- ``history.c`` — Implementation of the history built-in
- ``main.h`` — Main libraries that allow the compilation of the program.
- ``makefile`` — Script to compilate and run the shell.
- ``man_1_simple_shell`` — Man page of the program.
- ``parse.c`` — Functions behind of parsing the line and arguments.
- ``read.c`` — Functions behind of getting the PATH and working with strings.
- ``shell.c`` — Main program of the shell.
- ``strings.c`` — Functions behind of working with strings.
- ``test`` — Folder with background exercises to prepare the shell project.

## Authors

Johanna Alfonso, Cesar Molina, Felipe León.

## More information

[Holberton School](https://www.holbertonschool.com/)
