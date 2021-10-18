/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:23:10 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/15 22:49:59 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

t_elem	*ft_serch_position(t_elem **a, int index)
{
	t_elem	*tmp;
	t_elem	*max;

	tmp = (*a);
	max = (*a);
	while (tmp != NULL)
	{
		if ((ft_last_elem(*a)->index < index) && (index < tmp->index))
			return (tmp);
		while (tmp->index > index)
			tmp = tmp->next;
		while ((tmp != NULL) && (tmp->index < index))
		{
			tmp = tmp->next;
			max = tmp;
		}
		return (max);
	}
	return (max);
}

t_elem	*ft_serch_max_elem(t_elem *a)
{
	t_elem	*tmp;
	t_elem	*max;

	tmp = a;
	max = a;
	while (tmp != NULL)
	{
		if (max->index < tmp->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_elem	*ft_serch_min_elem(t_elem *a)
{
	t_elem	*tmp;
	t_elem	*min;

	tmp = a;
	min = a;
	while (tmp != NULL)
	{
		if (min->index > tmp->index)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_free(t_save *data)
{
	t_elem	*tmp_next;

	while (data->a != NULL)
	{
		tmp_next = data->a->next;
		free(data->a);
		data->a = tmp_next;
	}
	free(data->b);
	free(data);
}
