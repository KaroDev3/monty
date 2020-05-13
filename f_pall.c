#include "monty.h"

void f_pall(stack_t **stack, unsigned int n)
{
	stack_t *temp = *stack;
	(void)n;

	if (stack != NULL && *stack != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
	}
}
