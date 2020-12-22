#include "monty.h"

/**
 * _rotl - rotate the stack to the top
 * @stack: pointer to the head of the stack
 * @line_number: unused
 *
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	(void)line_number;
	if (stack && *stack && (*stack)->next)
	{
		runner = *stack;
		while (runner->next)
			runner = runner->next;
		*stack = (*stack)->next;
		runner->next = (*stack)->prev;
		(*stack)->prev->prev = runner;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}

/**
 * _rotr - rotates the stack to the bottom
 * @stack: pointer to the head of the stack
 * @line_number: unused
 *
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	(void)line_number;
	if (stack && *stack && (*stack)->next)
	{
		runner = *stack;
		while (runner->next)
			runner = runner->next;
		runner->prev->next = NULL;
		runner->prev = NULL;
		runner->next = *stack;
		(*stack)->prev = runner;
		*stack = runner;
	}
}
