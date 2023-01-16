#include "../push_swap.h"

t_list	*lst_new(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->data = content;
	new->next = NULL;
	new->last = NULL;
	new->previous = NULL;
	return (new);
}

void	lst_add_back(t_list *start, int data)
{
	t_list *new_node;
	t_list *stack;
	stack = start;
	while (stack->next)
		stack = stack->next;
	new_node = lst_new(data);
	stack->next = new_node;
	new_node->previous = stack;
	start->last = new_node;
}