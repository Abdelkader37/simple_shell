#include "main.h"
/**
 * put_env - Prints the environment variables to the standard output.
 * @cmd: Array of strings representing the input command.
 * @status: Pointer to an integer representing the shell status.
 */
void put_env(char **cmd, int *status)
{
	int x = 0;

	while (environ[x])
	{
		write(STDOUT_FILENO, environ[x], _strlen(environ[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
	freetool(cmd);
	(*status) = 0;
}

/**
 * _absolut - Checks if a string represents a valid non-negative integer.
 * @str: The input string to be checked.
 *
 * Return: 1 if the string is a valid non-negative integer, 0 otherwise.
 */
int _absolut(char *str)
{
	while (*str != '\0')
	{
	if (*str < '0' || *str > '9')
	{
		return (0);
	}
	str++;
	}
	return (1);
}

/**
 * int_to_str2 - Converts a string .
 * @str: The input string to be converted.
 *
 * Return: The integer value represented by the input string.
 */
int int_to_str2(char *str)
{
	int x, n = 0;

	for (x = 0; str[x]; x++)
	{
		n = n * 10;
		n += (str[x] - '0');
	}
	return (n);
}

