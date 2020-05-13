#include "monty.h"

void f_pop(stack_t **stack, unsigned int n)
{
	stack_t *temp = *stack;
	(void)n;

	if (stack == NULL || *stack == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	if (temp->prev != NULL)
		temp->prev->next = NULL;
	else
		*stack = NULL;

	free(temp);
}
