/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:23:30 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/17 17:59:15 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_save *data, int output)
{
	rra(data, output);
	rrb(data, output);
}

void	ft_print_sa_sb_ss(t_save *data)
{
	if ((data->prev_act == 1 && data->curr_act == 2) \
	 || (data->prev_act == 2 && data->curr_act == 1))
	{
		write(1, "ss\n", 3);
		data->prev_act = 0;
		data->curr_act = 0;
	}
	else if (data->prev_act == 1)
	{
		write(1, "sa\n", 3);
		data->prev_act = 0;
	}
	else if (data->prev_act == 2)
	{
		write(1, "sb\n", 3);
		data->prev_act = 0;
	}
}

void	ft_print_ra_rb_rr(t_save *data)
{
	if ((data->prev_act == 6 && data->curr_act == 7) \
	 || (data->prev_act == 7 && data->curr_act == 6))
	{
		write(1, "rr\n", 3);
		data->prev_act = 0;
		data->curr_act = 0;
	}
	else if (data->prev_act == 6)
	{
		write(1, "ra\n", 3);
		data->prev_act = 0;
	}
	else if (data->prev_act == 7)
	{
		write(1, "rb\n", 3);
		data->prev_act = 0;
	}
}

void	ft_print_rra_rrb_rrr(t_save *data)
{
	if ((data->prev_act == 9 && data->curr_act == 10) \
	 || (data->prev_act == 10 && data->curr_act == 9))
	{
		write(1, "rrr\n", 4);
		data->prev_act = 0;
		data->curr_act = 0;
	}
	else if (data->prev_act == 9)
	{
		write(1, "rra\n", 4);
		data->prev_act = 0;
	}
	else if (data->prev_act == 10)
	{
		write(1, "rrb\n", 4);
		data->prev_act = 0;
	}
}

void	ft_print_actions(t_save *data, int push)
{
	if ((data->prev_act == 1) || data->prev_act == 2)
		ft_print_sa_sb_ss(data);
	if ((data->prev_act == 6) || data->prev_act == 7)
		ft_print_ra_rb_rr(data);
	if ((data->prev_act == 9) || data->prev_act == 10)
		ft_print_rra_rrb_rrr(data);
	if (push == 1)
		write(1, "pb\n", 3);
	if (push == 2)
		write(1, "pa\n", 3);
}
