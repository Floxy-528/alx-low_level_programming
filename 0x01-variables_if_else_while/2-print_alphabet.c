#include <stdio.h>

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
