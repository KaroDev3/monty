#include "monty.h"

/**
 * get_func - selects the correct function to perform
 * @s: monty command passed as argument
 * Return: pointer to the function that corresponds to the operator
 */
int get_func(char *s, stack_t **stack, char *n)
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
	return (1);
}
