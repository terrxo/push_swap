/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_typedef_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:42:14 by iengels           #+#    #+#             */
/*   Updated: 2022/12/12 00:20:09 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list //typedef struct
{
	int data;
	struct s_list *next;
}		t_list;

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->data = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list **lst)
{
	t_list	*last;

	last = *lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_add_back(t_list **beginn, int number) //ads node in the back
{
	t_list *temp;

	temp = *beginn;
	while (temp->next)
		temp = temp->next;
	temp->next = ft_lstnew(number);
}

void	ft_add_front(t_list **head, int number)
{
	t_list	*new;

	new = ft_lstnew(number);
	new->next = *head;
	*head = new;
}

void	ft_print_list(t_list **head) //prints out a list;
{
	t_list *temp;

	temp = *head;
	while (temp)
	{
		printf("%i\n", temp->data);
		temp = temp->next;
	}
}

int	ft_list_size(t_list *head) //gives back list size
{
	if (head == NULL)
		return (0);
	else
		return (1 + ft_list_size(head->next));
}

int	main(int ac, char **av)
{
	t_list	*head;
	int		i;
	int		j;
	int		k;

	if (ac == 3)
	{
		i = atoi(av[1]);
		j = atoi(av[2]);
		head = ft_lstnew((int)10);
		while (i > 0)
		{
			k = 1;
			while (k <= j)
			{
				ft_add_back(&head, k);
				k++;
			}
			i--;
		}
		ft_add_front(&head, 1);
		ft_print_list(&head);
		printf("size of list is: %i\n", ft_list_size(head));
	}
	else
		printf("Wrong input, give 2 Integers as arguments\n");
	return (0);
}
