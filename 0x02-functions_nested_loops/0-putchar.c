#include <main.h>

/**
 * _putchar - writes a character to the standard output
 * @c: The character to print
 *
 * Return: On success 1, on error -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	_putchar('_');
	_putchar('p');
	_putchar('u');
	_putchar('t');
	_putchar('c');
	_putchar('h');
	_putchar('a');
	_putchar('r');
	_putchar('\n');
	return (0);
}
