#include "../push_swap.h"

t_list	*lst_new(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->data = content;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

t_list	*lst_last(t_list *stack)
{
	t_list	*start;

	start = stack;
	while (stack->next && stack->next != start)
		stack = stack->next;
	return (stack);
}

void	lst_add_back(t_list *stack, int data)
{
	t_list	*new_node;
	t_list	*last;

	new_node = lst_new(data);
	if (!stack->previous || !stack->next)
	{
		stack->previous = new_node;
		stack->next = new_node;
		new_node->next = stack;
		new_node->previous = stack;
		return ;
	}
	last = stack->previous;
	last->next = new_node;
	new_node->previous = last;
	new_node->next = stack;
	stack->previous = new_node;
}

t_list	*lst_move_front(t_list *stack, t_list *item)
{
	item->previous = stack->previous;
	item->previous->next = item;
	item->next = stack;
	stack->previous = item;
	return (item);
}

void	lst_determine_start_pos(t_start_pos *stack_pos, t_list *stack_from,
		int id)
{
	t_list	*check_last;

	if (id == 1)
	{
		stack_pos->a = stack_from->next;
		stack_pos->b = stack_from;
	}
	else if (id == 0)
	{
		check_last = stack_pos->b;
		stack_pos->b = stack_from->next;
		stack_pos->a = stack_from;
		if (check_last == check_last->next
			&& check_last == check_last->previous)
			stack_pos->b = NULL;
	}
	stack_pos->is_sender_a = id;
}
