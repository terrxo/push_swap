#include "../push_swap.h"

t_list	*lst_create_stack(int ac, char **av)
{
	t_list *stack;
	unsigned int data;
	int i = 0;
	while (i++ < ac)
	{
		i = ft_atoi(av[i]);
		if ((i >> 31) & 1)
			data = i ^ 2147483648;
		else
			data = i | 2147483648;
		if (i == 1)
			stack = lst_new(data);
		else
			lst_add_back(stack, data);
	}
	return (0);
}