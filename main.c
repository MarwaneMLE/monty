#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point for the Monty program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: Always returns 0.
 */
int main(int argc, char *argv[])
{
	/* Check for the correct number of command-line arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Creates a new stack node.
 * @n: The integer value to be stored in the node.
 * Return: A pointer to the newly created node or NULL on failure.
 */
stack_t *create_node(int n)
{
	/* Allocate memory for a new stack node */
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
		error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees all nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *tmp;

	/* Check if the stack is empty */
	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * add_to_queue - Adds a new node to the end of the queue.
 * @new_node: Pointer to the new node to be added.
 * @ln: Line number of the opcode (unused).
 */
void add_to_queue(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	/* Check for valid input */
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		/* If the queue is empty, set the new node as the head */
		head = *new_node;
		return;
	}

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	/* Add the new node to the end of the queue */
	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
