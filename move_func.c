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
		printf("L%d: can't swap, stack too short\n", line_num);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}

	x = (*head)->n;
	if ((*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_num);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}
	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = x;
}


