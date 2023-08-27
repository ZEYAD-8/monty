#include "monty.h"

/**
  * f_mod - division
  * @stack: stack head
  * @line_number: line_number
  * Return: no return
 */
void f_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int mod_node;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		f_exit(*stack);
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		f_exit(*stack);
	}
	mod_node = top->next->n % top->n;
	temp = top;
	*stack = top->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
	if (*stack != NULL)
	{
		(*stack)->n = mod_node;
	}
}

/**
 * f_pchar -> Print the char at the top of the stack
 * @stack: Stack Head.
 * @line_number: Line Number.
 */
void f_pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		f_exit(*stack);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		f_exit(*stack);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * f_pstr -> Print the string starting at the top of the stack
 * @stack: Stack Head.
 * @line_number: Line Number.
 */
void f_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	(void) line_number;
	while (top != NULL)
	{
		if (top->n <= 0 || top->n > 127)
		{
			break;
		}
		printf("%c", top->n);
		top = top->next;
	}
	printf("\n");
}

/**
 * f_rotl -> Rotates the stack to the top
 * @stack: Stack Head
 * @line_number: Line Number
 * Return: no return
 */
void f_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (h->next != NULL)
		h = h->next;
	h->next = *stack;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	h->next->next = NULL;
	h->next->prev = h;
}

/**
  * f_rotr- rotates the stack to the bottom
  * @stack: stack head
  * @line_number: line_number
  * Return: no return
 */
void f_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (h->next != NULL)
		h = h->next;
	h->prev->next = NULL;
	h->next = *stack;
	h->prev = NULL;
	(*stack)->prev = h;
	*stack = h;
}
