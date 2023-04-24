#include "header_shell.h"

/**
 * tokening - A function that split and create a full string instruct
 * @t: The delimeter for strtok.
 * @barrier: The pointer to input string.
 * Return: A string with full instruct
 */

char **tokening(char *barrier, const char *t)
{
	char *coupon = NULL, **instruct = NULL;
	size_t barsize = 0;
	int k = 0;

	if (barrier == NULL)
		return (NULL);

	barsize = _strlen(barrier);
	instruct = malloc((barsize + 1) * sizeof(char *));
	if (instruct == NULL)
	{
		perror("Unable to allocate barrier");
		free(barrier);
		free_mem(instruct);
		exit(EXIT_FAILURE);
	}

	coupon = strtok(barrier, t);
	while (coupon != NULL)
	{
		instruct[k] = malloc(_strlen(coupon) + 1);
		if (instruct[k] == NULL)
		{
			perror("Unable to allocate barrier");
			free_mem(instruct);
			return (NULL);
		}

		_strcopy(instruct[k], coupon);
		coupon = strtok(NULL, t);
		k++;
	}
	instruct[k] = NULL;
	return (instruct);
}
