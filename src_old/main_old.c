/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:57:30 by iengels           #+#    #+#             */
/*   Updated: 2023/01/16 18:07:55 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(unsigned int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->data = content;
	new->next = NULL;
	new->last = new;
	return (new);
}

void	ft_add_front(t_list *head, unsigned int number)
{
	t_list	*new;

	new = ft_lstnew(number);
	new->next = head;
	new->last = head->last;
	head = new;
}

void	ft_add_back(t_list *begin, unsigned int number) // ads node in the back
{
	begin->last->next = ft_lstnew(number);
	begin->last = begin->last->next;
}

t_list	*ft_happylist(int ac, char **av)
{
	t_list			*head;
	unsigned int	happy;
	unsigned int	j;
	int				i;
	t_list			*shit;

	j = 1;
	head = ft_lstnew(0);
	while (j < ac)
	{
		i = atoi(av[j]);
		if ((i >> 31) & 1)
			happy = i ^ 2147483648;
		else
			happy = i | 2147483648;
		ft_add_back(head, happy);
		j++;
	}
	shit = head->next;
	shit->last = head->last;
	free(head);
	return (shit);
}

void	ft_freeshitting(t_list *head)
{
	if (!(head->next == NULL))
		ft_freeshitting(head->next);
	free(head);
}

void	ft_print_list(t_list *head) // prints out a list;
{
	while (head)
	{
		printf("%u\n", head->data);
		head = head->next;
	}
}

void	ft_applyradix(t_list *head)
{
}

// Rotate list
t_list	*rl(t_list *head)
{
	t_list	*temp;

	temp = head->next;
	temp->last = head;
	head->next = NULL;
	head->last->next = head;
	return (temp);
}

// Reverse rotate list
t_list	*rrl(t_list *head)
{
	t_list	*temp;

	head->last->next = head;
	head = head->last;
	temp = head;
	while (head->next != temp)
		head = head->next;
	head->next = NULL;
	temp->last = head;
	return (temp);
}

// Push a to b list
void	pl(t_list *a, t_list *b)
{
}

int	main(int ac, char **av)
{
	t_list	*head;
	char	*temp[];

	temp[] = {"shithead", "0", "-1", "1"};
	// if (ac <= 1 || ft_is_valid(ac, av) == 1)
	// 	printf("Error");
	// else
	// {
	head = ft_happylist(4, temp);
	// head = ft_happylist(ac, av);
	ft_applyradix(head);
	head = rl(head);
	head = rl(head);
	ft_print_list(head);
	ft_freeshitting(head);
	printf("\n");
	return (0);
}

// int	main(int ac, char **av)
// {
// 	t_list *head;
// 	int i;
// 	int j;
// 	int k;

// 	if (ac == 3)
// 	{
// 		i = atoi(av[1]);
// 		j = atoi(av[2]);
// 		head = ft_lstnew((int)10);
// 		while (i > 0)
// 		{
// 			k = 1;
// 			while (k <= j)
// 			{
// 				ft_add_back(&head, k);
// 				k++;
// 			}
// 			i--;
// 		}
// 		ft_add_front(&head, 1);
// 		ft_print_list(&head);
// 		printf("size of list is: %i\n", ft_list_size(head));
// 	}
// 	else
// 		printf("Wrong input, give 2 Integers as arguments\n");
// 	return (0);
// }