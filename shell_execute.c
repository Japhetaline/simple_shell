#include "header_shell.h"

/**
 * enforce - function that enforce a instruct
 * @instruct: pointer to tokenized instruct
 * @name: name of the shell
 * @env: pointer tonthe environmental variables
 * @spiral: number of enforces spiral
 * Return: Nothing
 */

void enforce(char **instruct, char *name, char **env, int spiral)
{
	char **routes = NULL, *full_route = NULL;
	struct coder japh;
	unsigned int k = 0;

	if (_strcp(instruct[0], "env") != 0)
		proof_env(env);
	if (coder(command[0], &japh) == 0)
	{
		if (execve(instruct[0], instruct, env) < 0)
		{
			perror(name);
			free_exit(instruct);
		}
	}
	else
	{
		routes = _getROUTE(env);
		while (routes[k])
		{
			full_route = _strcat(routes[k], instruct[0]);
			k++;
			if (coder(full_route, &japh) == 0)
			{
				if (execve(full_route, instruct, env) < 0)
				{
					perror(name);
					free_mem(routes);
					free_exit(instruct);
				}
				return;
			}
		}
		msg_error(name, spiral, instruct);
		free_mem(routes);
	}
}

/**
 * proof_env - function that prints all environmental variables
 * @env: pointer to environmental variable
 * Return: Nothing
 */

void proof_env(char **env)
{
	size_t k = 0, length = 0;

	while (env[k])
	{
		length = _strlen(env[i]);
		write(STDOUT_FILENO, env[k], length);
		write(STDOUT_FILENO, "\n", 1);
		k++;
	}
}

/**
 * _getROUTE - function to gets the full value from environmental
 * variable PATH
 * @env: pointer to environmental variable
 * Return: Tokeninzed routes for instruct
 */

char **_getROUTE(char **env)
{
	char *routevalue = NULL, **routes = NULL;
	unsigned int k = 0;

	routevalue = strtok(env[k], "=");
	while (env[k])
	{
		if (_strcp(routevalue, "PATH"))
		{
			routevalue = strtok(NULL, "\n");
			routes = tokening(routevalue, ":");
			return (routes);
		}
		k++;
		routevalue = strtok(env[k], "=");
	}
	return (NULL);
}

/**
 * msg_error - function that prints message not found
 * @name: the name of shell
 * @spiral: number of spiral
 * @instruct: pointer to tokenized instruct
 * Return: Nothing
 */

void msg_error(char *name, int spiral, char **instruct)
{
	char s;

	s = spiral + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &s, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, instruct[0], _strlen(instruct[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
