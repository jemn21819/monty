#include "monty.h"

/**
 * exec - locate the fucntion asociated to th op
 * @head: pointer to double l-list
 * @line: command
 * @line_num: line numbre in file
 * Return: 0, 1 or -1
 */

int exec(stack_t **head, char *line, unsigned int line_num)
{
	instruction_t ops[] = {
		{"pall", pall}, {"pint", pint}, {"nop", nop},
		{"swap", swap}, {"add", add}, {"pop", pop},
		{"sub", sub}, {"div", _div}, {"pchar", pchar},
		{"mul", mul}, {"mod", mod}, {"pstr", pstr}, {"queue", queue},
		{"rotl", rotl}, {"rotr", rotr}, {"stack", stack}, {NULL, NULL}
	};
	int i, push_back;
	char *first_c;

	first_c = skipSpaces(line);
	if (!first_c)
	{
		free(line);
		return (1);
	}
	if (_strncmp(first_c, "push", _strlen("push")) == 0)
	{
		push_back = push(head, line, line_num);
		return ((push_back == 0) ? 0 : -1);
	}
	for (i = 0; ops[i].opcode; ++i)
	{
		if (_strncmp(first_c, ops[i].opcode, _strlen(ops[i].opcode)) == 0)
		{
			free(line), (ops[i].f)(head, line_num);
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction ", line_num);
	while (*first_c && (*first_c != ' ' && *first_c != '\t'))
		putchar(*first_c++);
	putchar('\n');
	free(line);
	return (-1);
}

/**
 * get_arg - et arg form math operations
 * @head: pointer to double l-list
 * @opcode: opcode string
 * @line_num: line number
 * Return: argument
 */
int get_arg(stack_t **head, char *opcode, unsigned int line_num)
{
	stack_t *node;
	int tmp;

	node = pop_start(head);

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, opcode);
		free_stk(*head);
		exit(EXIT_FAILURE);
	}
	tmp = node->n;
	free(node);
	return (tmp);
}


