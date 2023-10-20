#include "monty.h"

/**
 * add_to_stack - Add a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Line number of the opcode (unused).
 */
void add_to_stack(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	if (new_node == NULL || *new_node == NULL) {
		fprintf(stderr, "Error: Invalid input for add_to_stack\n");
		exit(EXIT_FAILURE);
	}

	/*If the stack is empty, set the new node as the head*/
	if (head == NULL) {
		head = *new_node;
		return;
	}

	/* Add the new node to the top of the stack*/
	(*new_node)->next = head;
	head->prev = *new_node;
	head = *new_node;
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

	if (stack == NULL || *stack == NULL) {
		fprintf(stderr, "Error: Can't pop an empty stack at line %u\n", ln);
		exit(EXIT_FAILURE);
	}

	tmp = *stack; /* Store the current top node in a temporary variable */
	*stack = tmp->next; /* Update the top of the stack to the next node */

	if (*stack != NULL) {
		(*stack)->prev = NULL; /* Set the new top node's prev pointer to NULL */
	}
	free(tmp); /* Free the removed node */
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
	{
		/* Error: Stack is empty, cannot print */
		more_error(6, ln);
	}
	else{
		/* Print the value of the top node */
		printf("%d\n", (*stack)->n);
	}
}
