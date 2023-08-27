#include "monty.h"

/**
 * free_lines - frees the global structure lines.m
 * Return: nothing
*/
void free_lines(void)
{
	int j, word_num;
	unsigned int i;

	if (lines_m.lines == NULL)
	{
		goto WORD_LINE_ONLY_FREE;
	}
	for (i = 0; i < lines_m.lines_count; i++)
	{
		word_num = lines_m.word_line[i];
		for (j = 0; j < word_num; j++)
		{
			if (lines_m.lines[i][j] != NULL)
			{
				free(lines_m.lines[i][j]);
			}
		}
		free(lines_m.lines[i]);
	}
	free(lines_m.lines);
WORD_LINE_ONLY_FREE:
	if (lines_m.word_line != NULL)
		free(lines_m.word_line);
}

/**
 * free_stack - frees the stack
 * @top: the pointer to the stack
 * Return: nothing
*/
void free_stack(stack_t *top)
{
	stack_t *next_a;

	while (top != NULL)
	{
		next_a = top->next;
		free(top);
		top = next_a;
	}
}

/**
 * f_exit - frees the memory and then exists
 * @stack: top of the stack
 * Retrun: nothing
*/
void f_exit(stack_t *stack)
{
	if (stack != NULL)
		free_stack(stack);

	if (lines_m.lines != NULL || lines_m.word_line != NULL)
		free_lines();

	exit(EXIT_FAILURE);
}
