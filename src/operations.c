#include "../push_swap.h"

t_list	*op_rotate_stack(t_list *stack)
{
	return (stack->previous);
}

t_list	*op_reverse_rotate_stack(t_list *stack)
{
	return (stack->next);
}

void	op_push_stack(t_list *stack_from, t_list *stack_to,
		t_start_pos *stack_pos)
{
	t_list *return_stack;

	stack_from->previous->next = stack_from->next;
	stack_from->next->previous = stack_from->previous;
	if (stack_from == stack_pos->a)
	{
		stack_pos->a = stack_from->next;
		stack_pos->b = stack_from;
	}
	else
	{
		stack_pos->a = stack_from;
		stack_pos->b = stack_from->next;
	}

	if (!stack_to)
	{
		return_stack = stack_from;
		return_stack->next = NULL;
		return_stack->previous = return_stack;
		return ;
	}
	lst_move_front(stack_to, stack_from);
	return ;
}