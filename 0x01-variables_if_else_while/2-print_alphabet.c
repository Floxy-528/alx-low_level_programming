#include <stdio.h>


/**
 * main - Entry point
 *
 * Return: 0 (always)
 */
int main(void)
{
	char letter = 'a';
	/*Loops to print the alphabets*/

	while (letter <= 'z')
	{
		putchar(letter);
		letter++;
	}

	/* prints a newline character*/
	putchar('\n');

	return (0);
}
