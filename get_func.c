#include "monty.h"

/**
 * get_func - selects the correct function to perform
 * @stack: linked list
 * @line_number: counter lines
 */
void get_func(stack_t **stack, unsigned int line_number)
{
	instruction_t monty_functions[] = {
	    {"push", f_push},
	    {"pall", f_pall},
	    {"pint", f_pint},
	    {"pop", f_pop},
	    {"pop", f_pop},
	    {"swap", f_swap},
	    {NULL, NULL}};
	int i = 0;

	while (monty_functions[i].opcode != NULL)
	{
		if (strcmp(monty_functions[i].opcode, global_var.words[0]) == 0)
			monty_functions[i].f(stack, line_number);
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n",
		line_number, global_var.words[0]);
	free(global_var.buffer);
	free_stack(*stack);
	fclose(global_var.fd);
	free_loop(global_var.words);
	exit(EXIT_FAILURE);
}
