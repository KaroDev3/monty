#include "monty.h"

/**
 * f_pchar - prints the char at the top of the stack,
 * followed by a new line.
 * @stack: head of linked list (stack)
 * @line_number: counter lines
 */
void f_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(global_var.buffer);
		free_loop(global_var.words);
		free_stack(*stack);
		fclose(global_var.fd);
		exit(EXIT_FAILURE);
	}

	if (temp->n >= 0 && temp->n <= 127)
	{
		while (temp->next != NULL)
			temp = temp->next;

		printf("%c\n", temp->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(global_var.buffer);
		free_loop(global_var.words);
		free_stack(*stack);
		fclose(global_var.fd);
		exit(EXIT_FAILURE);
	}
}
