#include "monty.h"

/**
 * exec - locate the fucntion asociated to th op
 * @head: pointer to double l-list
 * @line: command
 * @line_num: line numbre in file
 */

void exec(stack_t **head, char *line, unsigned int line_num)
{
	instruction_t ops[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	int i;
	char *first_c;

	first_c = skipSpaces(line);
	if (!first_c)
		return;
	if (_strncmp(first_c, "push", _strlen("push")) == 0)
	{
		push(head, line, line_num);
		return;
	}
	for (i = 0; ops[i].opcode; ++i)
	{
		if (_strncmp(first_c, ops[i].opcode, _strlen(ops[i].opcode)) == 0)
		{
			free(line);
			(ops[i].f)(head, line_num);
			return;
		}
	}
	printf("L%d: unknown instruction ", line_num);
	while (*first_c && (*first_c != ' ' && *first_c != '\t'))
		putchar(*first_c++);
	putchar('\n');
	free(line);
	free_stk(*head);
	*head = NULL;
	exit(EXIT_FAILURE);
}
