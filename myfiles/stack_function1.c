#include "monty.h"

/**
 * add_to_stack - Add a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Line number of the opcode (unused).
 */

void add_to_stack(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	/* Check for valid input */
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * print_stack - Print all nodes in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Line number of the opcode (unused).
 */
void print_stack(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;
	/* Check for valid input */
	if (stack == NULL)
		exit(EXIT_FAILURE);

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Remove the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Line number of the opcode.
 */
void pop_top(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;
	/* Check for valid input */
	if (stack == NULL || *stack == NULL)
		more_error(7, ln);

	tmp = *stack;/* Store the current top node in a temporary variable */
	*stack = tmp->next; /* Update the top of the stack to the next node */
	if (*stack != NULL)
	{
		(*stack)->prev = NULL; /* Set the new top node's prev pointer to NULL */
	}
	free(tmp);
}

/**
 * print_top - Print the value of the top node in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Line number of the opcode.
 */
void print_top(stack_t **stack, unsigned int ln)
{
	/* Check for valid input */
	if (stack == NULL || *stack == NULL)
		more_error(6, ln);

	printf("%d\n", (*stack)->n);
}
