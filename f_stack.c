#include "monty.h"

/**
 * f_stack - Set stack or queue
 * @stack: head of linked list (stack)
 * @line_number: counter lines
 */
void f_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (strcmp("stack", global_var.words[0]) == 0)
		global_var.is_stack = 1;
	else
		global_var.is_stack = 0;
}
