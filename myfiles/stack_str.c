#include "monty.h"

/*stack_t *tmp = *stack;*/

/**
 * print_char - Prints the ASCII value as a character.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;
	
	if (stack == NULL || *stack == NULL)
		string_error(11, line_number);

	ascii = (*stack)->n;

	if (ascii < 0 || ascii > 127)
		string_error(10, line_number);

	printf("%c\n", ascii);
}

/**
 * print_str - Prints a string composed of ASCII characters.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode (unused).
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;
	int ascii;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	/*stack_t *tmp = *stack;*/
	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;

		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode (unused).
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the opcode (unused).
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	/*stack_t *tmp = *stack;*/
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
