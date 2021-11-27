#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid, my_ppid;

    my_pid = getpid();
	my_ppid = getppid();
    printf("PID: %u\n", my_pid);
	printf("PPID: %u\n", my_ppid);
    return (0);
}
