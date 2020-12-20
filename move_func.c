#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @head: pointer to double l-list
 * @line_num: line number
 */

void swap(stack_t **head, unsigned int line_num)
{
	int x;

	if (!head || !*head)
	{
		fprintf(stderr, "L%d: can't swap, %s too short\n", line_num, flag);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}

	x = (*head)->n;
	if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, %s too short\n", line_num, flag);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}
	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = x;
}

/**
 * rotl - rotates the stack to the top.
 * @head: pointer double l-list
 * @line_num: void
 */

void rotl(stack_t **head, unsigned int line_num)
{
	stack_t *node, *tmp;

	(void) line_num;

	if (!head || !*head)
		return;
	if (!(*head)->next)
		return;
	node = pop_start(head);
	node->next = NULL;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

/**
 * rotr - rotates the stack to the bottom.
 * @head: pointer double l-list
 * @line_num: void
 */

void rotr(stack_t **head, unsigned int line_num)
{
	stack_t *node;

	(void)line_num;

	if (!head || !*head)
		return;
	if (!(*head)->next)
		return;
	node = dequeue(head);
	node->prev = NULL;

	node->next = *head;
	(*head)->prev = node;
	*head = node;
}
