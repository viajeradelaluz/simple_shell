#include "main.h"

void sigint_c(int signal)
{
    (void)signal;
    write(STDOUT_FILENO, "\n($) ", 5);
}