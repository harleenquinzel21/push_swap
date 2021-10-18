/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:24:11 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/13 16:38:27 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_5_elem(t_save *data, t_elem *min, int flag)
{
	if (flag == 1 || flag == 0)
	{
		while (min->prev != NULL)
			rra(data, 1);
	}
	else
	{
		while (min->prev != NULL)
			ra(data, 1);
	}
}

t_elem	*ft_serch_by_index(t_elem *current, int index)
{
	t_elem	*tmp;

	tmp = current;
	while (tmp->index != index)
		tmp = tmp->next;
	return (tmp);
}

int	ft_serch_min_way_for5(t_elem *current)
{
	int		to_start;
	int		to_finish;
	t_elem	*tmp;

	to_start = 0;
	to_finish = 0;
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
		return (1);
	else if (to_finish > to_start)
		return (2);
	return (0);
}

void	ft_sort_5_elem(t_save *data, int argc)
{
	t_elem	*min;
	int		flag;

	flag = 0;
	min = NULL;
	min = ft_serch_by_index(data->a, 1);
	flag = ft_serch_min_way_for5(min);
	ft_rotate_5_elem(data, min, flag);
	pb(data, 1);
	min = ft_serch_by_index(data->a, 2);
	flag = ft_serch_min_way_for5(min);
	ft_rotate_5_elem(data, min, flag);
	pb(data, 1);
	ft_sort_3_elem(data, argc);
	pa(data, 1);
	pa(data, 1);
	return ;
}

void	ft_sort_3_elem(t_save *data, int argc)
{
	data->max = ft_serch_max_elem(data->a);
	while (data->max->next != NULL)
	{
		if (data->max->prev == NULL)
			ra(data, 1);
		else
			rra(data, 1);
	}
	if (argc == 3)
		return ;
	if (data->a->number > data->a->next->number)
		sa(data, 1);
}
