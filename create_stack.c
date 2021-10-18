/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:24:46 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/13 22:06:20 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_last_elem(t_elem *a)
{
	t_elem	*tmp;

	if (a == NULL)
		return (NULL);
	tmp = a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_add_last(t_elem **a, t_elem *new)
{
	t_elem	*last;

	if ((*a) == NULL)
		(*a) = new;
	else
	{
		last = ft_last_elem(*a);
		last->next = new;
		new->prev = last;
	}
	return ;
}

void	ft_add_first(t_elem *a, t_elem *b)
{
	t_elem	*new;

	new = (t_elem *)malloc(sizeof(t_elem));
	if (new == NULL)
		return ;
	new->next = b;
	b->prev = new;
	b = b->prev;
	b->index = a->index;
	b->number = a->number;
	b->prev = NULL;
}

int	ft_index_checksorted_checkduplicate(t_elem *a, int sorted)
{
	t_elem	*tmp;
	t_elem	*value;

	value = a;
	tmp = a->next;
	while (value != NULL)
	{
		value->index = 1;
		while (tmp != NULL)
		{
			if (value->next != NULL && value->number > value->next->number)
				sorted = 0;
			if (value->number == tmp->number && tmp != value)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			if (value->number > tmp->number)
				value->index += 1;
			tmp = tmp->next;
		}
		value = value->next;
		tmp = a;
	}
	return (sorted);
}

void	ft_init_first_b(t_save *data)
{
	data->b->index = data->a->index;
	data->b->number = data->a->number;
	data->b->prev = NULL;
	data->b->next = NULL;
}
