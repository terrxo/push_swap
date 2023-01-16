#include "../push_swap.h"

void	debug_print_stack(t_list *stack)
{
	while (stack->next)
	{
		ft_printf("%u\n", stack->data);
		stack = stack->next;
	}
}