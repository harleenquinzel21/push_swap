/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:22:50 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/17 17:03:30 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_save *data, int output)
{
	int	tmp_number;
	int	tmp_index;

	if (data->a == NULL || data->a->next == NULL)
		return ;
	tmp_number = data->a->number;
	tmp_index = data->a->index;
	data->a->index = data->a->next->index;
	data->a->number = data->a->next->number;
	data->a->next->index = tmp_index;
	data->a->next->number = tmp_number;
	if (data->curr_act == 0)
		data->curr_act = 1;
	else
	{
		data->prev_act = data->curr_act;
		data->curr_act = 1;
	}
	if (output > 0)
		ft_print_actions(&(*data), 0);
}

void	sb(t_save *data, int output)
{
	int	tmp_number;
	int	tmp_index;

	if (data->b == NULL || data->b->next == NULL)
		return ;
	tmp_number = data->b->number;
	tmp_index = data->b->index;
	data->b->index = data->b->next->index;
	data->b->number = data->b->next->number;
	data->b->next->index = tmp_index;
	data->b->next->number = tmp_number;
	if (data->curr_act == 0)
		data->curr_act = 2;
	else
	{
		data->prev_act = data->curr_act;
		data->curr_act = 2;
	}
	if (output > 0)
		ft_print_actions(&(*data), 0);
}

void	ss(t_save *data, int output)
{
	sa(data, output);
	sb(data, output);
}

void	pa(t_save *data, int output)
{
	if (data->b == NULL)
		return ;
	ft_add_first(data->b, data->a);
	data->a = data->a->prev;
	if (data->b->next == NULL)
	{
		data->b->index = 0;
		data->b->number = 0;
	}
	else
		data->b = data->b->next;
	free(data->b->prev);
	data->b->prev = NULL;
	data->prev_act = data->curr_act;
	data->curr_act = 0;
	if (output > 0)
		ft_print_actions(&(*data), 2);
}

void	pb(t_save *data, int output)
{
	if (data->a == NULL)
		return ;
	if (data->b == NULL)
		ft_add_last(&data->b, ft_get_new_elem(0));
	if (data->b->index == 0)
		ft_init_first_b(data);
	else
	{
		ft_add_first(data->a, data->b);
		data->b = data->b->prev;
	}
	if (data->a->next == NULL)
	{
		data->a->index = 0;
		data->a->number = 0;
	}
	else
		data->a = data->a->next;
	free(data->a->prev);
	data->a->prev = NULL;
	data->prev_act = data->curr_act;
	data->curr_act = 0;
	if (output > 0)
		ft_print_actions(&(*data), 1);
}
