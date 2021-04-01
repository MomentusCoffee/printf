#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "headerfile.h"
/**
  * printstring - prints strings
  * @a: argument type
  *
  * Return: length
  */
int printstring(va_list a)
{
	char *s;
	int i;
	char *n;

	n = "(null)";

	i = 0;

	s = va_arg(a, char *);
	if (!(s))
	{
		while (*n != '\0')
		{
			print(*n);
			n++;
		}
		return (6);

	}
	while (s[i] != '\0')
	{
		print(s[i]);
		i++;
	}
	return (i);
}
/**
  * printchar - prints chars
  * @a: argument type
  *
  * Return: length
  */
int printchar(va_list a)
{

	print(va_arg(a, int));
	return (1);
}
/**
  * printint - prints ints
  * @a: argument passed in
  *
  * Return: length
  */
int printint(va_list a)
{
	int num;
	int mult;
	int count;
	unsigned int numcopy;
	unsigned int n;
	int len;

	num = va_arg(a, int);
	mult = 1;
	count = 1;

	if (num < 0)
	{
		print ('-');
		n = num * -1;
		numcopy = n;
	}
	else
	{
		n = num;
		numcopy = num;
	}
	while (numcopy >= 10)
	{
		numcopy /= 10;
		mult *= 10;
		count++;
	}
	if (num < 0)
		len = count + 1;
	else
		len = count;
	while (count > 1)
	{
		if ((n / mult) < 10)
		{
			print((n / mult + '0'));
		}
		else
		{
			print(((n / mult) % 10) + '0');
		}
		count--;
		mult /= 10;
	}
	print(n % 10 + '0');
	return (len);
}
