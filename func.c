#include "main.h"
/**
 * customReadInput - Reads a line of input from the user.
 *
 * Return: A dynamically allocated string containing the input line.
 *         Returns NULL if an error occurs or if the input is empty.
 */
char *customReadInput(void)
{
	char *input = NULL;
	size_t length = 0;
	ssize_t bytesRead;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}

	bytesRead = getline(&input, &length, stdin);

	if (bytesRead == -1)
	{
		if (input != NULL)
		free(input);
		return (NULL);
	}

	return (input);
}

/**
 * countTokens - Counts the number of tokens in a string.
 * @input: The input string to be tokenized.
 *
 * Return: The number of tokens in the input string.
 */
int countTokens(char *input)
{
	char *dup = NULL;
	char *token = NULL;
	int tokenCount = 0;

	dup = _strup(input);
	if (dup == NULL)
		return (0);

	token = strtok(dup, DELIMITER);

	while (token)
	{
		tokenCount++;
		token = strtok(NULL, DELIMITER);
	}
	free(dup);
	return (tokenCount);
}

/**
 * tokenizeString - Tokenizes a string into an array of strings.
 * @input: The input string to be tokenized.
 * @tokenCount: The number of tokens in the input string.
 *
 * Return: An array of strings (tokens) obtained from the input string.
 *         Returns (NULL) if an error occurs or if the input is empty.
 */
char **tokenizeString(char *input, int tokenCount)
{
	char **cmd = NULL;
	char *token = NULL;
	int index = 0;

	cmd = (char **)malloc(sizeof(char *) * (tokenCount + 1));
	if (cmd == NULL)
	return (NULL);

	token = strtok(input, DELIMITER);

	while (token)
	{
		cmd[index] = _strup(token);
		token = strtok(NULL, DELIMITER);
		index++;
	}

	cmd[index] = NULL;
	free(input), input = NULL;
	return (cmd);
}

/**
 * stringTokenizer - Tokenizes a string into an array of strings.
 * @input: The input string to be tokenized.
 *
 * Return: An array of strings (tokens) obtained from the input string.
 *         Returns (NULL) if an error occurs or if the input is empty.
 */
char **stringTokenizer(char *input)
{
	char *dup = NULL;
	char **cmd = NULL;
	int tokenCount;

	if (input == NULL)
		return (NULL);

	dup = _strup(input);

	if (dup == NULL)
	return (NULL);

	tokenCount = countTokens(input);
	if (tokenCount == 0)
	{
		free(dup), dup = NULL;
		free(input), input = NULL;
		return (NULL);
	}

	cmd = tokenizeString(input, tokenCount);
	free(dup), dup = NULL;

	return (cmd);
}

/**
 * execute_command - Executes a command with arguments.
 * @comnd: An array of strings representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @idx: The index of the command in the execution sequence.
 *
 * Return: The exit status of the executed command.
 */
int execute_command(char **comnd, char **argv, int idx)
{
	pid_t pid;
	int status;
	char *all_cmd;

	all_cmd = path_search(comnd[0]);

	if (all_cmd == NULL)
	{
	_perror(argv[0], comnd[0], idx);
	freetool(comnd);
	return (127);
	}

	pid = fork();

	if (pid == 0)
	{

		if (execve(all_cmd, comnd, environ) == -1)
		{
			free(all_cmd), all_cmd = NULL;
			freetool(comnd);
			exit(100);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		freetool(comnd);
		free(all_cmd), all_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}

