#include "header_shell.h"

/**
 * free_mem - A func that frees all the mem allocated for instruct
 * @instruct: The pointer to the allocated memory to be freed
 * Return: Nothing
 */

void free_mem(char **instruct)
{
	size_t k = 0;

	if (instruct == NULL)
		return;

	while (instruct[k])
	{
		free(instruct[k]);
		k++;
	}

	if (instruct[k] == NULL)
		free(instruct[k]);
	free(instruct);
}

/**
 * free_exit - A func that frees all the mem allocated and exit
 * @instruct: The point to allocated instruct memo to free
 * Return: Nothing
 */

void free_exit(char **instruct)
{
	size_t k = 0;

	if (instruct == NULL)
		return;

	while (instruct[k])
	{
		free(instruct[k]);
		k++;
	}

	if (instruct[k] == NULL)
		free(instruct[k]);
	free(instruct);

	exit(EXIT_FAILURE);
}
