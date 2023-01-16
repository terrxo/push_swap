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
	struct s_list	*last;
}					t_list;

#endif