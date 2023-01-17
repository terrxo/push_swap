#include "../push_swap.h"

t_list	*rotate_stack(t_list *stack)
{
	return (stack->previous);
}

t_list	*reverse_rotate_stack(t_list *stack)
{
	return (stack->next);
}

t_list	*push_stack(t_list *stack_from, t_list *stack_to)
{
	t_list *start_stack_from;
	t_list *return_stack;

	stack_from->previous->next = stack_from->next;
	stack_from->next->previous = stack_from->previous;
	start_stack_from = stack_from->next;

	if (!stack_to)
	{
		return_stack = stack_from;
		return_stack->next = NULL;
		return_stack->previous = return_stack;
		return (start_stack_from);
	}
	lst_move_front(stack_to, stack_from);
	return (start_stack_from);
}