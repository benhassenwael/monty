#include "monty.h"

/**
 * _stack - sets the format of the data to a stack
 * @stack: unused
 * @line_number: unused
 *
 */
void _stack(__attribute__((unused))stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	queue = 0;
}

/**
 * _queue - sets the format of the data to queue
 * @stack: unused
 * @line_number: unused
 *
 */
void _queue(__attribute__((unused))stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	queue = 1;
}
