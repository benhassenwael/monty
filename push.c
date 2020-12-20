#include "monty.h"


/**
 * add_dnodeint - add a new node at the beginning of
 * a dlistint_t list
 * @head: pointer the head of the list
 * @n: data of the new node
 *
 * Return: pointer to the new node or NULL on failure
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *node;

	if (!head)
		return (NULL);
	node = malloc(sizeof(stack_t));
	if (!node)
		free_and_exit(head);
	node->n = n;
	node->next = *head;
	node->prev = NULL;
	if (*head)
		(*head)->prev = node;
	*head = node;
	return (node);
}

/**
 * isnumber - check if agiven string is a number (taking into account
 * the '-' character at the start)
 * @s: string may start with '-'
 *
 * Return: 1 if s is a number, 0 otherwise
 */
int isnumber(char *s)
{
	int i = 0;

	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (!(s[i] <= '9' && s[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

/**
 * _push - execution of push opcode that pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: instruction line number
 *
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *arg_s;
	int arg_i;

	arg_s = strtok(NULL, "\n\t\r ");
	if (!arg_s || !isnumber(arg_s))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_and_exit(stack);
	}
	arg_i = atoi(arg_s);
	add_dnodeint(stack, arg_i);
}
