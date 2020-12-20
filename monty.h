#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>


/**
 * struct var_s - struct to contain the main variables of the Monty interpreter
 * @queue: flag to determine if in stack vs queue mode
 * @head_len: length of the stack
 */

typedef struct var_s
{
	int queue;
	size_t head_len;
} var_t;

#define STACK 0
#define QUEUE 1

/* global struct to hold flag for queue and stack length */
extern var_t var;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stacl (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO, Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* monty_helpers.c */
void free_lineptr(int status, void *line);
void fs_close(int status, void *line);
void free_stk(int status, void *line);
stack_t *add_node(stack_t **head, const int n);

/* string.c */


/* find_op.c */
void exec(char *line, stack_t **head, unsigned int line_num);

/* move_func.c */
void swap(stack_t **head, unsigned int line_num);
void rotl(stack_t **head, unsigned int line_num);
void rotr(stack_t **head, unsigned int line_num);

/* nop.c */
void nop(stack_t **head, unsigned int line_num);
void queue(stack_t **head, unsigned int line_num);
void stack(stack_t **head, unsigned int line_num);

/* prints.c */
void pall(stack_t **head, unsigned int line_num);
void pint(stack_t **head, unsigned int line_num);
void pchar(stack_t **head, unsigned int line_num);
void pstr(stack_t **head, unsigned int line_num);

/* push_pop.c */
void push(stack_t **head, unsigned int line_num);
void pop(stack_t **head, unsigned int line_num);

/* math_ops.c */
void add(stack_t **head, unsigned int line_num);
void sub(stack_t **head, unsigned int line_num);
void mul(stack_t **head, unsigned int line_num);
void _div(stack_t **head, unsigned int line_num);
void mod(stack_t **head, unsigned int line_num);


#endif
