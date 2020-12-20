#include "monty.h"

FILE *f;
char **buffer_ptr;


/**
 * run_op - find and run a given op instruction and exits on failure
 * @stack: dounble pointer to head of the stack
 * @op_cmd: op instruction
 * @line_nb: instruction line number
 *
 */
void run_op(stack_t **stack, char *op_cmd, unsigned int line_nb)
{
	int i;
	instruction_t op_code[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}
	};

	for (i = 0; op_code[i].opcode; i++)
	{
		if (!strcmp(op_cmd, op_code[i].opcode))
		{
			op_code[i].f(stack, line_nb);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_nb, op_cmd);
	free_and_exit(stack);
}

/**
 * main - main entry to the monty comand interpreter
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char *lineptr = NULL, *op_cmd;
	size_t n;
	ssize_t nread;
	unsigned int line_nb = 0;

	buffer_ptr = &lineptr;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);

	}
	while ((nread = getline(buffer_ptr, &n, f)) != -1)
	{
		line_nb += 1;
		op_cmd = strtok(*buffer_ptr, "\t \n\r");
		if (op_cmd && op_cmd[0] != '#')
		{
			run_op(&stack, op_cmd, line_nb);
		}
	}
	free_stack(&stack);
	free(*buffer_ptr);
	fclose(f);
	exit(EXIT_SUCCESS);
}
