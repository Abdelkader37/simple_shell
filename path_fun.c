#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string to be appended.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strcat(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
	*dest = *src;
	dest++;
	src++;
	}

	*dest = '\0';

	return (original_dest);
}

/**
 * path_search - Searches for the full path of a command in the system.
 * @cmd: The command to search for.
 *
 * Return: If found, returns a dynamically allocated string  the full path;
 *         otherwise, returns NULL.
 */
char *path_search(char *cmd)
{
	struct stat st;
	char *_path, *result;
	int i;

	if (cmd == NULL)
	{
		return (NULL);
	}

	for (i = 0; cmd[i]; i++)
	{
	if (cmd[i] == '/')
	{
	if (stat(cmd, &st) == 0)
	{
		return (_strup(cmd));
	}
	return (NULL);
	}
	}

	_path = _getenv("PATH");
	if (_path == NULL)
	{
	return (NULL);
	}

	result = search_in_path(cmd, _path);

	free(_path);
	return (result);
}

/**
 * search_in_path - Searches for a command in each directory in the PATH.
 * @cmd: The command to search for.
 * @_path: The PATH variable containing directories.
 *
 * Return: returns a dynamically allocated string containing full path;
 *         otherwise, returns NULL.
 */
char *search_in_path(char *cmd, char *_path)
{
	char *dir, *all_cmd;
	struct stat st;

	dir = strtok(_path, ":");

	while (dir != NULL)
	{
	all_cmd = malloc(strlen(dir) + strlen(cmd) + 2);
	if (all_cmd != NULL)
	{
	_strcpy(all_cmd, dir);
	_strcat(all_cmd, "/");
	_strcat(all_cmd, cmd);
	if (stat(all_cmd, &st) == 0)
	{
	return (all_cmd);
	}
	free(all_cmd);
	dir = strtok(NULL, ":");
	}
	}

		return (NULL);
}

/**
 * int_to_str - Converts an integer to a string.
 * @n: The integer to be converted.
 *
 * Return: A dynamically allocated string containing the converted integer.
 */
char *int_to_str(int n)
{
	int i = 0;
	int sign = n;
	char s[20];
	char *result;

	if (sign < 0)
	n = -n;

	do

	s[i++] = n % 10 + '0';

	while ((n /= 10) > 0);

	if (sign < 0)
	s[i++] = '-';

	s[i] = '\0';

	reverse(s, i);

	result = _strup(s);

	return (result);
}

/**
 * reverse - Reverses a string in-place.
 * @s: The string to be reversed.
 * @len: The length of the string.
 */
void reverse(char *s, int len)
{
	int i, j;
	char temp;

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
	}
}



