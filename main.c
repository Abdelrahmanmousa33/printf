#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char tchar = 'H';
	char *stest = "the string test";
	int count;

	printf("%lu\n", strlen(stest));
	count = _printf("%s\n", stest);
	printf("%d\n", count);
	_printf("this is the char %c \n", tchar);
	return (0);
}
