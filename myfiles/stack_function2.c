#include "monty.h"

/**
 * nop - No operation. Does nothing.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode (unused).
 */
void nop(stack_t **stack, unsigned int line_number)
{
	/* This function is a no-op (does nothing). */
	(void)stack; /* Ignore unused parameters.*/
	(void)line_number;
}

/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	
	/* Swaps the top two elements of the stack. */
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_number, "swap");

	/*stack_t *tmp = (*stack)->next;*/
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *stack;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	/* Adds the top two elements of the stack. */
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_number, "add");
	*stack = (*stack)->next;
	/*int sum = (*stack)->n + (*stack)->prev->n;*/
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int difference;

	if (stack == NULL || *stack == NULL || ( *stack)->next == NULL)
		more_error(8, line_number, "sub");

	*stack = (*stack)->next;

	difference = (*stack)->n - (*stack)->prev->n;

	(*stack)->n = difference;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_number, "div");

	if ((*stack)->n == 0)
		more_error(9, line_number);

	 *stack = (*stack)->next;
	 /*int result = (*stack)->n / (*stack)->prev->n;*/
	 result = (*stack)->n / (*stack)->prev->n;
	 (*stack)->n = result;
	 free((*stack)->prev);
	 (*stack)->prev = NULL;
}
