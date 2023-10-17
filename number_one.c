#include "main.h"

/**
 * form_char - print char characater.
 * @index: list of argments
 * Return: the number of characters from string.
 */
int form_char(va_list index)
{
	char character = va_arg(index, int);

	putchar(character);
	return (1);
}
/**
 * form_str - print string characater.
 * @index: list of argments
 * Return: the number of characters from string.
 */
int form_str(va_list index)
{
	int length1 = 0;
	const char *str;

	str = va_arg(index, const char*);

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
				length += form_str(index);
			}
			else if (*format == '%')
			{
				putchar('%');
				length++;
			}
			else 
			{
				putchar('%');
				putchar(*format);
				length += 2;
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
