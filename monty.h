#ifndef MONTY_H
#define MONTY_H

#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <string.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct data_t - is data type help as to save the where is the head
 * and where is the tail
 * @head:pointer to the head of the data
 * @tail:pointer to the tail of the data
 *
 * it's not neccery for project but to have more confortbul
 * the data can be stack or queue and we can shnge the <mode>
 * of the pushing while run time
*/
typedef struct data_t
{
	struct stack_s *head;
	struct stack_s *tail;
	char *temp_instruction;
	char invers;
	FILE *file;
	char *line;
	int mode;

} data;


/*************************************************************************/
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*(genral)*/
#define  MY_DATA data my_data
extern MY_DATA;

void excute_error(char TYPE_OF_ERROR, unsigned int line_number, char *opcode);
void handel_file(char *file_name);
int line_handler(char *line, unsigned int line_number);
int do_instruction(char *input[], unsigned int line_number); 
int valid(char *number_, int *number);

/***(functions)***/
/*(stack)*/
void push_tail(stack_t **stack, unsigned int line_number);
void pall_front(stack_t **stack, unsigned int line_number);
void pall_back(stack_t **stack, unsigned int line_number);
/*(queue)*/
void push_head(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);

#endif
