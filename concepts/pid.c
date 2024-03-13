#include <stdio.h>
#include <unistd.h>

/**
 * getpid - Get the process ID of the current process
 *
 * Return: The process ID of the current process.
 */
int main(void)
{
    /* Declare a variable to hold the process ID*/
	pid_t my_pid;

    /* Call getpid() to get the process ID of the current process*/
	my_pid = getpid();
/**
 * Print the process ID using printf()
 * The %u format specifier is used to print an unsigned integer, 
 * which is the type of PID returned by getpid().
 */    
	printf("%u\n", my_pid);

    /* return 0 to indicate successful completion*/
    return (0);
}

