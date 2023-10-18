#include "monty.h"

/**
 * mul_nodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int product;

	/* Check if the stack exists, is not empty, and has at least two elements */
	(*stack) = (*stack)->next;
	product = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = product;

	/* Free the previous node and set the previous pointer to NULL */
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - Computes the modulo of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int remainder;

	/* Check if the stack exists, is not empty, and has at least two elements */
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_number, "mod");

	/* Check if the divisor is zero */
	if ((*stack)->n == 0)
		more_error(9, line_number);

	/* Move the stack pointer to the next element and calculate the remainder */
	(*stack) = (*stack)->next;
	remainder = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = remainder;

	/* Free the previous node and set the previous pointer to NULL */
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
