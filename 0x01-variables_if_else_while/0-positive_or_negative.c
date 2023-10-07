#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/**
 * main - main function
 *
 * Return: always 0
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes here */
	if (n > 0)
		/*print positive number if n > 0*/
	{
		printf("%d is positive/n", n);
	}
	else if (n < 0)
		/*prints negative number if n < 0*/
	{
		printf("%d is negative/n", n);
	}
	else
		/*prints zero*/
	{
		printf("%d is zero/n", n);
	}

	return (0);
}
