#include "monty.h"


/**
 * _swap - execution of swap opcode that swaps
 * the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: instruction line number in the file
 *
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int aux;

	if (!stack || !(*stack) || !(*stack)->next)
	{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_and_exit(stack);
	}
	aux = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = aux;
}

/**
 * _nop - execution of nop opcode that doesn't do anything
 * @stack: unused variable
 * @line_number: instruction line number
 *
 */
void _nop(__attribute__((unused))stack_t **stack, unsigned int line_number)
{
	(void)line_number;
}
