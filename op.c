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
/**
 * swap - swaps the top two elements of the stack
 * @head: double pointer to the head
 * @Nline: line number
 */
void swap(stack_t **head, unsigned int Nline)
{
	int tmp;

	if (*head == NULL || (*head)->next == NULL) {
		fprintf(stderr, "L%u: can't swap, stack too short\n", Nline);
		exit(EXIT_FAILURE);
	}


	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
