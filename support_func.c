#include "header_shell"

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


