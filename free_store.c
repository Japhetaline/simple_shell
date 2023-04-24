#include "header_shell.h"

/**
 * free_mem - A function that frees all the memory allocated for instruct
 * @instruct: The pointer to allocated memory to free
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
 * free_exit - A function that frees all the memory allocated and exit
 * @instruct: The pointer to allocated instruct memory to free
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
