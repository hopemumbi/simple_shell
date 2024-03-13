#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * int execve(const char *pathname, char *const _Nullable argv[],
 *                                char *const _Nullable envp[]);
 *
 * execve() loads and runs a new program in the current process.
 * It replaces the current process image with a new one specified by pathname.
 * The new program is loaded into the current process address space,
 * and its entry point is called to begin execution.
 *
 * Arguments:
 *  - pathname: Path to the executable file to be executed.
 *  - argv: Array of pointers to null-terminated strings that represent
 *          the argument list available to the new program.
 *          The first argument, by convention, should point to the
 *          filename associated with the file being executed.
 *  - envp: Array of pointers to null-terminated strings that represent
 *          the environment of the new program.
 *          By convention, this array ends with a NULL pointer.
 */

int main(int argc, char *argv[])
{
    /* Define an array of strings for the new argument list*/
    static char *newargv[] = {"NULL", "hello", "world", NULL};

    /* Define an array of strings for the new environment list*/
    static char *newenvp[] = { NULL };

    /* Update the first element of newargv to match the first argument of the program*/
    newargv[0] = argv[1];

    /* Replace the current process image with a new one specified by argv[1]*/
    /* using the new argument and environment lists*/
    execve(argv[1], newargv, newenvp);

    /* This line is reached only if execve() fails*/
    perror("execve");
    return 1;
}
