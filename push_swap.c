/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:24:37 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/18 15:43:43 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_save	*ft_init_data(t_save *data)
{
	data = (t_save *)malloc(sizeof(t_save));
	if (data == NULL)
		exit (0);
	data->a = NULL;
	data->b = NULL;
	data->min = NULL;
	data->max = NULL;
	data->tmp = NULL;
	data->str = NULL;
	data->sorted = 1;
	data->to_start = 0;
	data->to_finish = 0;
	data->steps = 500;
	data->index_close_in = 0;
	data->prev_act = 0;
	data->curr_act = 0;
	return (data);
}

void	ft_sort(int argc, t_save *data)
{
	if (argc <= 4)
		ft_sort_3_elem(data, argc);
	if (argc <= 6 && argc > 4)
		ft_sort_5_elem(data, argc);
	if (argc > 6)
		ft_sort_big_stack(data, argc);
}

void	ft_check_arg(int argc, char *str, int i)
{
	if ((argc == 1) || (argc == 2))
		exit (0);
	if (str == NULL)
		return ;
	if ((str[i] < '0' || str[i] > '9') && \
	(str[i + 1] < '0' || str[i + 1] > '9'))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

t_elem	*ft_get_new_elem(int res)
{
	t_elem	*new;

	new = (t_elem *)malloc(sizeof(t_elem));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->number = res;
	new->index = 0;
	return (new);
}

int	ft_get_nbr(char *str, int i)
{
	long long int	res;
	int				sign;

	res = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-' || str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0')
	{
		ft_check_arg(3, str, i);
		res = (long long int)(str[i] - '0') + res * 10;
		i++;
	}
	res = (long long int)res * sign;
	if ((res < -2147483648 || res > 2147483647) || (ft_strlen(str) > 10))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return ((int)res);
}
