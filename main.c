#include <stdio.h>
#include <unistd.h>


int main(int ac, char **av)
{
	int *arr;
	int i;
	// create function gets the numbers in the arguments and stroe them in arr
	i = 0;
	while (av[i])
		printf("|%s|\n", av[i++]);
}