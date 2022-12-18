/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:57:30 by iengels           #+#    #+#             */
/*   Updated: 2022/12/18 08:07:34 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list // typedef struct
{
	unsigned int data;
	struct s_list *next;
	struct s_list *last;
} t_list;

t_list *ft_lstnew(unsigned int content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->data = content;
	new->next = NULL;
	return (new);
}

void ft_add_front(t_list *head, unsigned int number)
{
	t_list *new;

	new = ft_lstnew(number);
	new->next = head;
	head = new;
}

void ft_add_back(t_list *beginn, unsigned int number) // ads node in the back
{
	t_list *temp;

	temp = beginn;
	while (temp->next)
		temp = temp->next;
	temp->next = ft_lstnew(number);
}

// int	ft_error2(char *str, int minus)
// {
// 	if (minus == 1)
// 	{
// 		if (ft_strlen(&str[1]) == 10 && (ft_strcmp(str, "-2147483648") > 0))
// 			return (1);
// 		else if (ft_strlen(&str[1]) > 10)
// 			return (1);
// 		else
// 			return (0);
// 	}
// 	else
// 	{
// 		if (ft_strlen(str) == 10 && (ft_strcmp(str, "2147483647") > 0))
// 			return (1);
// 		else if (ft_strlen(str) > 10)
// 			return (1);
// 		else
// 			return (0);
// 	}
// }
// int	ft_error(char *str)
// {
// 	int	i;
// 	int	minus;

// 	minus = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (!(str[i] >= '0' && str[i] <= '9'))
// 		{
// 			if (str[i] == '-' && minus == 0)
// 				minus = 1;
// 			else
// 				return (1);
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	return (ft_error2(str, minus));
// }

// int	ft_is_valid(int ac, char **av)
// {
// 	int	i;

// 	i = 1;
// 	while (i > ac)
// 	{
// 		if (ft_error_1(av[i]) == 1)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

t_list *ft_happylist(int ac, char **av)
{
	t_list *head;
	unsigned int happy;
	unsigned int j;
	int i;
	t_list *shit;

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
	free(head);
	return (shit);
}

void ft_freeshitting(t_list *head)
{
	if (!(head->next == NULL))
		ft_freeshitting(head->next);
	free(head);
}

void ft_print_list(t_list *head) // prints out a list;
{
	while (head)
	{
		printf("%u\n", head->data);
		head = head->next;
	}
}

void ft_applyradix(t_list *head)
{
}

void rl(t_list *head)
{
}
void rrl(t_list *head)
{
}
void pl(t_list *a, t_list *b)
{
}

int main(int ac, char **av)
{
	t_list *head;

	// if (ac <= 1 || ft_is_valid(ac, av) == 1)
	// 	printf("Error");
	// else
	// {
	head = ft_happylist(ac, av);
	ft_applyradix(head);
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