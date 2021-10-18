/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:43:46 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/17 17:15:58 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	ft_action_a_b(t_save *data, char *str, int found)
{
	if (str[0] == 's' && str[1] == 's' && str[2] == '\0')
	{
		ss(data, 0);
		return (found += 1);
	}
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && str[3] == '\0')
	{
		rrr(data, 0);
		return (found += 1);
	}
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
	{
		rr(data, 0);
		return (found += 1);
	}
	return (found);
}

int	ft_action_a(t_save *data, char *str, int found)
{
	if (str[0] == 's' && str[1] == 'a' && str[2] == '\0')
	{
		sa(data, 0);
		return (found += 1);
	}
	else if (str[0] == 'p' && str[1] == 'a' && str[2] == '\0')
	{
		pa(data, 0);
		return (found += 1);
	}
	else if (str[0] == 'r' && str[1] == 'a' && str[2] == '\0')
	{
		ra(data, 0);
		return (found += 1);
	}
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && str[3] == '\0')
	{
		rra(data, 0);
		return (found += 1);
	}
	return (found);
}

int	ft_action_b(t_save *data, char *str, int found)
{
	if (str[0] == 's' && str[1] == 'b' && str[2] == '\0')
	{
		sb(data, 0);
		return (found += 1);
	}
	else if (str[0] == 'p' && str[1] == 'b' && str[2] == '\0')
	{
		pb(data, 0);
		return (found += 1);
	}
	else if (str[0] == 'r' && str[1] == 'b' && str[2] == '\0')
	{
		rb(data, 0);
		return (found += 1);
	}
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && str[3] == '\0')
	{
		rrb(data, 0);
		return (found += 1);
	}
	return (found);
}

void	ft_action(t_save *data, char **str, int found)
{
	found = 0;
	while (get_next_line(0, &(*str)))
	{
		found = 0;
		found = ft_action_a(data, *str, found);
		if (found == 0)
			found = ft_action_b(data, *str, found);
		if (found == 0)
			found = ft_action_a_b(data, *str, found);
		if (found == 0)
			ft_print_error_and_free(data, found, str);
		free(*str);
	}
	if (*str[0] != '\0')
		ft_print_error_and_free(data, 0, &(*str));
}

int	main(int argc, char **argv)
{
	t_save	*data;
	int		count;
	int		i;

	data = NULL;
	count = 1;
	i = 0;
	ft_check_arg(argc, NULL, 0);
	data = ft_init_data(data);
	while (count < argc)
	{
		ft_add_last(&data->a, ft_get_new_elem(ft_get_nbr(argv[count], i)));
		count++;
	}
	if (ft_index_checksorted_checkduplicate(data->a, data->sorted) != 0)
		write(1, "OK\n", 3);
	ft_action(data, &data->str, i);
	free(data->str);
	if (ft_checksorted(data->a) != 0)
		write(1, "OK\n", 3);
	if (ft_checksorted(data->a) == 0)
		write(1, "KO\n", 3);
	ft_free(data);
	return (0);
}
