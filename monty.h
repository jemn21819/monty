#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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


/* Monty helper functions */
int main(int ac, char **av);
void free_stk(stack_t *head);
stack_t *add_node(stack_t **head, const int n);
void exec(stack_t **head, char *line, unsigned int line_num);
int get_arg(stack_t **head, char *opcode, unsigned int line_num);

/* String handlers */
/* Gets the length of a string */
int _strlen(char *str);

/* Compares 2 strings */
int _strcmp(char *s1, char *s2);

/* Comapres 2 strings up to n chars */
int _strncmp(char *s1, char *s2, int n);

/* Skips white spaces */
char *skipSpaces(char *s);

/* Searches for a number inside a string */
char *searchNumber(char *s);

/* Monty code functions */
/* Prints all elements in a stack */
void pall(stack_t **head, unsigned int line_num);

/* Pushes elements into the top of the stack */
void push(stack_t **head, char *line, unsigned int line_num);

/* Prints element on top of the stack */
void pint(stack_t **head, unsigned int line_num);

/* Removes element on top of the stack */
void pop(stack_t **head, unsigned int line_num);

/* nop ocode doesnt do anything */
void nop(stack_t **head, unsigned int line_num);

/* mathematical fucntion */
void add(stack_t **head, unsigned int line_num);
void sub(stack_t **head, unsigned int line_num);
void mul(stack_t **head, unsigned int line_num);
void _div(stack_t **head, unsigned int line_num);
void mod(stack_t **head, unsigned int line_num);

/* moving functions */
void swap(stack_t **head, unsigned int line_num);


#endif
