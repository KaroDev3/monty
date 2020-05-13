#include "monty.h"

/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: head of linked list (stack)
 * @line_number: counter lines
 */
void f_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		if (temp->n == 0 || (temp->n < 0 || temp->n > 127))
		{
			free(global_var.buffer);
			free_loop(global_var.words);
			free_stack(*stack);
			fclose(global_var.fd);
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		printf("%c", temp->n);
		temp = temp->prev;
	}
}
