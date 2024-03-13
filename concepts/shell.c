#include <stdio.h>      /*Standard input/output functions*/
#include <unistd.h>     /* Standard symbolic constants and types*/
#include <stdlib.h>     /* Standard library functions*/
#include <string.h>     /* String manipulation functions*/
#include <sys/wait.h>   /* Wait for process termination function*/

int main(void)
{
    char *lineptr = NULL;   /* Pointer to the input line buffer*/
    size_t n = 0;           /* Initial size of the input buffer*/
    pid_t child_pid;        /* Process ID of the child process*/
    int status;             /* Exit status of the child process*/

    /*create a prompt and wait for argument to be entered*/
    printf("#cisfun$ ");

    while (getline(&lineptr, &n, stdin) != -1)
    {
        /* Remove the newline character at the end of the line using strtok*/
        lineptr = strtok(lineptr, "\n");

        /* Fork a child process*/
        child_pid = fork();
        if (child_pid == 0)
        {
            /* Child process*/
            char *argv[] = {lineptr, NULL};

            /* Execute the command*/
            if (execve(lineptr, argv, NULL) == -1)
            {
                perror("execve");
                exit(1);
            }
        }
        else
        {
            /* Parent process*/
            wait(&status);
        }

        /* Print prompt for the next command*/
        printf("#cisfun$ ");
    }

    /* Free the memory allocated for the input line*/
    free(lineptr);
    return (0);
}

