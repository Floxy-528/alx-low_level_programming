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
	int var;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	var = n % 10;
	/* your code goes here */
	if (var > 5)
		/*prints last digit if var > 5*/
	{
		printf("Last digit of %d is %d and is greater than 5\n", n, var);
	}
	else if (var < 6 && var != 0)
	{
		/*prints last digit if var < 6 && != 0*/

		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, var);
	}
	else
		/*prints last digit if var == 0*/
	{
		printf("Last digit of %d is %d and is 0\n", n, var);
	}

	return (0);
}
