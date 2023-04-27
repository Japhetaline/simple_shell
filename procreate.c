#include "header_shell.h"

/**
 * procreate - func that create a sub process
 * @instruct: pointer to tokenized instruct
 * @name: pointer to the shell name
 * @env: pointer to the environ variable
 * @spiral: numb of executed spiral
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
 * change_dr - func that changes working directory.
 * @trail: new working directory
 * Return: 0 for success and -1 for fail
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
