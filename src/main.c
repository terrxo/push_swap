#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_list		*stack;
	t_start_pos	*stack_pos;

	ft_printf("\nStarting push_swap:\n");
	stack_pos = malloc(sizeof(t_start_pos));
	if (!stack_pos)
		return (1);
	// stack = lst_create_stack(ac, av);
	stack = debug_create_stack(0, 15, 6);
	stack_pos->a = stack;
	debug_print_stack(stack_pos->a);
	// ft_printf("Is sorted: %i\n", solve_is_sorted(stack_pos));
	if (solve_is_sorted(stack_pos))
		return (0);
	radix_controller(stack_pos);
	// debug_print_stack(stack_pos->a);
	return (0);
}

// Main for Debugging
// int	main(void)
// {
// 	ft_printf("\nStarting push_swap in debug mode:\n");
// 	stack = debug_create_stack(0, 25, 5);
// printf("is stack sorted: %i\n", solve_is_sorted(stack_pos));
// 	debug_push_stacks(stack, NULL, 3);
// 	return (0);
// }
