#include "main.h"
/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: If found, returns a duplicated string containing the variable value;
 *         otherwise, returns NULL.
 */
char *_getenv(char *name)
{
	char *dup, *str1, *str2, *inv;
	int i;

	 for (i = 0; environ[i]; i++)
	{
	dup = _strup(environ[i]); 
	str1 = strtok(dup, "=");
	if (str1 != NULL && str_comp(str1, name) == 0)
	{
	str2 = strtok(NULL, "\n");
	if (str2 != NULL)
		{
		inv = _strup(str2); 
		free(dup);
		return (inv);
		}
	}
	free(dup);
	}
	return (NULL);
}

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
 * path_search - Searches for the full path of a command in the PATH directories.
 * @cmd: The command to search.
 *
 * Return: If found, returns a duplicated string containing the full path;
 *         otherwise, returns NULL.
 */
char *path_search(char *cmd)
{
	char *dir, *_path, *all_cmd;
	struct stat st;
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
		free(_path);
		return (all_cmd);
		}
		free(all_cmd);
	dir = strtok(NULL, ":");
	}
	}

	free(_path);
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
	{
	s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

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



