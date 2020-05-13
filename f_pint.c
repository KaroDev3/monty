#include "monty.h"

void f_pint(stack_t **stack, unsigned int n)
{
	stack_t *temp = *stack;
	(void)n;

	if (stack == NULL || *stack == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	printf("%d\n", temp->n);
}
