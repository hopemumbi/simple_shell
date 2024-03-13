#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	pid_t child_pid;
	int status;

	/*display a prompt and wait for user to enter command*/
	printf("$ ");
	while(getline(&lineptr, &n, stdin) != -1)
	{
		lineptr = strtok(lineptr, "\n");

		child_pid = fork();
		if (child_pid == 0)
		{
			char *argv[] = {NULL, NULL};
			argv[0] = lineptr;

			if ((execve(argv[0], argv, NULL) == -1))
			{
				printf("%s: No such file or directory\n", lineptr);
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
		printf("$ ");
	}
	free(lineptr);
	return (0);
}
