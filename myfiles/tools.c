#include "monty.h"

/**
* open_file - Opens a file and starts reading its contents.
* @file_name: The file's path to open.
*/
void open_files(char *file_name)
{
FILE *fd = fopen(file_name, "r");

if (file_name == NULL || fd == NULL)
error(2, file_name);

read_files(fd);
fclose(fd);
}

/**
* read_file - Reads and processes instructions from a file.
* @fd: A pointer to the open file descriptor.
*/
void read_files(FILE *fd)
{
int line_number, format = 0;
char *buffer = NULL;
size_t len = 0;

for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
{
format = parse_lines(buffer, line_number, format);
}
free(buffer);
}

/**
* parse_line - Separates a line into tokens to determine appropriate function.
* @buffer: The line from the file.
* @line_number: The line number.
* @format: Storage format. 0 for stack, 1 for queue.
* Return: 0 if the format is stack, 1 if the format is queue.
*/
int parse_lines(char *buffer, int line_number, int format)
{
char *opcode, *value;
const char *delim = "\n ";

if (buffer == NULL)
error(4);

opcode = strtok(buffer, delim);
if (opcode == NULL)
return (format);
value = strtok(NULL, delim);

if (strcmp(opcode, "stack") == 0)
return (0);
if (strcmp(opcode, "queue") == 0)
return (1);

find_functions(opcode, value, line_number, format);
return (format);
}

/**
* find_func - Finds the appropriate function for the given opcode.
* @opcode: The opcode.
* @value: Argument of the opcode.
* @format: Storage format. 0 for stack, 1 for queue.
* @ln: Line number.
*/
void find_functions(char *opcode, char *value, int ln, int format)
{
int i;
int flag;

instruction_t func_list[] = {
{"push", add_to_stack},
{"pall", print_stack},
{"pint", print_top},
{"pop", pop_top},
{"nop", nop},
{"swap", swap_nodes},
{"add", add_nodes},
{"sub", sub_nodes},
{"div", div_nodes},
{"mul", mult_nodes},
{"mod", mode_nodes},
{"pchar", print_char},
{"pstr", print_str},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}
};

if (opcode[0] == '#')
return;

for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
{
if (strcmp(opcode, func_list[i].opcode) == 0)
{
call_function(func_list[i].f, opcode, value, ln, format);
flag = 0;
}
}
if (flag == 1)
error(3, ln, opcode);
}

/**
* call_fun - Calls the required function.
* @func: Pointer to the function to be called.
* @op: String representing the opcode.
* @val: String representing a numeric value.
* @ln: Line number for the instruction.
* @format: Storage format. 0 for stack, 1 for queue.
*/
void call_function(op_func func, char *op, char *val, int ln, int format)
{
stack_t *node;
int flag;
int i;

flag = 1;
if (strcmp(op, "push") == 0)
{
if (val != NULL && val[0] == '-')
{
val = val + 1;
flag = -1;
}
if (val == NULL)
error(5, ln);
for (i = 0; val[i] != '\0'; i++)
{
if (isdigit(val[i]) == 0)
error(5, ln);
}
node = create_node(atoi(val) * flag);
if (format == 0)
func(&node, ln);
if (format == 1)
add_to_queue(&node, ln);
}
else
func(&head, ln);
}
