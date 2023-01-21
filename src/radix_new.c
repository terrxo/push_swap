// #include "../push_swap.h"

// void	radix_determine_rotation(t_start_pos *start_pos, int bit_pos)
// {
// }

// void	radix_controller(t_start_pos *stack_pos)
// {
// 	int	bit_pos;

// 	bit_pos = -1;
// 	while (++bit_pos < 32)
// 	{
// 		if (solve_is_sorted(stack_pos))
// 			return ;
// 		if (is_bit_in_lst_at_pos(stack_pos->a, bit_pos))
// 		{
// 			radix_determine_rotation(stack_pos, bit_pos);
// 			radix_solve_bit_pos(stack_pos, bit_pos);
// 		}
// 		ft_printf("Updated stack:\n");
// 		debug_print_stack(stack_pos->a);
// 		if (solve_is_sorted(stack_pos))
// 		{
// 			ft_printf("Stack is solved\n");
// 			return ;
// 		}
// 	}
// }

// radix_return_to_start();