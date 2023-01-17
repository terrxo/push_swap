#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack;

	// stack = lst_create_stack(ac, av);
	stack = debug_create_stack(0, 25, 5);
	debug_push_stacks(stack, NULL, 3);
	// debug_print_stack(stack);
	return (0);
}
