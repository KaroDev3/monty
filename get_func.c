#include "monty.h"

/**
 * get_func - selects the correct function to perform
 * @s: monty command passed as argument
 * Return: pointer to the function that corresponds to the operator
 */
int get_func(char *s, stack_t **stack, char *n, int count_line)
{
	instruction_t monty_functions[] = {
	    {"push", f_push},
	    {"pall", f_pall},
	    {NULL, NULL}};

	int i = 0;
	while (monty_functions[i].opcode != NULL)
	{
		if (strcmp(monty_functions[i].opcode, s) == 0)
		{
			monty_functions[i].f(stack, atoi(n));
			return (0);
		}
		i++;
	}
	write(STDERR_FILENO, "L", 1);
	print_number(count_line);
	write(STDERR_FILENO, ": unknown instruction ", 22);
	write(STDERR_FILENO, s, strlen(s));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
	return (1);
}