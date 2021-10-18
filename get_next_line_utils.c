/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:53:26 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/17 15:41:01 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

int	ft_checksorted(t_elem *a)
{
	t_elem	*tmp;
	int		sorted;

	sorted = 1;
	tmp = a;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			sorted = 0;
		tmp = tmp->next;
	}
	return (sorted);
}

void	ft_print_error_and_free(t_save *data, int found, char **str)
{
	if (found == 0)
	{
		write(1, "Error\n", 6);
		if (str != NULL)
			free(*str);
		ft_free(data);
		exit (0);
	}
	else
		return ;
}

char	*ft_strchr_nl(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*new;
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen(str) + 1;
	new = (char *)malloc(sizeof(char) * size);
	if (!(new))
		return (0);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *rem, char *buf)
{
	char	*res;
	int		i;
	int		j;

	if (!rem)
		return (ft_strdup(buf));
	res = (char *)malloc(sizeof(char) * (ft_strlen(rem) + ft_strlen(buf) + 1));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (rem[j])
		res[i++] = rem[j++];
	j = 0;
	while (buf[j])
		res[i++] = buf[j++];
	free(rem);
	res[i] = '\0';
	return (res);
}
