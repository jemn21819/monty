#include "monty.h"

var_t var;

/**
 * main - Monty bytecode interpreter
 * @ac: number of arguments passed
 * @av: array of argument strings
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */

int main(int ac, char *av[])
{
	stack_t *head = NULL;
	unsigned int line_num = 0;
	FILE *fs = NULL;
	char *lineptr = NULL, *line = NULL;
	size_t n = 0;

	var.queue = 0;
	var.head_len = 0;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fs = fopen(av[1], "r");
	if (fs == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(free_lineptr, &lineptr);
	on_exit(free_stk, &head);
	on_exit(fs_close, fs);
	while (getline(&lineptr, &n, fs) != -1)
	{
		line_num++;
		line = strtok(lineptr, "\n\t\r ");
		if (line != NULL && line[0] != '#')
		{
			exec(line, &head, line_num);
		}
	}
	exit(EXIT_SUCCESS);
}
