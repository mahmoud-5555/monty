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

	printf("%i : testing namber of args", argn);
	if (argn < 2)
	{
		/*error for intery point */
		excute_error('i', 0);
		exit(EXIT_FAILURE);
	}
	handel_file(argv[1]);

	return (0);
}

/**
 * handel_file - file function that open the file and read the line one by one
 * @file_name: the file name <file path taked from the args>
 * Return: no return value
*/
void handel_file(char *file_name)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	file = fopen(file_name, "r+");
	if (file == NULL)
		/*error file reading */
		excute_error('f', 0);

	while ((read = getline(&line, &len, file)) != -1)
	{
		printf("%s", line);
	}

	fclose(file);
	if (line)
		free(line);

}

