/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:23:38 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/17 17:02:08 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_save *data, int output)
{
	t_elem	*first;
	t_elem	*last;

	if (data->a == NULL || data->a->next == NULL)
		return ;
	first = data->a->next;
	last = ft_last_elem(data->a);
	data->a->prev = last;
	last->next = data->a;
	data->a->next = NULL;
	first->prev = NULL;
	data->a = first;
	if (data->curr_act == 0)
		data->curr_act = 6;
	else
	{
		data->prev_act = data->curr_act;
		data->curr_act = 6;
	}
	if (output > 0)
		ft_print_actions(data, 0);
	return ;
}

void	rb(t_save *data, int output)
{
	t_elem	*first;
	t_elem	*last;

	if (data->b == NULL || data->b->next == NULL)
		return ;
	first = data->b->next;
	last = ft_last_elem(data->b);
	data->b->prev = last;
	last->next = data->b;
	data->b->next = NULL;
	first->prev = NULL;
	data->b = first;
	if (data->curr_act == 0)
		data->curr_act = 7;
	else
	{
		data->prev_act = data->curr_act;
		data->curr_act = 7;
	}
	if (output > 0)
		ft_print_actions(data, 0);
	return ;
}

void	rr(t_save *data, int output)
{
	ra(data, output);
	rb(data, output);
}

void	rra(t_save *data, int output)
{
	t_elem	*first;
	t_elem	*last;

	if (data->a == NULL || data->a->next == NULL)
		return ;
	first = ft_last_elem(data->a);
	last = first->prev;
	last->next = NULL;
	first->next = data->a;
	first->prev = NULL;
	data->a->prev = first;
	data->a = first;
	if (data->curr_act == 0)
		data->curr_act = 9;
	else
	{
		data->prev_act = data->curr_act;
		data->curr_act = 9;
	}
	if (output > 0)
		ft_print_actions(data, 0);
	return ;
}

void	rrb(t_save *data, int output)
{
	t_elem	*first;
	t_elem	*last;

	if (data->b == NULL || data->b->next == NULL)
		return ;
	first = ft_last_elem(data->b);
	last = first->prev;
	last->next = NULL;
	first->next = data->b;
	first->prev = NULL;
	data->b->prev = first;
	data->b = first;
	if (data->curr_act == 0)
		data->curr_act = 10;
	else
	{
		data->prev_act = data->curr_act;
		data->curr_act = 10;
	}
	if (output > 0)
		ft_print_actions(data, 0);
	return ;
}
