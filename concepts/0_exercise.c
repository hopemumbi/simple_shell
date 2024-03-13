#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
	/*declare variables to hold the PID*/
	pid_t child_pid;
	int i, status;

	/*loop to create five child processes*/
	for (i = 0; i < 5; i++)
	{
		/*fork a child*/
		child_pid = fork();

		/*check for fork failure*/
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		/*the child process*/
		else if (child_pid == 0)
		{
			char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
			/*executes the command ls -l /tmp in the child process.*/
			execve(argv[0], argv, NULL);
			/*If execve fails, print an error message and exit*/
			perror("execve");
			return (1);
		}
		/*parent process*/
		else
		{
			/*Wait for the child process to finish before creating a new one*/
			wait(&status);
		}
	}
	/*Parent process exits after all children have finished*/
	return (0);
}
