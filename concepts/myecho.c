#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	size_t j;

	for (j = 0; j < argc; j++)
		printf("argv[%zu]: %s\n", j, argv[j]);

	return(0);
}
