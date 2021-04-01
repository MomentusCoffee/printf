#include <stdarg.h>
#include <stdio.h>
#include "headerfile.h"
/**
  * _printf - produces output according to a format
  * @format: character string with directives
  *
  * Return: number of characters printed
  */
int _printf(const char *format, ...)
{
	int i, j;
	int length;

	ops printops[] = {
		{"c", printchar},
		{"s", printstring},
		{"d", printint},
		{"i", printint},
		{"b", printbinary},
		{"r", revstring},
		{"R", printrot13},
		{NULL, NULL}
	};
	va_list arglist;

	i = 0;
	j = 0;
	length = 0;

	va_start(arglist, format);
	if (format == NULL)
		return (-1);
	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			if (format[i] == '%')
			{
				i++;
				while (printops[j].s != NULL)
				{
					while (format[i] == ' ')
					{
						i++;
					}
					if (*(printops[j].s) == format[i])
					{
						length += printops[j].f(arglist);
						break;
					}
					if (format[i] == '%')
					{
						print(format[i]);
						length++;
						break;
					}
					j++;
					if (printops[j].s == NULL)
					{
						if (format[--i] == ' ')
						{
							print('%');
							print(' ');
							length += 2;
						}
						else
						{
							print('%');
							length++;
						}

					}

				}

			}
			else
			{
				print(format[i]);
				length++;
			}
			i++;
		}
	}
	return (length);
}
