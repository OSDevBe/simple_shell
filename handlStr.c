#include "shell.h"

/**
 * concatPath - concat two strings
 *
 * @str1 : string
 * @str2 : string
 *
 * Return: concated strings
 */

char *concatPath(char *str1, char *str2)
{
	int i, j;
	int length1 = _strlen(str1);
	int length2 = _strlen(str2);

	/* Allocate memory for the concatenated string */
	char *result = (char *)malloc((length1 + length2 + 2) * sizeof(char));

	if (result == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	/* Copy the first string to the result */
	for (i = 0; i < length1; i++)
	{
		result[i] = str1[i];
	}

	/* Add '/' to the result */
	result[i] = '/';
	i++;

	/* Copy the second string to the result */
	for (j = 0; j < length2; j++, i++)
	{
		result[i] = str2[j];
	}

	/* Add null terminator */
	result[i] = '\0';

	return (result);
}
