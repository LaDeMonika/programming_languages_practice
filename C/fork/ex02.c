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
    if (id == 0)
        printf("hello from child process\n");
    else
        printf("hello from main process\n");
    return 0;
}
