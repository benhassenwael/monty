#include "monty.h"

/**
 * free_stack - free all the element of the stack
 * @stack: double pointer to the head of the stack
 *
 */
void free_stack(stack_t **stack)
{
	if (*stack == NULL)
		return;
	free_stack(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

/**
 * free_and_exit - free the stack, the buffer and close the file then
 * exit with error
 * @stack: double pointer to the head of the stack
 *
 */
void free_and_exit(stack_t **stack)
{
	free_stack(stack);
	free(*buffer_ptr);
	fclose(f);
	exit(EXIT_FAILURE);
}
