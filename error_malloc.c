#include "monty.h"

/**
 * error_malloc - print error in stderr
 */
void error_malloc()
{
	write(STDERR_FILENO, "Error: malloc failed\n", 21);
	exit(EXIT_FAILURE);
}