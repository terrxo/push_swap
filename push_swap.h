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

t_list				*lst_create_stack(int ac, char **av);

t_list				*lst_new(int content);
void				lst_add_back(t_list *start, int data);
void				lst_move_front(t_list *stack, t_list *item);

int					is_bit_at_pos(unsigned int byte, int pos);
int					is_bit_in_lst_at_pos(t_list *stack, int pos);

void				debug_print_stack(t_list *stack);

#endif