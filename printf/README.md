# This is _printf

## _printf

**_printf** is based on emulating the normal C library printf which is used for make formatted prints.

 This is a [Holberton School](https://www.holbertonschool.com/) partner project with [@viajeradelaluz](https://github.com/viajeradelaluz) and [@NyRakath](https://github.com/NyRakath). _printf will load the data and converts them to character string and output to `stdout`.

This document explains how printf works and how to design the right format specification for any occasion

[toc]

## How does printf work?

### Description

Prints formated arguments in the presence of the universal symbol `%(FORMAT)` if this symbol isnt presence in the parameter passed, the function will only print the string without any formated option **FORMAT** identifies a value after his invocation `[ %[formater]]`, these "formater" especifies the output way of a variable or the same **FORMAT** argument string.

![Flowchar of _printf function](/_printf_flowchar.jpg)

### Project  Requirements

- All files will be compiled on Ubuntu 14.04 LTS
- Programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` `and -pedantic`
- All files end with a new line
- The code use the `Betty` style. It will be checked [Here](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl)
- Do not use global variables
- The prototypes of all functions should be included in your header file called `main.h`
- Authorized functions and macros:
  - `write` (man 2 write)
  - `malloc` (man 3 malloc)
  - `free` (man 3 free)
  - `va_start` (man 3 va_start)
  - `va_end` (man 3 va_end)
  - `va_copy` (man 3 va_copy)
  - `va_arg` (man 3 va_arg)

### How  To Use

> ```This is a blockquote with two paragraphs. This is first paragraph.
> $ git clone git@github.com:NyRakath/printf.git
> ```

compile everything within the directory and use _printf instead of printf

> ```This is a blockquote with two paragraphs. This is first paragraph.
> $ gcc -Wall -Werror -Wextra -pedantic *.c
> ```

Declaration 

| Formater | Function to use |
| -------- | --------------- |
| Char let | Int ( *f )()    |

``` markdown
 #include "main.h"
    /**
    * Filename: main.c
    * main - Entry point
    *
    * Return: Always 0
    */
    int main(void)
    {
        /* Print strings */
        _printf("Hello %s\n", "World");
        /* Print integers */
        _printf("%d\n", 1024);
        /* Print a single char */
        _printf("%c\n", 'H');
        return (0);
    }
```

### Examples

**String**

- Input: `_printf("%s\n", 'Hello World.');`
- Output: `HelloWorld.`

**Character**

- Input: `_printf("The first numbers in the integers is %c\n", '1');`
- Output: `The first numbers in the intgers is 1`

**Integer**

- Input: `_printf("There are %i dozens in a gross\n", 12);`
- Output: `There are 12 dozens in a gross`

**Decimal:**

- Input: `_printf("%d\n", 567);`
- Output: `567`

### Format tags

format tags must follow the format of specifier

| **specifier** | **output**           |
| ------------- | -------------------- |
| c             | characters           |
| s             | string of characters |
| i or d        | signed decimal int   |
| %             | printf %             |
