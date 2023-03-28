#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
/**
 * _printf - a fucntion that prints anything
 * @format: the input to be printed
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0, i = 0;
	va_list ptr;
	char c;
	char *str;

	va_start(ptr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case '%':
					c = va_arg(ptr, int);
					printed_chars += write(1, &format[i + 1], 1);
					break;
				case 'c':
					c = va_arg(ptr, int);
					printed_chars += write(1, &c, 1);
					break;
				case 's':
					str = va_arg(ptr, char *);
					printed_chars += write(1, str, strlen(str));
					break;
			}
			i = i + 2;
			continue;
		}
		else
		{
			printed_chars += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(ptr);
	return (printed_chars);
}
