#include "header_shell.h"

/**
 * _strcp - Fuction which compares two strings
 * @k1: string one
 * @k2: string two
 * Return: same string = 1, not same = 0
 */

int _strcp(char *k1, char *k2)
{
	unsigned int j = 0;

	while (k1[j])
	{
		if (k1[j] != k2[j])
			return (0);

		j++;
	}

	return (1);
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
	return (len);
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
 * _strcopy - A function that copies a string to another string
 * @destination: pointer to the copied string
 * @source: pointer to string to copy for
 * Return: pointer to copied string
 */

char *_strcopy(char *destination, char *source)
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
	int cue = 1;
	unsigned int overall = 0;
	char zero_label = 0;

	if (k == NULL)
		return (0);
	while (*k)
	{
		if (*k == '-')
			cue *= -1;
		if (*k >= '0' && *k <= '9')
		{
			zero_label = 1;
			overall = overall * 10 + (*k - '0');
		}
		else if (*k < '0' || *k > '9')
		{
			if (zero_label == 1)
				break;
		}
		k++;
	}
	if (cue < 0)
		overall = (-1 * (overall));
	return (overall);
}
