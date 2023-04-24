#include "header_shell.h"

/**
 * procreate - function that create a sub proocess
 * @instruct: pinter to tokenized instruct
 * @name: pointer to the name of shell
 * @env: pointer to the environmental variable
 * @spiral: number of executed spiral
 */

void procreate(char **instruct, char *name, char **env, int spiral)
{
	int parent_id = 0;
	int stature = 0;
	int delay_error = 0;

	parent_id = fork();
	if (parent_id < 0)
	{
		perror("Error: ");
		free_exit(instruct);
	}
	else if (parent_id == 0)
	{
		enforce(instruct, name, env, spiral);
		free_mem(instruct);
	}
	else
	{
		delay_error = waitpid(parent_id, &stature, 0);
	       if (delay_error < 0)
	       {
		       free_exit(instruct);
	       }
	       free_mem(instruct);
	}
}

/**
 * change_dr - Function that changes working directory.
 * @trail: The new working directory
 * Return: success(0), fail (-1)
 */

int change_dr(const char *trail)
{
	char *bar = NULL;
	size_t weight = 1024;

	if (trail == NULL)
		trail = getcwd(bar, weight);

	if (chdir(trail) == -1)
	{
		perror(trail);
		return (98);
	}
	return (1);
}
