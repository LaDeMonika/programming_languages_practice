#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

/*  waitpid will wait for specific child process to finish its execution
    */
int main(int ac, char **av)
{
    //first child process
    int pid1 = fork();
    if (pid1 == -1)
    {
        printf("Error creating process\n");
        return 1;
    }
    if (pid1 == 0)
    {
        sleep(4); //4 seconds
        printf("Finished executin (%d)\n", getpid()); //we need getpid because pid1 is def 0
        return 0;
    }
    
    //second child process
    int pid2 = fork();
    if (pid2 == -1)
    {
        printf("Error creating process\n");
        return 2;
    }
    if (pid2 == 0)
    {
         sleep(1); //1 second
        printf("Finished executin (%d)\n", getpid()); //we need getpid because pid1 is def 0
        return 0;
    }

    /* int pid1_res = wait(NULL);
    printf("waited for %d\n", pid1_res);
    int pid2_res = wait(NULL);
    printf("waited for %d\n", pid2_res); */

    int pid1_res = waitpid(pid1, NULL, WNOHANG); //WNOHANG / 0
    printf("waited for %d\n", pid1_res);
    int pid2_res = waitpid(pid2, NULL, WNOHANG); //WNOHANG / 0
    printf("waited for %d\n", pid2_res);
}