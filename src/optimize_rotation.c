#include "../push_swap.h"

int	check_reverse_rotate(t_list *stack, int pos)
{
	t_list	*start;
	int		rotations;

	start = stack;
	rotations = 1;
	if (is_bit_at_pos(stack->data, pos))
		return (0);
	stack = stack->previous;
	while (stack != start)
	{
		if (is_bit_at_pos(stack->data, pos) == 1)
			return (rotations);
		rotations++;
		stack = stack->previous;
	}
	return (-1);
}

int	check_rotate(t_list *stack, int pos)
{
	t_list	*start;
	int		rotations;

	start = stack;
	rotations = 1;
	if (is_bit_at_pos(stack->data, pos))
		return (0);
	stack = stack->next;
	while (stack != start)
	{
		if (is_bit_at_pos(stack->data, pos) == 1)
			return (rotations);
		rotations++;
		stack = stack->next;
	}
	return (-1);
}

int	is_rotate_faster(t_start_pos *stack_pos, int pos)
{
	int	rotate;
	int	reverse_rotate;

	rotate = check_rotate(stack_pos->a, pos);
	reverse_rotate = check_reverse_rotate(stack_pos->a, pos);
	// if (rotate < reverse_rotate)
	// {
	stack_pos->no_of_rotation = rotate;
	return (1);
	// }
	// else
	// stack_pos->no_of_rotation = reverse_rotate;
	return (0);
}

int	check_next_no_of_rotations(t_list *stack, int pos)
{
	t_list	*start;
	int		rotations;

	start = stack;
	rotations = 1;
	if (is_bit_at_pos(stack->data, pos))
		return (0);
	stack = stack->next;
	while (stack != start)
	{
		if (is_bit_at_pos(stack->data, pos) == 1)
			return (rotations);
		rotations++;
		stack = stack->next;
	}
	return (0);
}

// void	check_rotation(t_start_pos *stack_pos, int pos)
// {
// 	if (stack_)
// }