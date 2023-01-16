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
	t_list	*start;

	start = stack;
	stack = lst_last(stack);
	new_node = lst_new(data);
	stack->next = new_node;
	new_node->previous = stack;
	start->previous = new_node;
}
