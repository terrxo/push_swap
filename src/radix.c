#include "../push_swap.h"

void	radix_rotate_stack(t_start_pos *stack_pos, int use_rotate)
{
	int	repetition;

	repetition = stack_pos->no_of_rotation;
	repetition++;
	while (--repetition)
	{
		if (use_rotate)
			op_rotate_stack(stack_pos, stack_pos->a);
		else
			op_reverse_rotate_stack(stack_pos, stack_pos->a);
	}
	stack_pos->no_of_rotation = 0;
}

void	radix_solve_bit_pos(t_start_pos *stack_pos, int bit_pos)
{
	int		is_bit;
	t_list	*start;

	is_bit = 1;
	is_rotate_faster(stack_pos, bit_pos);
	is_bit = is_bit_in_lst_at_pos(stack_pos->a, bit_pos);
	while (!stack_pos->no_of_rotation && is_bit)
	{
		op_push_stack(stack_pos->a, stack_pos->b, stack_pos);
		is_rotate_faster(stack_pos, bit_pos);
		is_bit = is_bit_in_lst_at_pos(stack_pos->a, bit_pos);
	}
	start = stack_pos->a;
	while (is_bit)
	{
		if (is_rotate_faster(stack_pos, bit_pos))
		{
			radix_rotate_stack(stack_pos, 1);
		}
		else
			radix_rotate_stack(stack_pos, 0);
		op_push_stack(stack_pos->a, stack_pos->b, stack_pos);
		is_bit = is_bit_in_lst_at_pos(stack_pos->a, bit_pos);
	}
	stack_pos->a = start;
	while (stack_pos->b)
		op_push_stack(stack_pos->b, stack_pos->a, stack_pos);
}

void	radix_controller(t_start_pos *stack_pos)
{
	int bit_pos;
	bit_pos = -1;
	while (++bit_pos < 32)
	{
		if (solve_is_sorted(stack_pos))
			return ;
		if (is_bit_in_lst_at_pos(stack_pos->a, bit_pos))
			radix_solve_bit_pos(stack_pos, bit_pos);
		ft_printf("Updated stack:\n");
		debug_print_stack(stack_pos->a);
		if (solve_is_sorted(stack_pos))
		{
			ft_printf("Stack is solved\n");
			return ;
		}
	}
}