#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * wait - Wait for a child process to change state
 *
 * This function causes the calling process to block until one of its child
 * processes terminates or stops (e.g., by receiving a signal). If the
 * function returns because a child has stopped, the return value is the
 * process ID of the stopped child. If the function returns because a child
 * has terminated, the return value is the process ID of the terminated
 * child. The exit status or termination information of the child process
 * is stored in the location pointed to by `wstatus`, if `wstatus` is not NULL.
 *
 * Arguments:
 *  - wstatus: A pointer to an integer where the exit status or termination
 *             information of the child process will be stored.
 *
 * Returns:
 *  - On success, the process ID of the child that terminated or stopped.
 *  - On error, -1 is returned, and an error message is printed.
 */

int main(void)
{
    // Declare variables to hold the child process ID and status
    pid_t child_pid;
    int status;

    // Create a child process
    child_pid = fork();

    // Check if fork failed
    if (child_pid == -1)
    {
        // Fork failed, print error message and return 1
        perror("Error:");
        return (1);
    }

    // Code executed by the child process
    if (child_pid == 0)
    {
        printf("Wait for me, wait for me\n");
        sleep(3); /*suspends the execution of a process for a specified number of seconds*/
    }
    // Code executed by the parent process
    else
    {
        // Parent process waits for the child process to change state
        wait(&status);

        // Check if child terminated normally
        if (WIFEXITED(status))
        {
            printf("Child process terminated with status: %d\n", WEXITSTATUS(status));
        }
        // Check if child terminated due to a signal
        else if (WIFSIGNALED(status))
        {
            printf("Child process terminated due to signal: %d\n", WTERMSIG(status));
        }

        printf("Oh, it's all better now\n");
    }

    // Return 0 to indicate successful completion
    return (0);
}
