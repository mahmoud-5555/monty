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

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", Nline);
		exit(EXIT_FAILURE);
	}


	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}

/**
 * pop -  removes the top element of the stack.
 * @stack: Pointer to a pointer
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "Error: can't pop, stack empty\n");
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * add -  adds the top two elements of the stack.
 * @stack: Pointer to a pointer
 * @line_number: line number of of the opcode.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	(void) line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * nop - doesn’t do anything.
 * @stack: Pointer to a pointer
 * @line_number: line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
