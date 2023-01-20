#include "../push_swap.h"

int	is_bit_at_pos(unsigned int byte, int pos)
{
	// debug_printBits(1, &byte);
	if (!((byte >> pos) & 1))
		return (1);
	return (0);
}

int	is_bit_in_lst_at_pos(t_list *stack, int pos)
{
	int i = 0;
	int loop = 0;
	t_list *start;
	start = stack;
	while ((!loop && stack->next != start) || stack != start)
	{
		if (!loop)
			loop = 1;
		i += is_bit_at_pos(stack->data, pos);
		stack = stack->next;
	}
	if (i > 0)
		return (1);
	return (0);
}