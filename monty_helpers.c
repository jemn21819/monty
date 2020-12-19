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

/**
 * add_node - add a node at beggning of a stack
 * @head: refrence to head of stack
 * @n: value for new node
 * Return: NULL if failed || address of the new stack
 */
stack_t *add_node(stack_t **head, const int n)
{
	if (head == NULL)
		return (NULL);

	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;
	*head = new;
	return (new);
}
