#include "monty.h"

MY_DATA;

/**
 * main - the entery point of the program
 * @argn: number of main args
 * @argv: argumant array of string
 * Return: 0 for succser or 1 for error
*/

int main(int argn, char *argv[])
{

	if (argn < 2)
	{
		/*error for intery point */
		excute_error('i', 0, NULL);
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
	unsigned int line_number = 0;

	file = fopen(file_name, "r+");
	if (file == NULL)
		excute_error('f', 0, file_name);

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_handler(line);
		line_number++;
	}

	fclose(file);
	if (line)
		free(line);
}

int line_handler(char *line)
{
	char *token;
	int i = 0;

	char *inst[2];

	token = strtok(line, " ");
	while (token != NULL && i < 2)
	{
		inst[i] =  token;
		token = strtok(NULL, " ");
		i += 1;
	}

	return (0);
}
int do_instruction(char *input[])
{
	instruction_t instruction[] = {{"push", pall_back}, {"pall", pall_back}};
	int i;

	for (i = 0; i < 2; i++)
	{
		if (!strcmp(instruction[i].opcode, input[0]))
		{
			
		}
	}
}

