#include "monty.h"

/**
 * free_stk - free a double l-list
 * @head: pointer to double l-list
 */

void free_stk(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
