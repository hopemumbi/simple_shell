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
int main(int argc, char *argv[])
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
		if (child_pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);

		}
		else if (child_pid == 0)
		{
			char *newargv[] = {NULL, NULL};
			char *newenviron[] = {NULL};

			newargv[0] = lineptr;

			if (execve(lineptr, newargv, newenviron) == -1)
			{
				printf("%s: No such file or directory\n", argv[argc - 1]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(lineptr);
	return (0);
}
