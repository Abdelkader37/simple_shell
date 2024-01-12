#include "main.h"
/**
 * main - Entry point for the shell program.
 * @ac: The number of arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: Always returns 0 on successful execution.
 */
int main(int ac, char **argv)
{
	char *input = NULL;
	char **comnd = NULL;
	int status = 0, i = 0;

	(void)ac;

	while (1)
	{
	input = customReadInput();
	if (input == NULL)
	{
	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "\n", 1);
	return (status);
	}
	i++;

	comnd = stringTokenizer(input);
	if (comnd == NULL)
	continue;
	else if (non_input(comnd[0]))
	{
	input_built(comnd, argv, &status, i);
	}
	else
	{
	status = execute_command(comnd, argv, i);
	}
	}
}
