#include "main.h"

/**
 * form_char - print char characater.
 * @index: list of argments
 * Return: the number of characters from string.
 */
int form_char(va_list index)
{
	int length = 0;
	char character = va_arg(index, int);

	putchar(character);
	length++;
	return (1);
}
/**
 * form_str - print string characater.
 * @index: list of argments
 * Return: the number of characters from string.
 */
int form_str(va_list index)
{
	int length1;
	char *str;

	str = va_arg(index, char*);
	while (*str != '\0')
	{
		putchar(*str);
		str++;
		length1++;
	}
	return (length1);
}

/**
 * _printf - produces output according to a format.
 * @format: to be printed
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list index;
	int length1, length = 0;

	va_start(index, format);

	if (format == NULL)
		return (-1);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == 'c')
			{
				length += form_char(index);
			}
			else if (*format == 's')
			{
				length1 = form_str(index);
				length += length1;
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
	va_end(index);
	return (length);
}
