#include "main"

/**
 * get_path - Constructs a path to binaries.
 * @tokens: Double pointer to tokens.
 * Return: Return - path, else - NULL.
 */
char *get_path(char **tokens)
{
	char path1[100] = "/bin/";
	char path2[100] = "/usr/bin/";

	char *finalPath1;
	char *finalPath2;

	finalPath1 = _strcat(path1, tokens[0]);

	if ((if_file_exists(finalPath1) == 0))
		return (finalPath1);

	finalPath2 = _strcat(path2, tokens[0]);
	if ((if_file_exists(finalPath2) == 0))
		return (finalPath2);

	return (NULL);
}
