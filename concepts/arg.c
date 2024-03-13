#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **argv)
{
	while (*argv != NULL)
	{
		printf("%s\n", *argv);
		argv++;
	}
	return(0);

}
