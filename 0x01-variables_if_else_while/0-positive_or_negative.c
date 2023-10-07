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
	else if (n == 0)
		/*prints zero if number is = 0*/
	{
		printf("%d is zero/n", n);
	}
	else
		/*prints negative number if n is < 0*/
	{
		printf("%d is negative/n", n);
	}
	
	return (0);
}
