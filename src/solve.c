#include "../push_swap.h"

int	solve_is_sorted(t_start_pos *stack)
{
	t_list			*loop_stack;
	t_list			*start;
	unsigned int	data_cmp;
	int				loop;

	loop = 0;
	data_cmp = 0;
	loop_stack = stack->a;
	start = loop_stack;
	while (!loop || loop_stack != start)
	{
		if (!loop)
			loop = 1;
		if (data_cmp && loop_stack->data < data_cmp)
			return (0);
		data_cmp = loop_stack->data;
		loop_stack = loop_stack->next;
	}
	return (1);
}
