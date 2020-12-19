#include "monty.h"

/**
 * pall - prints all elents in a stack from top
 * @head: head of the stack
 * @line_num: number of lines
 * Return: no return for print function
 */

void pall(stack_t **head, unsigned int line_num)
{
	(void)line_num;
	stack_t *h = *head;

	if (head == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
