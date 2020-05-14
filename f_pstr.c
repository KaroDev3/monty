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
	while (temp != NULL)
	{
		if (temp->n == 0 || (temp->n < 0 || temp->n > 127))
		{
			printf("\n");
			return;
		}
		printf("%c", temp->n);
		temp = temp->prev;
	}
	printf("\n");
}

/*

The opcode pstr prints the string starting at the top of the stack, followed by a new line.

    Usage: pstr
    The integer stored in each element of the stack is treated as the ascii value of the character to be printed
    The string stops when either:
        the stack is over
        the value of the element is 0
        the value of the element is not in the ascii table
    If the stack is empty, print only a new line

*/