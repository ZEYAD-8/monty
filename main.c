#include "monty.h"

lines_t lines_m;

/**
 * main - monty function to implement stacks and queues functionality
 * @ac: number of arguments
 * @av: the arguments
 *
 * Return: 0 on success, 1 on error
*/
int main(int ac, char **av)
{
	stack_t *stack = NULL;
	unsigned int i;
	void (*function)(stack_t **, unsigned int);

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		f_exit(stack);
	}
	lines_m.word_line = malloc(1024 * sizeof(int));
	tokenize_file(av[1]);
	for (i = 0; i < lines_m.lines_count && lines_m.lines[i] != NULL; i++)
	{
		if (lines_m.lines[i][0][0] == '#')
		{
			continue;
		}
		function = get_function(lines_m.lines[i][0]);
		if (function == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction\n", (i + 1));
			f_exit(stack);
		}
		function(&stack, i + 1);
	}
	if (stack != NULL)
		free_stack(stack);

	if (lines_m.lines != NULL || lines_m.word_line != NULL)
		free_lines();
	return (0);
}


/**
 * get_function -> Executes the opcode
 * @word: Opcode
 * Return:Pointer to the respective function to the provided opcode
*/
void (*get_function(char *word))(stack_t **, unsigned int)
{
	int opcodes_count, i;

	instruction_t opcode[] = {
	{"push", f_push},
	{"pall", f_pall},
	{"pint", f_pint},
	{"pop", f_pop},
	{"swap", f_swap},
	{"add", f_add},
	{"nop", f_nop},
	{"mul", f_mul},
	{"div", f_div},
	{"mod", f_mod},
	{"sub", f_sub},
	{"pchar", f_pchar},
	{"pstr", f_pstr},
	{"rotl", f_rotl},
	{"rotr", f_rotr}
	};

	opcodes_count = 15;
	for (i = 0; i < opcodes_count; i++)
	{
		if (strcmp(opcode[i].opcode, word) == 0)
		{
			return (opcode[i].f);
		}
	}
	return (NULL);
}


