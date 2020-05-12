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
		words = split_line(buffer, count_words);
		count_lines++;
		if (words[1] == NULL)
			get_func(words[0], &head, "0", count_lines);
		else
			get_func(words[0], &head, words[1], count_lines);
		free_loop(words);
	}
	free(buffer);
	fclose(fd);
	return (0);
}