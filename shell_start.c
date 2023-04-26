#include "header_shell.h"

/**
 * main - This is a function that runs our shell
 * @argc: The number of inputed arguments.
 * @argv: pointers to array of inputed arguments
 * @env: pointer to array of environmental variables
 * Return: 0
 */

int main(int argc, char **argv, char **env)
{
	char *barrier = NULL, **instruct = NULL;
	size_t barrier_size = 0;
	ssize_t chars_read = 0;
	int spiral = 0;
	(void)argc;

	while (1)
	{
		spiral++;
		shell_swift();
		signal(SIGINT, operate);
		chars_read = getline(&barrier, &barrier_size, stdin);
		if (chars_read == EOF)
			_EOF(barrier);
		else if (*barrier == '\n')
			free(barrier);
		else
		{
			barrier[_strlen(barrier) - 1] = '\0';
			instruct = tokening(barrier, " \0");
			free(barrier);
			if (_strcp(instruct[0], "exit") != 0)
				exit_shell(instruct);
			else if (_strcp(instruct[0], "cd") != 0)
				change_dr(instruct[1]);
			else
				procreate(instruct, argv[0], env, spiral);
		}
		fflush(stdin);
		barrier = NULL, barrier_size = 0;
	}
	if (chars_read == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * shell_swift - This is a function that prints the shell swift
 * Return: Nothing
 */

void shell_swift(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "hsh$ ", 5);
}

/**
 * operate - A function that operate Ctrl+C signal
 * @indicators: The indicator to operate
 * Return: Nothing
 */

void operate(int indicators)
{
	(void)indicators;
	write(STDOUT_FILENO, "/nhsh$ ", 6);
}

/**
 * _EOF - A function that checks if buffer is EOF
 * @barrier: The pointer to the input string
 * Return: Nothing
 */

void _EOF(char *barrier)
{
	if (barrier)
	{
		free(barrier);
		barrier = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "/n", 1);
	free(barrier);
	exit(EXIT_SUCCESS);
}

/**
 * exit_shell - A function that exits the shell.
 * @instruct: The pointer to tokenized instruct.
 * Return: Nothing
 */

void exit_shell(char **instruct)
{
	int condition = 0;

	if (instruct[1] == NULL)
	{
		free_mem(instruct);
		exit(EXIT_SUCCESS);
	}

	condition = _atoi(instruct[1]);
	free_mem(instruct);
	exit(condition);
}
