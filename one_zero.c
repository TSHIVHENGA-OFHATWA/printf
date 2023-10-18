#include "main.h"
/**
 * mall_str - produces output according to a format.
 * @index: list of arguments
 * Return: the number of characters printed.
 */
int mall_str(va_list index)
{
	const char *ptr = va_arg(index, const char *);
	int i, len = 0;
	char *cpy = NULL;

	if (ptr == NULL)
		ptr = "(null)";
	while (ptr[len] != '\0')
		len++;
	cpy = malloc(len + 1);
	if (cpy == NULL)
		return (-1);
	i = 0;
	while (i < len)
	{
		cpy[i] = ptr[i];
		i++;
	}
	cpy[len] = '\0';
	write(1, cpy, len);
	free(cpy);
	return (len);
}
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
				length += mall_str(index);
			}
			else if (*format == 'c')
			{
				char letter = va_arg(index, int);

				write(1, &letter, 1);
				length++;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
					length++;
			}
		}
		format++;
	}
	va_end(index);
	return (length);
}
