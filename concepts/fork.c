#include <stdio.h>
#include <unistd.h>
/**
 * fork - Create a new process by duplicating the current process
 *
 * This function creates a new process by duplicating the current process.
 * The new process, called the child process, is an exact copy of the
 * calling process, called the parent process, except for a few details
 * such as the process ID.
 *
 * Return:
 *  - On success, the PID of the child process is returned in the parent
 *    process, and 0 is returned in the child process.
 *  - On failure, -1 is returned in the parent process, no child process
 *    is created, and an error message is printed.
 */
int main(void)
{
/*Declare variables to hold process IDs*/
    pid_t my_pid;
    pid_t child_pid;
/* Print a message before forking */
    printf("Before fork\n");

    /* Fork the current  process */
    child_pid = fork();
    if (child_pid == -1)
    {
        /* Fork failed, print error message and return -1*/
        perror("Error:");
        return (1);
    }
    /* Both parent and child continue from here */

    /* Get the process ID of the current process */
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);

    /*Use the return value of fork to differentiate between parent and child*/
    if (child_pid == 0)
    {
/*child process*/
        printf("(%u) Nooooooooo!\n", my_pid);
    }
    else
    {
/*Parent process*/
        printf("(%u) %u, I am your father\n", my_pid, child_pid);
    }
/*Return 0 to indicate successful completion*/
    return (0);
}

