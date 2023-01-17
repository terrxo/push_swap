#include "../push_swap.h"

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

t_list	*debug_create_stack(int range_lower, int range_upper, int count)
{
	int		i;
	int		val;
	t_list	*stack;

	i = 0;
	val = 0;
	while (++i <= count)
	{
		// val = debug_print_randoms(range_lower, range_upper);
		if (i == 1)
		{
			stack = lst_new(val);
		}
		else
			lst_add_back(stack, val);
		val++;
	}
	return (stack);
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
