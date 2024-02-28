#include <unistd.h> // to use fork();
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* creating main and child process (with fork) */
int main(int ac, char **av)
{
    fork();
    printf("bla bla\n");
    return 0;
}