#include "monty.h"

/**
 * nop - doesn’t do anything.
 * @head: pointer to dll
 * @line_num: line number
 */

void nop(stack_t **head, __attribute__((unused))unsigned int line_num)
{
	(void)head;
}

/**
 * queue - sets the format of the data to a queue (FIFO).
 * @head: pointer to double l-line
 * @line_num: line number
 */
void queue(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;

	flag = "queue";
}


/**
 * stack - sets the format of the data to a stack (LIFO).
 * @head: pointer to double l-line
 * @line_num: line number
 */
void stack(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;

	flag = "stack";
}
