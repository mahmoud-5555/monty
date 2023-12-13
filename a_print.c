#include"monty.h"

/**
 * pint - prints the value at the top of the stack\n
 * @head: double pointer to the head
 * @Nline: line number
 */
void pint(stack_t **head, unsigned int Nline)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", Nline);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
