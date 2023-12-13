#include "monty.h"

/**
 * excute_error - function that print the error
 * @line_number: number of the line that ther an error there
 * @opcode: the instruction that not understud <optionnal> could be NULL
 * @TYPE_OF_ERROR: type of the error
 * 'e' refer to prpblem in run the program <entary point ERROR>
 * Return: no return value
*/
void excute_error(char TYPE_OF_ERROR, unsigned int line_number, char *opcode)//handel file ERROR
{
	if (TYPE_OF_ERROR == 'e')
		fprintf(stderr, "USAGE: monty file\n");
	else if (TYPE_OF_ERROR == 'M')
		fprintf(stderr, "Error: malloc failed\n");
	else if (TYPE_OF_ERROR == 'i')
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	else if (TYPE_OF_ERROR == 'f')
		fprintf(stderr, "Error: Can't open file <file>", opcode);

}