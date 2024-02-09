#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>

int main(int ac, char **av)
{
    int id1 = fork();
    int id2 = fork();

    if (id1 != 0 && id2 != 0)
    {
        printf("This is prenet prossess: ");
        sleep(1);
    }
    if (id1 == 0)
    {
        if (id2 == 0)
        {
            printf("process y\n");
        }
        else
        {
            printf("process x\n");
        }
    }
    else
    {
        if (id2 == 0)
        {
            printf("process z\n");
        }
        else
            printf("parent process\n");
    }


/*     while (wait(NULL) != -1 || errno != ECHILD)
    {
        printf("waiting for child to finish\n");
    } */
    if (id1 != 0 && id2 != 0)
    {
        if (wait(NULL) == -1)
            printf("No child process to wait for\n");
    }
}