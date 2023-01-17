#include "../push_swap.h"

void	op_rotate_stack(t_start_pos *stack_pos, t_list *stack)
{
	if (stack_pos->a == stack)
		stack_pos->a = stack_pos->a->previous;
	else
		stack_pos->b = stack_pos->b->previous;
}

void	op_reverse_rotate_stack(t_start_pos *stack_pos, t_list *stack)
{
	if (stack_pos->a == stack)
		stack_pos->a = stack_pos->a->next;
	else
		stack_pos->b = stack_pos->b->next;
}

void	op_push_stack(t_list *stack_from, t_list *stack_to,
		t_start_pos *stack_pos)
{
	t_list	*return_stack;

	if (!stack_from)
		exit(ft_printf("Stack you're trying to push from is empty!\n"));
	stack_from->previous->next = stack_from->next;
	stack_from->next->previous = stack_from->previous;
	if (stack_from == stack_pos->a)
		lst_determine_start_pos(stack_pos, stack_from, 1);
	else
		lst_determine_start_pos(stack_pos, stack_from, 0);
	if (!stack_to)
	{
		return_stack = stack_from;
		return_stack->next = NULL;
		return_stack->previous = return_stack;
		return ;
	}
	lst_move_front(stack_to, stack_from);
	if (stack_pos->a == stack_pos->b)
	{
		if (stack_pos->is_sender_a)
			stack_pos->a = NULL;
		else
			stack_pos->b = NULL;
	}
}
