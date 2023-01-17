#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include <fcntl.h>

typedef struct s_list
{
	unsigned int	data;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct s_start_pos
{
	struct s_list	*a;
	struct s_list	*b;
}					t_start_pos;

t_list *
lst_create_stack(int ac, char **av);

t_list				*lst_new(int content);
void				lst_add_back(t_list *start, int data);
t_list				*lst_move_front(t_list *stack, t_list *item);

int					is_bit_at_pos(unsigned int byte, int pos);
int					is_bit_in_lst_at_pos(t_list *stack, int pos);

void				debug_print_stack(t_list *stack);
t_list				*debug_create_stack(int range_lower, int range_upper,
						int count);
void				debug_push_stacks(t_list *a, t_list *b, int count);

void				op_push_stack(t_list *stack_from, t_list *stack_to,
						t_start_pos *stack_pos);

#endif