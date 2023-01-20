#include "../push_swap.h"

int	check_reverse_rotate(t_list *stack, int pos)
{
	t_list	*start;
	int		rotations;
	int		loop;

	loop = 0;
	start = stack;
	rotations = 0;
	while (!loop || stack != start)
	{
		if (!loop)
			loop = 1;
		if (is_bit_at_pos(stack->data, pos) == 1)
			return (rotations);
		stack = stack->next;
		if (stack != start)
			rotations++;
		rotations++;
	}
	return (-1);
}

int	check_rotate(t_list *stack, int pos)
{
	t_list	*start;
	int		rotations;
	int		loop;

	loop = 0;
	start = stack;
	rotations = 0;
	while (!loop || stack != start)
	{
		if (!loop)
			loop = 1;
		if (is_bit_at_pos(stack->data, pos) == 1)
			return (rotations);
		stack = stack->previous;
		if (stack != start)
			rotations++;
	}
	return (-1);
}

int	is_rotate_faster(t_start_pos *stack_pos, int pos)
{
	int rotate = check_rotate(stack_pos->a, pos);
	int reverse_rotate = check_reverse_rotate(stack_pos->a, pos);
	// if (rotate < reverse_rotate)
	// {
	stack_pos->no_of_rotation = rotate;
	return (1);
	// }
	// else
	// 	stack_pos->no_of_rotation = reverse_rotate;
	// return (0);
}