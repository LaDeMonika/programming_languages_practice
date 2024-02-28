#include <unistd.h> // to use fork();
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* creating main and child process (with fork) */
int main(int ac, char **av)
{
    int id = fork(); // create one child process

    /* to check if im in child process */
    if (id != 0) //we'll get only tree processes...
    {
        fork();
                /* ..because main proces get forked, child whould
                be as well forked if we didn't (id != 0)
                and called fork func inside */
    }
    printf("Hello\n");
    return 0;
}
