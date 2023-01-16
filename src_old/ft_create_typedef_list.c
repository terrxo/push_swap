/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_typedef_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:42:14 by iengels           #+#    #+#             */
/*   Updated: 2023/01/16 18:06:54 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
