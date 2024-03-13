#include <stdio.h>
int main(int ac, char **av)
{
	int i;
	/** 
	 * print all arg
	 * do not use ac
	 */
	for(;av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
