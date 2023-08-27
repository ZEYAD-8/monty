#include "monty.h"

/**
 * f_push -> Push an element to the stack
 * @stack: Stack
 * @line_number: Line Number
*/
void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)line_number;
	new_node->n = 111;
	if (lines_m.lines != NULL && lines_m.lines[line_number - 1] != NULL)
		new_node->n = atoi(lines_m.lines[line_number - 1][1]);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * f_pall -> Print all the values on the stack
 * @stack: Stack
 * @line_number: Line Number
*/
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_line = *stack;

	(void) line_number;
	while (stack_line != NULL)
	{
		printf("%d\n", stack_line->n);
		stack_line = stack_line->next;
	}
}

/**
 * f_pint -> Print the value at the top of the stack
 * @stack: Stack
 * @line_number: Line Number
*/
void f_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		f_exit(*stack);
	}
	printf("%d\n", temp->n);
}

/**
 * f_pop -> Removes the top element of the stack
 * @stack: Stack
 * @line_number: Line Number
*/
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		f_exit(*stack);
	}
	if (temp->next == NULL)
	{
		free(temp);
		*stack = NULL;
		return;
	}
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * f_swap -> Swap the top two elements of the stack
 * @stack: Stack
 * @line_number: Line Number
*/
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		f_exit(*stack);
	}
	top->n = top->n + top->next->n;
	top->next->n = top->n - top->next->n;
	top->n = top->n - top->next->n;
}
