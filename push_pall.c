#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @head: pointer to the head of double l-list
 * @line: content in file
 * @line_num: line number
 * Return: 0 on success -1 on failure
 */

int push(stack_t **head, char *line, unsigned int line_num)
{
	char *first_n;
	stack_t *node;

	first_n = searchNumber(line);
	if (!first_n)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		free(line);
		return (-1);
	}

	if (_strcmp(flag, "stack") == 0)
		node = add_node(head, atoi(first_n));
	else
		node = add_node_end(head, atoi(first_n));

	free(line);
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	return (0);
}


/**
 * pop - pop value at the top of the stack
 * @head: head of stack
 * @line_num: number of lines
 * Return: no return for void function
 */
void pop(stack_t **head, unsigned int line_num)
{
	stack_t *node;

	node = pop_start(head);

	if (!node)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}
	free(node);
}
