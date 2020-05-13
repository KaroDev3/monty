#include "monty.h"

/**
 * f_rotl - rotates the stack to the top.
 * @stack: head of linked list (stack)
 * @line_number: counter lines
 */
void f_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	temp->prev->next = NULL; /* update new top */
	(*stack)->prev = temp;	 /* head becomes 2d position */
	temp->next = *stack;	 /* top becomes head */
	temp->prev = NULL;	 /* top becomes head */
	*stack = temp;		 /* update head */
}
