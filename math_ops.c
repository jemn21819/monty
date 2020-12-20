#include "monty.h"

/**
 * add - add the top 2 values on the stack
 * @head: pointer to dll
 * @line_num: line number
 */

void add(stack_t **head, unsigned int line_num)
{
	int n = 0;

	if (var.head_len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	n += (*head)->n;
	pop(head, line_num);
	(*head)->n += n;
}

/**
 * sub - subtract the top 2 values on the stack
 * @head: pointer to dll
 * @line_num: line number
 */
void sub(stack_t **head, unsigned int line_num)
{
	int n;

	if (var.head_len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	n = (*head)->n;
	pop(head, line_num);
	(*head)->n -= n;
}

/**
 * _div - divides the top 2 values on the stack
 * @head: pointer to dll
 * @line_num: line number
 */
void _div(stack_t **head, unsigned int line_num)
{
	int n;

	if (var.head_len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	n = (*head)->n;
	pop(head, line_num);
	if (n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*head)->n /= n;
}


/**
 * mul - multiply the top 2 values on the stack
 * @head: pointer to dll
 * @line_num: line number
 */
void mul(stack_t **head, unsigned int line_num)
{
	int n;

	if (var.head_len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	n = (*head)->n;
	pop(head, line_num);
	(*head)->n *= n;
}

/**
 * mod - get the modulo of the top 2 values on the stack
 * @head: pointer to dll
 * @line_num: line number
 */

void mod(stack_t **head, unsigned int line_num)
{
	int n;

	if (var.head_len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	n = (*head)->n;
	pop(head, line_num);
	if (n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*head)->n %= n;
}

