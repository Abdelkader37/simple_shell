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
 
