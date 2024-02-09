#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

/* process IDs in C */
int main()
{
    int id = fork();

    if (id != 0)
    {
        printf("This is prenet prossess: ");
        sleep(1);
    }
    printf("Current ID: %d, perent ID:%d\n", getpid(), getppid());
    if (id != 0)
    {
        if (wait(NULL) == -1)
            printf("No child process to wait for\n");
    }
}