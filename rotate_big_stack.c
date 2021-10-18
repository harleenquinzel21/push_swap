/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_big_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:24:20 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/13 16:37:43 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_final_rotate(t_save *data)
{
	data->to_start = 0;
	data->to_finish = 0;
	data->tmp = data->a;
	if (data->a->index == 1)
		return ;
	while (data->tmp->index != ft_serch_min_elem(data->a)->index)
	{
		data->tmp = data->tmp->next;
		data->to_start += 1;
	}
	while (data->tmp != NULL)
	{
		data->tmp = data->tmp->next;
		data->to_finish += 1;
	}
	if (data->to_start < data->to_finish)
	{
		while (data->a->index != 1)
			ra(data, 1);
	}
	else
	{
		while (data->a->index != 1)
			rra(data, 1);
	}
}

void	ft_rotate_to_min_max(t_save *data)
{
	if (data->index_close_in < data->min->index)
	{
		if (data->min->prev == NULL)
			pa(data, 1);
		else
		{
			ft_rotate_a(data, data->a, data->min->index);
			pa(data, 1);
		}
	}
	else if (data->index_close_in > data->max->index)
	{
		if (data->max->next == NULL)
			pa(data, 1);
		else
		{
			ft_rotate_a(data, data->a, data->max->index);
			ra(data, 1);
			pa(data, 1);
		}
	}
}

void	ft_rotate_a(t_save *data, t_elem *a, int first_index)
{
	data->to_start = 0;
	data->to_finish = 0;
	data->tmp = a;
	while (data->tmp->index != first_index)
	{
		data->tmp = data->tmp->next;
		data->to_start += 1;
	}
	while (data->tmp != NULL)
	{
		data->tmp = data->tmp->next;
		data->to_finish += 1;
	}
	if (data->to_start < data->to_finish)
	{
		while (data->a->index != first_index)
			ra(data, 1);
	}
	else
	{
		while (data->a->index != first_index)
			rra(data, 1);
	}
}

void	ft_rotate_b(t_save *data, t_elem *b, int first_index)
{
	data->to_start = 0;
	data->to_finish = 0;
	data->tmp = b;
	while (data->tmp->index != first_index)
	{
		data->tmp = data->tmp->next;
		data->to_start += 1;
	}
	while (data->tmp != NULL)
	{
		data->tmp = data->tmp->next;
		data->to_finish += 1;
	}
	if (data->to_start < data->to_finish)
	{
		while (data->b->index != first_index)
			rb(data, 1);
	}
	else
	{
		while (data->b->index != first_index)
			rrb(data, 1);
	}
}

int	ft_count_elements(t_elem *a)
{
	t_elem	*tmp;
	int		count;

	if (a == NULL)
		return (0);
	tmp = a;
	count = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		count += 1;
	}
	return (count);
}
