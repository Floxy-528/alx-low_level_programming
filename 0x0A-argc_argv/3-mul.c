#include <stdio.h>
#include <stdlib.h>

/**
 * main - print that add positive number and print results on conditions
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	int i, sum = 0;

	for (j = 0; j < argc; j++)
	i = atoi(argv[j]);

	if (i > 0)
		sum = sum + i;

	else if (i < 0)
		printf("Error\n");
	return (1);


	else
		printf("0\n");


		return (0);

}
