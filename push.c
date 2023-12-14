#include"monty.h"

/**
 * push_head - function that push in the head of the data
 * @stack: pointer to stack <head>
 * @line_number: number of line in the file help in error // handel
 * return: no return
*/
void push_head(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int var;

	if (valid(my_data.temp_instruction, &var))
	{
		free(new_node);
		excute_error('P', line_number, NULL);
	}
	if (!new_node)
	{
		excute_error('M', line_number, NULL);
		/*function that print ERROR depind on error type*/
		free(my_data.line);
		fclose(my_data.file);
		exit(EXIT_FAILURE);
	}
/*Function that print ERROR depind on error type*/
	new_node->n = var;
	if ((*stack) != NULL)
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
		my_data.tail = new_node;
	}
}

/**
 * push_tail - function that push in the tail of the data
 * @stack: pointer to stack <tail>queue
 * @line_number: number of line in the file help in error // handel
 * return: no return
*/
void push_tail(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int var;

	if (valid(my_data.temp_instruction, &var))
	{
		free(new_node);
		excute_error('P', line_number, NULL);
	}
	if (!new_node)
	{
		excute_error('M', line_number, NULL);
		/*function that print ERROR depind on error type*/
		exit(EXIT_FAILURE);
	}
	new_node->n = var;
	if ((my_data.tail) != NULL)
	{
		(my_data.tail)->next = new_node;
		new_node->prev = my_data.tail;
		new_node->next = NULL;
		my_data.tail = new_node;
	}
	else
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
		my_data.tail = new_node;
	}
}

/**
 *  pall_front - function that print all the data and don't print any
 * thing if no data <print statring from the head>
 * @stack: pointer to stack <head>
 * @line_number: number of line in the file help in error // handel
 * return: no return
*/
void pall_front(stack_t **stack, unsigned int line_number)
{
	/*stak  <pointer to head> from the head to tail*/
	stack_t *it = *stack;

	while (!it)
	{
		printf("%d\n", it->n);
		it = it->next;
	}


}

/**
 *  pall_back - function that print all the data and don't print any
 * thing if no data <print statring from the <<tail>> and revarce the print>
 * @stack: pointer to stack <tail>
 * @line_number: number of line in the file help in error // handel
 * return: no return
*/

void pall_back(stack_t **stack, unsigned int line_number)
{
	stack_t *it = my_data.tail;

	while (it)
	{
		printf("%d\n", it->n);
		it = it->prev;
	}

}
