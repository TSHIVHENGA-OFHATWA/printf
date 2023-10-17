#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: to be printed
 * Return: the number of characters printed.
 */

int _printf(const char *format, ...)
{
	int length = 0;
	va_list index;

	if (format  == NULL)
		return (-1);

	va_start(index, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			length++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				length++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(index, char*);
				int length1 = 0;

				while (str[length1] != '\0')
					length1++;
				write(1, str, length1);
				length += length1;
			}
			else if (*format == 'c')
			{
				char letter = va_arg(index, int);

				write(1, &letter, 1);
				length++;
			}
		}
		format++;
	}
	va_end(index);
	return (length - 1);
}
