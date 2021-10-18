/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:04:43 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/16 21:50:25 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 65000
# define BUFFER_SIZE 100

int		get_next_line(int fd, char **line);
int		cut_nl_rem_to_line(char **line, char **remainder, char *ptr_nl);
char	*read_file(int fd, char *remainder, char *buffer);
char	*ft_strchr_nl(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *remainder, char *buffer);

#endif
