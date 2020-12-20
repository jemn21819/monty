#include "monty.h"

/**
 * pall - prints all elents in a stack from top
 * @head: head of the stack
 * @line_num: number of lines
 * Return: no return for void function
 */

void pall(stack_t **head, unsigned int line_num)
{
	stack_t *stack;

	(void)(line_num);

	stack = *head;
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		if (stack == *head)
		{
			return;
		}
	}
}

/**
 * pint - prints value at the top of the stack
 * @head: head of stack
 * @line_num: number of lines
 * Return: no return for void function
 */
void pint(stack_t **head, unsigned int line_num)
{
	stack_t *stack = *head;

	if (var.head_len == 0)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack->n);
}
/**
 * pchar - prints the char at the top of the stack.
 * @head: pointer to double l-list
 * @line_num: line number
 */

void pchar(stack_t **head, unsigned int line_num)
{
	int ch;

	if (var.head_len < 1)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	ch = (*head)->n;
	if (!isascii(ch))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}
/**
 * pstr - prints the string starting at the top of the stack
 * @head: pointer to double l-list
 * @line_num: void
 */

void pstr(stack_t **head, unsigned int line_num)
{
	stack_t *temp;
	int ch;

	(void)line_num;

	temp = *head;
	while (temp != NULL)
	{
		ch = temp->n;
		if (!isascii(ch) || ch == 0)
			break;
		putchar(ch);
		temp = temp->next;
		if (temp == *head)
			break;
	}
	putchar('\n');
}
