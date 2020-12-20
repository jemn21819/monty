#include "monty.h"

/**
 * free_stk - free a double l-list
 * @status: exit status
 * @line: pointer to double l-list
 */

void free_stk(int status, void *line)
{
	stack_t **head;
	stack_t *next;
	(void)status;

	head = (stack_t **)line;
	if (*head)
	{
		(*head)->prev->next = NULL;
		(*head)->prev = NULL;
	}
	while (*head != NULL)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	var.head_len = 0;
}

/**
 * fs_close - close file stream
 * @status: status passed to exit
 * @line: pointer to file stream
 */

void fs_close(int status, void *line)
{
	FILE *fs;

	(void)status;

	fs = (FILE *) line;
	fclose(fs);
}

/**
 * free_lineptr - free line pointer returned by getline
 * @status: exit status
 * @line: pointer to line
 *
 * Return: void
 */
void free_lineptr(int status, void *line)
{
	char **lineptr = line;

	(void)status;
	if (*lineptr != NULL)
		free(*lineptr);
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
	if (*head == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		(*head)->prev->next = new;
		new->prev = (*head)->prev;
		(*head)->prev = new;
		new->next = *head;
	}
	if (var.queue == STACK || var.head_len == 0)
		*head = new;
	return (new);
}
