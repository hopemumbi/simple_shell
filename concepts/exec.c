#include <unistd.h>
#include <stdio.h>

/**
 * The execve function replaces the current process with a new process. It loads
 * and runs a new program from the specified pathname, with the provided
 * command-line arguments and environment variables.
 *
 * int execve(const char *pathname, char *const argv[], char *const envp[]);
 * - pathname: The path to the executable file to be executed.
 * - argv: An array of strings representing the command-line arguments for the new program.
 *         The first element should be the name of the program itself.
 *         The last element must be NULL to indicate the end of the array.
 * - envp: An array of strings representing the environment variables for the new program.
 *         This array must end with a NULL pointer.
 *
 * If execve is successful, it does not return. If an error occurs, it returns -1,
 * and the current process continues to run.
 */

int main()
{
    // Define an array of strings representing the command-line arguments
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    // Print a message before calling execve
    printf("BEFORE");

    // Call execve to execute the "/bin/ls" program with the specified arguments
    if (execve(argv[0], argv, NULL) != -1)
    {
        // Print an error message if execve fails
        printf("error");
    }

    // Print a message after execve (this line should not be reached if execve is successful)
    printf("AFTER");

    // Return 0 to indicate successful completion of the program
    return 0;
}
