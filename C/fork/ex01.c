#include <unistd.h> // to use fork();
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* creating main and child process (with fork) */
int main(int ac, char **av)
{
    int id = fork(); //fork returns int num
    printf("bla bla from id: %d\n", id);
                                        /* id in child process is always 0 and
                                        if not 0 then you're in main process */
    return 0;
    /* every single process have prosses id */
}
