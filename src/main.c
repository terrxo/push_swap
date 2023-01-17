#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack;

	ft_printf("\nStarting push_swap:\n");
	stack = lst_create_stack(ac, av);
	debug_print_stack(stack);
	return (0);
}

// Main for Debugging
// int	main(void)
// {
// 	ft_printf("\nStarting push_swap in debug mode:\n");
// 	stack = debug_create_stack(0, 25, 5);
// 	debug_push_stacks(stack, NULL, 3);
// 	return (0);
// }
