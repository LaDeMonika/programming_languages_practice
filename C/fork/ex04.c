#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main()
{
    int id = fork();
    int n;

    if (id == 0)
    {
        n = 1;
        /* first five num will print child */
    }
    else
    {
        n = 6;
        /* and second main process */
    }

    if (id != 0)
    {
        wait(NULL);
        /* main process will wait till child is done */
    }
    int i;
    for (i = n; i < n + 5; i++)
    {
        printf("%d ", i);
        fflush(stdout);
    }
    if (id != 0)
    {
        printf("\n");
    }
    return 0;
}