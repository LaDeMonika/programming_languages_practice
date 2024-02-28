#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    /* 
        fd[0] -> read
        fd[1] -> write
        fd[2] -> 
     */
    int fd[2];

    /* pipe () in memory file. has like
    a buffer and store in it and read from it. */
    if (pipe(fd) == -1)
    {
        printf("An error ocurred with opening the pipe\n");
        return 1;
    }
    int id = fork();
    if (id == -1)
    {
        printf("An error ocurred with fork\n");
        return 4;
    }
    if (id == 0) // code for child prosses
    {
        close (fd[0]); //close read

        int x;

        printf("Input number: ");
        scanf("%d", &x);
        if (write(fd[1], &x, sizeof(int)) == -1)
        {
            printf("An error ocurred with writing to the pipe\n");
            return 1;
        }
        //after we are done with writing
        //we should close the file descriptor
        close(fd[1]);
    }
    else // code for main prosses
    {
        int y;

        if (read(fd[0], &y, sizeof(int)) == -1)
        {
            printf("An error ocurred with reading from the pipe\n");
            return 3;
        }
        y = y * 3;
        close(fd[0]);
        printf("Got from child prosses %d\n", y);
    }

}