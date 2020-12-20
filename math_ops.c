#include "monty.h"

/**
 * add - add the top 2 values on the stack
 * @head: pointer to dll
 * @line_num: line number
 * opcode add
 */

void add(stack_t **head, unsigned int line_num)
{
	int num1, num2;

	num1 = get_arg(head, "add", line_num);
	num2 = get_arg(head, "add", line_num);

	add_node(head, num1 + num2);
}


/**
 * sub - subtract the top 2 values on the stack
 * @head: pointer to dll
 * @line_num: line number
 * opcode: sub
 */
void sub(stack_t **head, unsigned int line_num)
{
	int num1, num2;

	num1 = get_arg(head, "sub", line_num);
	num2 = get_arg(head, "sub", line_num);

	add_node(head, num2 - num1);
}


/**
 * _div - divides the top 2 values on the stack
 * @head: pointer to dll
 * @line_num: line number
 * opcode: div
 */
void _div(stack_t **head, unsigned int line_num)
{
	int num1, num2;

	num1 = get_arg(head, "div", line_num);
	num2 = get_arg(head, "div", line_num);

	if (num1 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}
	add_node(head, num2 / num1);
}


/**
 * mul - multiply the top 2 values on the stack
 * @head: pointer to dll
 * @line_num: line number
 * opcode: mul
 */
void mul(stack_t **head, unsigned int line_num)
{
	int num1, num2;

	num1 = get_arg(head, "mul", line_num);
	num2 = get_arg(head, "mul", line_num);

	add_node(head, num2 * num1);
}

/**
 * mod - get the modulo of the top 2 values on the stack
 * @head: pointer to dll
 * @line_num: line number
 * opcode: mod
 */

void mod(stack_t **head, unsigned int line_num)
{
	int num1, num2;

	num1 = get_arg(head, "mod", line_num);
	num2 = get_arg(head, "mod", line_num);

	if (num1 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}
	add_node(head, num2 % num1);
}
