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
	int				is_sender_a;
	int				no_of_rotation;
}					t_start_pos;

t_list *
lst_create_stack(int ac, char **av);

t_list				*lst_new(int content);
void				lst_add_back(t_list *start, int data);
t_list				*lst_move_front(t_list *stack, t_list *item);
void	lst_determine_start_pos(t_start_pos *stack_pos,
								t_list *stack_from,
								int id);

int					is_bit_at_pos(unsigned int byte, int pos);
int					is_bit_in_lst_at_pos(t_list *stack, int pos);
int					is_rotate_faster(t_start_pos *stack_pos, int pos);

void				debug_print_stack(t_list *stack);
t_list				*debug_create_stack(int range_lower, int range_upper,
						int count);
void				debug_push_stacks(t_list *a, t_list *b, int count);
void				debug_printBits(size_t const size, void const *const ptr);

void				op_push_stack(t_list *stack_from, t_list *stack_to,
						t_start_pos *stack_pos);
void	op_reverse_rotate_stack(t_start_pos *stack_pos,
								t_list *stack);
void				op_rotate_stack(t_start_pos *stack_pos, t_list *stack);

int					solve_is_sorted(t_start_pos *stack);

void				radix_controller(t_start_pos *stack_pos);

#endif