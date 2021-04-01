#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "headerfile.h"
/**
 * printrot13 - encodes string to rot13
 * @a: argument
 *
 * Return: length of sentence
 */
int printrot13(va_list a)
{
	int i;
	int j;
	char *s;
	char *ns;
	int count = 0;

	char lower[27] = "abcdefghijklmABCDEFGHIJKLM";
	char upper[27] = "nopqrstuvwxyzNOPQRSTUVWXYZ";

	s = va_arg(a, char *);
	i = 0;
	while (s[i] != '\0')
	{
		count++;
		i++;
	}

	ns = malloc(sizeof(char) * (count + 1));

	if (ns == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		ns[i] = s[i];
		i++;
	}

	for (i = 0; ns[i] != '\0'; i++)
		for (j = 0; j < 26; j++)
		{
			if (ns[i] == lower[j])
			{
				ns[i] += 13;
			}
			else if (ns[i] == upper[j])
				ns[i] -= 13;
		}
	for (i = 0; ns[i] != '\0'; i++)
		print(ns[i]);
	free(ns);
	return (i);
}
/**
  * revstring - prints unsigned ints to binary
  * @a: argument type
  *
  * Return: length
  */
int revstring(va_list a)
{
	char *s;
	int i;
	int count;

	i = 0;
	count = 0;

	s = va_arg(a, char *);

	while (s[i] != '\0')
	{
		i++;
		count++;
	}
	i--;
	while (i >= 0)
	{
		print(s[i]);
		i--;
	}
	return (count);
}
/**
  * printbinary - prints unsigned ints to binary
  * @a: argument type
  *
  * Return: length
  */
int printbinary(va_list a)
{
	char *s;
	int count;
	unsigned int num, numcopy;
	int i;
	int c;

	i = 0;
	c = 1;
	count = 0;

	num = va_arg(a, unsigned int);

	numcopy = num;

	while (numcopy > 0)
	{
		numcopy /= 2;
		c++;
	}

	s = malloc(sizeof(unsigned int) * (c - 1));

	if (s == NULL)
	{
		free(s);
		return (0);
	}
	if (num == 0)
	{
		print(0 + '0');
		free(s);
		return (1);
	}
	while (num > 0)
	{
		s[i] = num % 2;
		num /= 2;
		i++;
	}
	count = i;
	i--;
	while (i >= 0)
	{
		print(s[i] + '0');
		i--;
	}
	free(s);
	return (count);
}
