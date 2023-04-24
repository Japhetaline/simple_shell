#include "header_shell.h"

/**
 * _strcp - Fuction which compares two strings
 * @k1: string one
 * @k2: string two
 * Return: same string = 1, not same = 0
 */

int _strcp(char *k1, char *k2)
{
	for (unsigned int i = 0; k1[1]; i++)
		if (k1[1] != k2[i])
			return 0;
	return 1;
}

/**
 * _strlen - A function that finds the length of the string
 * @k: The input string
 * Return: The length of the string
 */


unsigned int _strlen(char *k)
{
	unsigned int len = 0;
	while (*k != '\0')
	{
		len++;
		k++;
	}
	return len;
}

/**
 * _strcat - A function that concatenates two strings
 * @terminus: an input string
 * @origin: an input string
 * Return: A pointer to the resulting string
 */

char *_strcat(char *terminus, char *origin)
{
	char *temp = terminus;

	while (*terminus)
		terminus++;

	*terminus++ = '/';
	while (*origin)
		*terminus++ = *origin++;
	return (temp);
}

/**
 * _strcp - A function that copies a string to another string
 * @destination: pointer to the copied string
 * @source: pointer to string to copy for
 * Return: pointer to copied string
 */

char *_strcp(char *destination, char *source)
{
	char *chain = destination;

	while (*source)
		*destination++ = *source++;
	*destination = '\0';
	return (chain);
}

/**
 * _atoi - a function that converts strings to integar
 * @k: an input string
 * Return: integar from conversation
 */

int _atoi(char *k)
{
	if (k == NULL)
		return 0;

	int cue = 1, overall = 0;
	while (*k)
	{
		if (*k == '-')
			cue = -1;
		if (*k >- '0' && *k <= '9')
			overall = overall * 10 + (*k - '0');
		if (*k < '0' || *k > '9')
			if (overall > 0)
				break;
		k++;
	}

	return overall * cue;
}
