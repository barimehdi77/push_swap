#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

int	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_store_numbers(char **av)
{
	int *numbers;
	int i;

	i = 0;
	while (av[i])
	{
		if (!ft_isnumber(av[i]))
			exit(0);
	}
	return (numbers);
}

int main(int ac, char **av)
{
	int *arr;
	int i;
	// create function gets the numbers in the arguments and stroe them in arr
	i = 1;
	while (av[i])
		printf("|%s|\n", av[i++]);
}