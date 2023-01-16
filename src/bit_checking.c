int	is_bit_at_pos(unsigned int byte, int pos)
{
	if (byte & 1 << pos)
		return (1);
	return (0);
}

int	is_bit_in_lst_at_pos(t_list *stack, int pos)
{
	int i = 0;
	while (stack)
	{
		i += is_bit_at_pos(stack->data, pos);
		stack = stack->next;
	}
	if (i > 0)
		return (1);
	return (0);
}