#include "monty.h"

/**
 * f_rotr - rotates the stack to the bottom.
 * @stack: head of linked list (stack)
 * @line_number: counter lines
 */
void f_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next->next = NULL;
	temp->next->prev = temp;
}
