#include "monty.h"

/**
 * main - the entery point of the program
 * @argn: number of main args
 * @argv: argumant array of string
 * Return: 0 for succser or 1 for error
*/
int main(int argn, char *argv[])
{
	data my_data;
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (argn < 2)
		excute_error('i', 0);/*error for intery point */
	file = fopen(argv[1], "r+");
	if (file == NULL)
		excute_error('f', 0);/*error file reading */

	while ((read = getline(&line, &len, file)) != -1)
	{
		printf("%s", line);
	}

	fclose(file);
	if (line)
		free(line);
	return (0);
}

