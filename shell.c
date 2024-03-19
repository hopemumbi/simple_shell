#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
/**
 * main - 1. Simple shell 0.1
 *
 * Return: always 0
 */
int main(int ac, char **av, char **env)
{
	ssize_t read;
	char *lineptr = NULL;
	size_t n = 0;
	pid_t child_pid;
	int status;

	while (1)
	{
		/*display a prompt and wait for user to enter command*/
		printf("$ ");
		/*read a command line from user*/
		read = getline(&lineptr, &n, stdin);
		if (read == -1)
		{
			break;
		}
		/*remove the end of line*/
		lineptr = strtok(lineptr, "\n");
		/*create a child process*/
		child_pid = fork();
		if (child_pid == 0)
		{
			char *argv[] = {NULL, NULL};

			argv[0] = lineptr;

			if ((execve(argv[0], argv, NULL) == -1))
			{
				printf("%s: No such file or directory\n", av[ac - 1]);
				exit(1);
			}
		}
		else
		{
			wait(&status);

			printf("\nEnvironment: \n");
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
		}
	}
	free(lineptr);
	return (0);
}
