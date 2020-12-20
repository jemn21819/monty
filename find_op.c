#include "monty.h"

/**
 * exec - locate the fucntion asociated to th op
 * @head: pointer to double l-list
 * @line: command
 * @line_num: line numbre in file
 * Return: 0, 1 or -1
 */

void exec(char *line, stack_t **head, unsigned int line_num)
{
	size_t i;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, line) == 0)
		{
			ops[i].f(head, line_num);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, line);
	exit(EXIT_FAILURE);
}

