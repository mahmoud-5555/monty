#include "monty.h"
#include <stdio.h>
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
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
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	my_data.mode = 0;
	my_data.line = NULL;
	my_data.head = NULL;
	my_data.tail = NULL;
	my_data.temp_instruction = NULL;
	my_data.file = fopen(file_name, "r+");

	if (my_data.file == NULL)
		excute_error('f', 0, file_name);

	while ((read = getline(&(my_data.line), &len, my_data.file)) != -1)
	{
		line_number++;
		line_handler(my_data.line, line_number);
	}

	fclose(my_data.file);
	if (my_data.line)
		free(my_data.line);
	free_stack(my_data.head);
}
/**
 * line_handler - function that handel the line <cut it>
 * @line: the string input
 * @line_number: line number
 * Return: 0
*/

int line_handler(char *line, unsigned int line_number)
{
	char *token;
	int i = 0;

	char *inst[] = {NULL, NULL};

	token = strtok(line, " ");
	while (token != NULL && i < 2)
	{
		inst[i] =  token;
		token = strtok(NULL, " \t\n");
		i += 1;
	}
	do_instruction(inst, line_number);

	return (0);
}

/**
 * do_instruction - function that check if the instruction is in method
 * or not then do the insrtuction
 * @input: the instruction and the vakue of the insruction
 * @line_number:used for the error
 * Return: 0
*/
int do_instruction(char *input[], unsigned int line_number)
{
	instruction_t instruction[] = {{"push", push_tail}, {"pall", pall_back}};
	int i;
	char flag_test_faile = 1;

	for (i = 0; i < 2; i++)
	{
		if (!strcmp(instruction[i].opcode, input[0]))
		{
			if (!(my_data.mode))
			{
				my_data.temp_instruction = input[1];
				((instruction[i].f)(&(my_data.head), line_number));
			}
			flag_test_faile = 0;
		}
	}
	if (flag_test_faile)
		excute_error('i', line_number, input[0]);

	return (0);

}

