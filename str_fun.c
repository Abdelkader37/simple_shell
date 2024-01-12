#include "main.h"
#include "main.h"
/**
 * _strup - Duplicates a string.
 * @str: The input string to be duplicated.
 *
 * Return: return to null and duplicate.
 */
char *_strup(const char *str)
{

	char *duplicate;
	size_t length;

	if (str == NULL)
	return (NULL);

	length = _strlen(str) + 1;

	duplicate = (char *)malloc(length);

	if (duplicate != NULL)
	_strcpy(duplicate, str);

	return (duplicate);
}

/**
 * _strlen - Calculates the length of a string.
 * @str: The input string.
 *
 * Return: The length of the input string.
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
	length++;
	}
	return (length);
}

/**
 * str_comp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: An integer
 */
int str_comp(char *s1, char *s2)
{

	while (*s1 && (*s1 == *s2))
	{
	s1++;
	s2++;
	}
	return ((int)(*s1) - (int)(*s2));
}

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination buffer for the copied string.
 * @src: The source string to be copied.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *dest, const char *src)
{

	char *originalDest = dest;

	while ((*dest++ = *src++) != '\0')
	{

	}

	return (originalDest);
}

/**
 * freetool - Frees memory allocated for an array of strings.
 * @arr: The array of strings to be freed.
 */
void freetool(char **arr)
{

	int i;

	if (arr == NULL)
	return;

	for (i = 0; arr[i]; i++)
	{
	free(arr[i]);
	arr[i] = NULL;
	}

	free(arr);
}
