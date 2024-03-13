#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>  
#include <unistd.h>   
/**
 * main - stat example
 *
 * int stat(const char *restrict pathname, struct stat *restrict statbuf);
 * stat function is used to retrieve information about a file specified by pathname.
 * pathname is a pointer to a string containing the path to the file.
 * statbuf is a pointer to a struct stat where the file status information will be stored.
 * The function returns 0 on success and -1 on failure, setting errno to indicate the error.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    unsigned int i;
    struct stat st;     /*Structure for storing file status information*/

    /*Check if the program is called with at least one command-line argument*/
    if (ac < 2)
    {
        /*Print usage information and exit with error status*/
        printf("Usage: %s path_to_file ...\n", av[0]);
        return (1);
    }

    /*Initialize the index variable to 1 to skip the program name (av[0])*/
    i = 1;

    /* Iterate over each command-line argument*/
    while (av[i])
    {
        /* Print the current argument */
        printf("%s:", av[i]);
	/**
        * Use the stat function to get file status information
        * The stat function returns 0 if successful, -1 if there was an error
	*/
        if (stat(av[i], &st) == 0)
        {
            /* If the file exists, print "FOUND"*/
            printf(" FOUND\n");
        }
        else
        {
            /* If the file does not exist, print "NOT FOUND"*/
            printf(" NOT FOUND\n");
        }

        /* Move to the next command-line argument*/
        i++;
    }

    // Return 0 to indicate successful completion of the program
    return (0);
}

