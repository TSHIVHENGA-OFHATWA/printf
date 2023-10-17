#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: to be printed
 * Return: the number of characters printed.
 */

int _printf(const char *format, ...)
{
	char *output_ptr;
	char *output;
	int total_characters;
	char *str;
	va_list args;
	va_start(args, format);

	total_characters = 0;

	output = (char *)malloc(1000 * sizeof(char)); 
	
	if (output == NULL) 
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	
	output_ptr = output;
	
	while (*format) 
	{
		if (*format == '%')
		{
			format++; 
			if (*format == 'c') 
			{
				char c = (char)va_arg(args, int);
				*output_ptr = c;
				output_ptr++;
				total_characters++;
			} else if (*format == 's') 
			{
				str = va_arg(args, char *);

				while (*str)
				{
					*output_ptr = *str;
					output_ptr++;
					str++;
					total_characters++;
				}
			}
			else if (*format == '%') 
			{
				*output_ptr = '%';
				output_ptr++;
				total_characters++;
			}
		}
		else
		{
			*output_ptr = *format;
			output_ptr++;
			total_characters++;
		}
		format++;
	}

	*output_ptr = '\0';
	printf("%s", output);
	
	free(output);
	
	va_end(args);
	return (total_characters);
}
