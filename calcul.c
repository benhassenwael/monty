#include "monty.h"

/**
 * _add - execution of add opcode that add the top two
 * elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: instruction line_number
 *
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t **head = stack;

	if (!stack || !(*stack) || !(*stack)->next)
	{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_and_exit(stack);
	}
	stack = &(*stack)->next;
	(*stack)->n += (*stack)->prev->n;
	_pop(head, line_number);
}

/**
 * _sub - execution of sub opcode that subtracts the top element
 * of the stack from the second top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: instruction line_number
 *
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t **head = stack;

	if (!stack || !(*stack) || !(*stack)->next)
	{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_and_exit(stack);
	}
	stack = &(*stack)->next;
	(*stack)->n -= (*stack)->prev->n;
	_pop(head, line_number);
}

/**
 * _div - execution of div opcode that divides the second top
 * element of the stack by the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: instruction line_number
 *
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t **head = stack;

	if (!stack || !(*stack) || !(*stack)->next)
	{
	fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_and_exit(stack);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_and_exit(stack);
	}
	stack = &(*stack)->next;
	(*stack)->n /= (*stack)->prev->n;
	_pop(head, line_number);
}

/**
 * _mul - execution of mul opcode that multiplies the second
 * top element of the stack with the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: instruction line_number
 *
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t **head = stack;

	if (!stack || !(*stack) || !(*stack)->next)
	{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_and_exit(stack);
	}
	stack = &(*stack)->next;
	(*stack)->n *= (*stack)->prev->n;
	_pop(head, line_number);
}
/**
 * _mod - execution of mod opcode that computes the rest of
 * the division of the second top element of the stack by
 * the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: instruction line_number
 *
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t **head = stack;

	if (!stack || !(*stack) || !(*stack)->next)
	{
	fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_and_exit(stack);
	}
	if ((*stack)->n == 0)
	{
	fprintf(stderr, "L%u: division by zero\n", line_number);
		free_and_exit(stack);
	}
	stack = &(*stack)->next;
	(*stack)->n %= (*stack)->prev->n;
	_pop(head, line_number);
}
