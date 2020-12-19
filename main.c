#include "monty.h"

/**
 * main - run monty program
 * @ac: argument counter
 * @av: argument vector
 * Return: 0
 */

int main(int ac, int **av)
{
	stack_t *h;
	unsigned int line_num;
	ssize_t status;
	char *line;
	size_t len;
	FILE *fp;

	if (ac != 2)
	{
		printf("USAGE: %s file\n", av[0]);
		exit(EXIT_FAILURE);
	}
	h = NULL;
	fp = fopen(av[1], "r");
	if (!fp)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	line_num = 0;
	do {
		++line_num;
		line =  NULL;
		len = 0;
		status = getline(&line, &len, fp);
		if (status > 0)
			exec(&h, line, line_num);
		else
			free(line);
	} while (status >= 0);
	fclose(fp);
	free_stk(h);
	return (0);
}
