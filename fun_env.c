#include "main.h"
/**
 * _perror - Prints a command not found error message.
 * @nm: Program name or identifier.
 * @cmd: Command or input associated with the error.
 * @i: Numeric index or identifier associated with the error.
 */
void _perror(char *nm, char *cmd, int i)
{
	char *idx, error[] = ": not found\n";

	idx = int_to_str(i);

	write(STDERR_FILENO, nm, _strlen(nm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, error, _strlen(error));
	free(idx);
}

#include "main.h"

/**
 * non_input - Checks if the provided command is a non-interactive command.
 * @cmd: The input command to be checked.
 *
 * Return: 1 if the command is a non-interactive command, 0 otherwise.
 */
int non_input(char *cmd)
{
	char *input[] = {"exit", "env"};
	int x = 0;

	while (x < 2)
	{
	if (str_comp(cmd, input[x]) == 0)
	{
	return (1);
	}
	x++;
	}
	return (0);
}

/**
 * input_built - Handles built-in commands within the shell.
 * @input: Array of strings representing the input command.
 * @argv: Array of strings representing the arguments.
 * @status: Pointer to an integer representing the shell status.
 * @i: Integer representing the command index.
 */
void input_built(char **input, char **argv, int *status, int i)
{
	if (str_comp(input[0], "exit") == 0)
		_break(input, argv, status, i);
	else if (str_comp(input[0], "env") == 0)
		put_env(input, status);
}

/**
 * _perror2 - Prints an error message to the standard error output.
 * @argv: Array of strings representing the arguments.
 * @i: Integer representing the command index.
 * @error: String representing the error message.
 * @input1: Additional input information.
 */
void _perror2(char **argv, int i, char *error, char *input1)
{
	char *idx = int_to_str(i);

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error, _strlen(error));
	write(STDERR_FILENO, input1, _strlen(input1));
	write(STDERR_FILENO, "\n", 1);

	free(idx);
}

/**
 * _break - Handles the "exit" command.
 * @input: Array of strings representing the input command.
 * @argv: Array of strings representing the arguments.
 * @status: Pointer to an integer representing the shell status.
 * @i: Integer representing the command index.
 */
void _break(char **input, char **argv, int *status, int i)
{
	int va;
	char *error = "exit: Illegal number: ";

	if (input[1])
	{
	if (_absolut(input[1]))
	{
		va = int_to_str2(input[1]);
	}
	else
	{
		_perror2(argv, i, error, input[1]);
		freetool(input);
		return;
	}
	}
	else
	{
		va = *status;
	}

	freetool(input);
	exit(va);
}

