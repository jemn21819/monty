#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @head: pointer to double l-list
 * @line_num: line number
 */

void swap(stack_t **head, unsigned int line_num)
{
	stack_t *next;

	if (var.head_len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (var.head_len == 2)
	{
		*head = (*head)->next;
		return;
	}
	next = (*head)->next;
	next->prev = (*head)->prev;
	(*head)->prev->next = next;
	(*head)->prev = next;
	(*head)->next = next->next;
	next->next->prev = *head;
	next->next = *head;
	*head = next;
}
/**
 * rotl - rotates the stack to the top.
 * @head: pointer double l-list
 * @line_num: void
 */

void rotl(stack_t **head, unsigned int line_num)
{
	(void)line_num;

	if (*head)
		*head = (*head)->next;
}

/**
 * rotr - rotates the stack to the bottom.
 * @head: pointer double l-list
 * @line_num: void
 */

void rotr(stack_t **head, unsigned int line_num)
{
	(void)line_num;

	if (*head)
		*head = (*head)->prev;
}
