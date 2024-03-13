#include <stdio.h>   // Header file for standard input/output functions like printf()
#include <unistd.h>  // Header file for POSIX operating system API, including getpid() and getppid()

/**
 * main - PID
 * getppid() to get the parent process ID and store it in my_pid
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;  // Declare a variable to hold the process ID

    // Call getppid() to get the parent process ID and store it in my_pid
    my_pid = getppid();

    // Print the parent process ID using printf() with the %u format specifier for unsigned integers
    printf("%u\n", my_pid);

    // Return 0 to indicate successful completion
    return (0);
}

