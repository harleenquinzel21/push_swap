/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:23:56 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/13 16:37:09 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_steps_to_min_max(t_save *data, t_elem *tmp_b, int steps)
{
	if (tmp_b->index < data->min->index)
	{
		steps = ft_count_to_start_to_finish(tmp_b);
		steps += ft_count_to_start_to_finish(data->min);
	}
	else if (tmp_b->index > data->max->index)
	{
		steps = ft_count_to_start_to_finish(tmp_b);
		steps += ft_count_to_start_to_finish(data->max);
	}
	return (steps);
}

int	ft_count_to_start_to_finish(t_elem *current)
{
	int		to_start;
	int		to_finish;
	t_elem	*tmp;

	to_start = 0;
	to_finish = 1;
	tmp = current;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		to_start += 1;
	}
	tmp = current;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		to_finish += 1;
	}
	if (to_finish < to_start)
		return (to_finish);
	else
		return (to_start);
}

void	ft_sort_index_close_in(t_save *data)
{
	if (data->index_close_in < data->min->index \
	|| data->index_close_in > data->max->index)
		ft_rotate_to_min_max(data);
	else
	{
		ft_rotate_a(data, data->a, ft_serch_position \
		(&data->a, data->index_close_in)->index);
		pa(data, 1);
	}
}

void	ft_serch_min_way(t_save *data)
{
	t_elem	*tmp_a;
	t_elem	*tmp_b;
	int		steps;

	tmp_a = data->a;
	tmp_b = data->b;
	data->steps = 500;
	steps = 0;
	while (tmp_b != NULL)
	{
		if (tmp_b->index < data->min->index || tmp_b->index > data->max->index)
			steps = ft_count_steps_to_min_max(data, tmp_b, steps);
		else
		{
			steps = ft_count_to_start_to_finish(tmp_b);
			tmp_a = ft_serch_position(&data->a, tmp_b->index);
			steps += ft_count_to_start_to_finish(tmp_a);
		}
		if (steps < data->steps)
		{
			data->steps = steps;
			data->index_close_in = tmp_b->index;
		}
		tmp_b = tmp_b->next;
	}
}

void	ft_sort_big_stack(t_save *data, int argc)
{
	int	mid;

	mid = argc / 2;
	while (ft_count_elements(data->a) >= mid)
	{
		if (data->a->index >= mid)
			pb(data, 1);
		else
			ra(data, 1);
	}
	while (ft_count_elements(data->a) > 3)
		pb(data, 1);
	ft_sort_3_elem(data, ft_serch_max_elem(data->a)->index + 1);
	while (data->b->index != 0)
	{
		data->max = ft_serch_max_elem(data->a);
		data->min = ft_serch_min_elem(data->a);
		ft_serch_min_way(data);
		if (data->b->index != data->index_close_in)
			ft_rotate_b(data, data->b, data->index_close_in);
		ft_sort_index_close_in(data);
	}
	ft_final_rotate(data);
	return ;
}
