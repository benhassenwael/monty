#include "monty.h"

/**
 * _pall - print all the values on the stack, starting from the top
 * @stack: double pointer on the head of the stack
 * @line_number: instruction line number in the file
 *
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	(void)line_number;
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
	if (stack && *stack)
	{
		printf("%d\n", (*stack)->n);
		return;
	}
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	free_and_exit(stack);
}

/**
 * _pchar - print the char at the top of the stack followed by
 * a new line
 * @stack: pointer to the head of the stack
 * @line_number: instruction line number
 *
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_and_exit(stack);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_and_exit(stack);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - print the string starting at the top of the stack followed by
 * a new line
 * @stack: pointer to the head of the stack
 * @line_number: instruction line number
 *
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	(void)line_number;
	while (runner && runner->n > 0 && runner->n < 128)
	{
		putchar(runner->n);
		runner = runner->next;
	}
	putchar('\n');
}
