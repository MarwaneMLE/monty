#include "monty.h"

/**
 * error - Prints appropriate error messages based on their error code.
 * @error_code: The error codes and their meanings are as follows:
 * (1) => No file or more than one file provided by the user.
 * (2) => The provided file cannot be opened or read.
 * (3) => Invalid instruction found in the provided file.
 * (4) => Memory allocation failure.
 * (5) => Non-integer parameter given to the "push" instruction.
 * (6) => Stack is empty when attempting "pint."
 * (7) => Stack is empty when attempting "pop."
 * (8) => Stack is too short for the requested operation.
 */
void error(int error_code, ...)
{
	va_list args;
	int l_num;
	char *op;

	va_start(args, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
		{
			l_num = va_arg(args, int);
			op = va_arg(args, char *);

			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		}
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}

	va_end(args);
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_error - Manages specific errors based on error codes.
 * @error_code: The following error codes are supported:
 * (6) => Occurs when the stack is empty during a "pint" operation.
 * (7) => Occurs when the stack is empty during a "pop" operation.
 * (8) => Occurs when the stack is too short for the requested operation.
 * (9) => Occurs when division by zero is attempted.
 */
void more_error(int error_code, ...)
{
	va_list args;
	char *op;
	int l_num;

	va_start(args, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
		case 8:
		{
			l_num = va_arg(args, unsigned int);
			op = va_arg(args, char *);

			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		}
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	va_end(args);
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_error - Manages errors with specific error codes.
 * @error_code: The following error codes are handled:
 * (10) => When the value inside a node falls outside the ASCII bounds.
 * (11) => When the stack is empty.
 */
void string_error(int error_code, ...)
{
	va_list args;
	int l_num;

	va_start(args, error_code);
	l_num = va_arg(args, int);

	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	va_end(args);
	free_nodes();
	exit(EXIT_FAILURE);
}
