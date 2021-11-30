#include "shell.h"

int main(void)
{
    int n_process = 1, status = 0;
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }

    while (n_process <= 5)
    {
        if (child_pid == 0)
        {
            execve(argv[0], argv, NULL);
            exit(0);
        }
        else
        {
            wait(&status);
            child_pid = fork();
        }
        n_process++;
    }
    return (0);
}