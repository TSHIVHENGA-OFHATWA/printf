#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: to be printed
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list prints;
	char *str;
	int length = 0;

	va_start(prints, format);

	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char character = va_arg(prints, int);

				putchar(character);
				length++;
			}
			else if (*format == 's')
			{
				str = va_arg(prints, char*);
				for (; *str != '\0'; str++)
				{
					putchar(*str);
					length++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				length++;
			}
		}
		else
		{
			putchar(*format);
			length++;
		}
	}
	va_end(prints);
	return (length);
}
