/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:03:40 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/15 17:06:37 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		count;
	int		i;
	t_save	*data;

	count = 1;
	i = 0;
	data = NULL;
	ft_check_arg(argc, NULL, 0);
	data = ft_init_data(data);
	while (count < argc)
	{
		ft_add_last(&data->a, ft_get_new_elem(ft_get_nbr(argv[count], i)));
		count++;
	}
	if (ft_index_checksorted_checkduplicate(data->a, data->sorted) > 0)
		exit(0);
	ft_sort(argc, data);
	if (data->curr_act != 0)
	{
		data->prev_act = data->curr_act;
		data->curr_act = -1;
		ft_print_actions(data, 0);
	}
	ft_free(data);
	return (0);
}
