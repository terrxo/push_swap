#include "../push_swap.h"

void	debug_printBits(size_t const size, void const *const ptr)
{
	unsigned char	*b;
	unsigned char	byte;

	b = (unsigned char *)ptr;
	int i, j;
	for (i = size - 1; i >= 0; i--)
	{
		for (j = 7; j >= 0; j--)
		{
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	puts("");
}

void	debug_print_stack(t_list *stack)
{
	t_list	*last;

	if (!stack)
	{
		ft_printf("Stack empty!\n");
		return ;
	}
	last = stack->previous;
	while (stack != last)
	{
		ft_printf("%u\n", stack->data);
		stack = stack->next;
	}
	ft_printf("%u\n", stack->data);
}

int	debug_print_randoms(int lower, int upper)
{
	int num = (rand() %
				(upper - lower + 1)) +
		lower;
	return (num);
}

void	debug_push_stacks(t_list *a, t_list *b, int count)
{
	t_start_pos	*stack_pos;
	int			count2;

	count2 = count;
	stack_pos = malloc(sizeof(t_start_pos));
	stack_pos->a = a;
	stack_pos->b = b;
	while (count--)
	{
		op_push_stack(stack_pos->a, stack_pos->b, stack_pos);
		ft_printf("Stack a:\n");
		debug_print_stack(stack_pos->a);
		ft_printf("Stack b:\n");
		debug_print_stack(stack_pos->b);
		ft_printf("\n\n");
	}
	count = count2;
	while (count2--)
	{
		op_push_stack(stack_pos->b, stack_pos->a, stack_pos);
		ft_printf("Stack a:\n");
		debug_print_stack(stack_pos->a);
		ft_printf("Stack b:\n");
		debug_print_stack(stack_pos->b);
		ft_printf("\n\n");
	}
	while (count--)
	{
		op_push_stack(stack_pos->a, stack_pos->b, stack_pos);
		ft_printf("Stack a:\n");
		debug_print_stack(stack_pos->a);
		ft_printf("Stack b:\n");
		debug_print_stack(stack_pos->b);
		ft_printf("\n\n");
	}
}

t_list	*debug_create_stack(int range_lower, int range_upper, int count)
{
	int i;
	t_list *stack;
	// int val[6] = {15, 23, 101, 71, 84, 30};
	int val;
	i = -1;
	while (++i < count)
	{
		val = debug_print_randoms(range_lower, range_upper);
		if (i == 0)
		{
			stack = lst_new(val);
		}
		else
			lst_add_back(stack, val);
	}
	return (stack);
}