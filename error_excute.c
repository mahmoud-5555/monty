#include "monty.h"

/**
 * excute_error - function that print the error
 * @line_number: number of the line that ther an error there
 * @opcode: the instruction that not understud <optionnal> could be NULL
 * @TYPE_OF_ERROR: type of the error
 * 'e' refer to prpblem in run the program <entary point ERROR>
 * Return: no return value
*/
void excute_error(char TYPE_OF_ERROR, unsigned int line_number, char *opcode)
{
	if (TYPE_OF_ERROR == 'e')
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else if (TYPE_OF_ERROR == 'M')
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(my_data.head);
		free(my_data.line);
		fclose(my_data.file);
	}
	else if (TYPE_OF_ERROR == 'i')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free(my_data.line);
		fclose(my_data.file);
		free_stack(my_data.head);
		exit(EXIT_FAILURE);
	}
	else if (TYPE_OF_ERROR == 'f')
	{
		fprintf(stderr, "Error: Can't open file %s\n", opcode);
		exit(EXIT_FAILURE);
	}
	else if (TYPE_OF_ERROR == 'P')
	{
		fprintf(stderr, "L%u: usage: push integer %s\n", line_number, opcode);
		free(my_data.line);
		fclose(my_data.file);
		free(my_data.line);
		free_stack(my_data.head);
		exit(EXIT_FAILURE);
	}

}
/**
 * valid - function that check if the number is valid or not
 * @number_: string number
 * @number: the value will store in this variable
 * Return: 0 if the value is valid  else 1
*/
int valid(char *number_, int *number)
{
	char *str = "-123";
	char *endptr;
	int errno = 0;

	 *number = strtol(number_, &endptr, 10);
	if (errno != 0 || *endptr != '\0' || endptr == str)
		return (1);
	else
		return (0);
}
/**
 * free_stack - function that free the stack
 * @head: the head of stack
 * Retaurn:no retuen value
*/
void free_stack(stack_t *head)
{
	stack_t *temp = head;

	while (!head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
