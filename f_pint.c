#include "monty.h"

/**
 * f_pint - prints the value at the top of the stack.
 * @stack: head of linked list (stack)
 * @line_number: counter lines
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(global_var.buffer);
		free_loop(global_var.words);
		free_stack(*stack);
		fclose(global_var.fd);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
		temp = temp->next;

	printf("%d\n", temp->n);
}
