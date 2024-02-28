#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int ac, char **av)
{
    int p1[2];

    if (pipe(p1) == -1)
        return 1;
    
    int pid = fork();
    if (pid == -1) 
        return 2;
    if (pid == 0)
    {
        //Child process
        int x;
        if (read(p1[0], &x, sizeof(x)) == -1)
            return 3;
        printf("received %d\n", x);
        x *= 4;
        if (write(p1[1], &x, sizeof(x)) == -1)
            return 4;
        printf("Wrote %d\n", x);
    }
    else
    {
        //perent process
        srand(time(NULL));
        int y = rand() % 10;
        if (write(p1[1], &y, sizeof(y)) == -1)
            return 5;
        printf("Wrote %d\n", y);
        if (read(p1[0], &y, sizeof(y)) == -1)
            return 6;
        printf("result is %d\n", y);
    }
    close(p1[0]);
    close(p1[1]);
}