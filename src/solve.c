#include "../push_swap.h"

int	solve_is_sorted(t_start_pos *stack)
{
	t_list			*loop_stack;
	t_list			*start;
	unsigned int	data_cmp;

	loop_stack = stack->a;
	start = loop_stack;
	while (loop_stack->next != start)
	{
		if (!data_cmp)
			;
		if (loop_stack->data < data_cmp)
			return (0);
		data_cmp = loop_stack->data;
		loop_stack = loop_stack->next;
	}
	return (1);
}
