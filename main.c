#include "monty.h"

int main(int ac, char *av[])
{
	FILE *fd;
	char *buffer = NULL;
	size_t state_buffer;
	int flag_EOF = 1;
	char **words = NULL;
	int count_words = 0;
	stack_t *head = NULL;
	int count_lines = 0;
	int i, flag = 0, err_inst;

	if (ac != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (!fd)
	{
		write(STDERR_FILENO, "Error: Can't open file ", 18);
		write(STDERR_FILENO, av[1], strlen(av[1]));
		write(STDERR_FILENO, "\n", strlen(av[1]));
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		flag_EOF = getline(&buffer, &state_buffer, fd);
		if (flag_EOF == -1)
			break;
		count_words = countwords(buffer);
		count_lines++;
		words = split_line(buffer, count_words);
		if (words[0] == NULL)
		{
			free(words);
			continue;
		}

		flag = 0;
		if (strcmp("push", words[0]) == 0)
		{
			if (words[1] == NULL)
				flag = 1;
			for (i = 0; flag != 1 && words[1][i] != '\0'; i++)
			{
				if (isdigit(words[1][i]) == 0)
					flag = 1;
			}

			if (flag == 1)
			{
				write(STDERR_FILENO, "L", 1);
				print_number(count_lines);
				write(STDERR_FILENO, ": usage: push integer\n", 22);
				free(buffer);
				free_loop(words);
				free_stack(head);
				fclose(fd);
				exit(EXIT_FAILURE);
			}
		}
		if (head == NULL)
		{
			write(STDERR_FILENO, "L", 1);
			print_number(count_lines);
			write(STDERR_FILENO, ": can't pint, stack empty\n", 26);
			free(buffer);
			free_loop(words);
			free_stack(head);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
		err_inst = 0;
		if (words[1] == NULL)
			err_inst = get_func(words[0], &head, "0");
		else
			err_inst = get_func(words[0], &head, words[1]);
		if (err_inst)
		{
			write(STDERR_FILENO, "L", 1);
			print_number(count_lines);
			write(STDERR_FILENO, ": unknown instruction ", 22);
			write(STDERR_FILENO, words[0], strlen(words[0]));
			write(STDERR_FILENO, "\n", 1);
			free(buffer);
			free_stack(head);
			fclose(fd);
			free_loop(words);
			exit(EXIT_FAILURE);
		}
		free_loop(words);
	}
	free(buffer);
	free_stack(head);
	fclose(fd);
	return (0);
}