#include "header_shell.h"

/**
 * enforce - func that enforces a instruct
 * @instruct: pointer to a tokenized instruct
 * @name: name of the shell
 * @env: pointer to the environ variables
 * @spiral: number of enforced spiral
 * Return: Nothing
 */

void enforce(char **instruct, char *name, char **env, int spiral)
{
	char **routes = NULL, *full_route = NULL;
	struct stat er;
	unsigned int k = 0;

	if (_strcp(instruct[0], "env") != 0)
		proof_env(env);
	if (stat(instruct[0], &er) == 0)
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
			if (stat(full_route, &er) == 0)
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
 * proof_env - func that prints all environ variables
 * @env: pointer to environ variable
 * Return: Nothing
 */

void proof_env(char **env)
{
	size_t k = 0, length = 0;

	while (env[k])
	{
		length = _strlen(env[k]);
		write(STDOUT_FILENO, env[k], length);
		write(STDOUT_FILENO, "\n", 1);
		k++;
	}
}

/**
 * _getROUTE - funct to get the full value from environ
 * variable PATH
 * @env: pointer to environ variable
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
 * msg_error - funct that prints message not found
 * @name: the name of shell
 * @spiral: number of spirals
 * @instruct: pointer to the tokenized instruct
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
