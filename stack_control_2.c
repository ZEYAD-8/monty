#include "monty.h"

/**
  * f_add - addition
  * @stack: stack head
  * @line_number: line_number
  * Return: no return
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int add_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		f_exit(*stack);
	}
	add_node = top->next->n + top->n;
	*stack = top->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(top);
	if (*stack != NULL)
	{
		(*stack)->n = add_node;
	}
}

/**
 * f_nop -> Does nothing
 * @stack: pointer to top of the stack
 * @line_number: line_number
 * Return: nothing
*/
void f_nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void) stack;
}

/**
  * f_sub - sustration
  * @stack: stack head
  * @line_number: line_number
  * Return: no return
 */
void f_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int sub_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		f_exit(*stack);
	}

	sub_node = top->next->n - top->n;
	*stack = top->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(top);
	if (*stack != NULL)
	{
		(*stack)->n = sub_node;
	}
}

/**
  * f_div - division
  * @stack: stack head
  * @line_number: line_number
  * Return: no return
 */
void f_div(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int div_node;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		f_exit(*stack);
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		f_exit(*stack);
	}
	div_node = top->next->n / top->n;
	temp = top;
	*stack = top->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
	if (*stack != NULL)
	{
		(*stack)->n = div_node;
	}
}

/**
  * f_mul- multiplication
  * @stack: stack head
  * @line_number: line_number
  * Return: no return
 */
void f_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *temp;
	int mul_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		f_exit(*stack);
	}
	mul_node = top->next->n * top->n;
	temp = top;
	*stack = top->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
	if (*stack != NULL)
	{
		(*stack)->n = mul_node;
	}
}


