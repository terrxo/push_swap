#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack;

	stack = lst_create_stack(ac, av);
	debug_print_stack(stack);
	return (0);
}
