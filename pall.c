#include "monty.h"

/**
 * _pall - print all the values on the stack, starting from the top
 * @stack: double pointer on the head of the stack
 * @line_number: instruction line number in the file
 *
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *runner;

	runner = *stack;
	while (runner)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * _pint - print the value at the top of the stack followed by
 * a new line
 * @stack: pointer the head of the stack
 * @line_number: instructrion line number in the file
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack && *stack)
	{
		printf("%d\n", (*stack)->n);
		return;
	}
	fprintf(stderr, "L%u: can't pint, stack empty", line_number);
	free_and_exit(stack);
}
