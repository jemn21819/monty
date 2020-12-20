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
	stack_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
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

/**
 * add_node_end - add node at the end of double l-list
 * @head: pointer to doble l-list
 * @n: element to insert
 * Return: address of node or NULL
 */

stack_t *add_node_end(stack_t **head, int n)
{
	stack_t *new, *tmp;

	if (!head)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head)
	{
		for (tmp = *head; tmp->next;)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
	else
	{
		new->prev = NULL;
		*head = new;
	}
	return (new);
}

/**
 * pop_start - return the node at beninning
 * @head: pointer to double l-l
 * Return: pointer to node or NULL
 */

stack_t *pop_start(stack_t **head)
{
	stack_t *tmp;

	if (!head || !*head)
		return (NULL);

	tmp = *head;
	*head = (*head)->next;

	if (*head)
		(*head)->prev = NULL;

	return (tmp);
}

/**
 * dequeue - return the node at the end
 * @head: pointer to double l-list
 * Return: pointer to node or NULL
 */

stack_t *dequeue(stack_t **head)
{
	stack_t *h;

	if (!head || !*head)
		return (NULL);

	h = *head;
	while (h->next != NULL)
		h = h->next;

	if (h->prev)
		(h->prev)->next = NULL;
	else
		*head = NULL;

	return (h);
}
