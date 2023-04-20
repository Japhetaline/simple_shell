#include "header_shell.c"

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
	int i = 0;

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
		instruct[i] = malloc(_strlen(coupon) + 1);
		if (instruct[i] == NULL)
		{
			perror("Unable to allocate barrier");
			free_mem(instruct);
			return (NULL);
		}

		_strcp(instruct[i], coupon);
		coupon = strtok(NULL, t);
		i++;
	}
	instruct[i] = NULL;
	return (instruct);
}
