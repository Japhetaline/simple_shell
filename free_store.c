#include "header_shell.h"

/**
 * free_mem - A function that frees all the memory allocated for instruct
 * @instruct: The pointer to allocated memory to free
 * Return: Nothing
 */

void free_mem(char **instruct)
{
	if (instruct == NULL)
	{
		return;
	}

	for (size_t i = 0; instruct[i] != NULL; i++)
	{
		free(instruct[i]);
	}

	free(instruct);
}

/**
 * free_exit - A function that frees all the memory allocated and exit
 * @instruct: The pointer to allocated instruct memory to free
 * Return: Nothing
 */

void free_exit(char **instruct)
{
	if (command == NULL)
	{
		return;
	}

	size_t i = 0;
	while (instruct[i] != NULL)
	{
		free(instruct[i]);
		i++;
	}
	free(instruct[i]);
	free(instruct);

	exit(EXIT_FAILURE)
}
