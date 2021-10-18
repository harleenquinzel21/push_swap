/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:24:27 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/17 15:51:15 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_elem
{
	struct s_elem	*next;
	struct s_elem	*prev;
	int				number;
	int				index;

}t_elem;

typedef struct s_save
{
	struct s_elem	*a;
	struct s_elem	*b;
	struct s_elem	*min;
	struct s_elem	*max;
	struct s_elem	*tmp;
	int				steps;
	int				prev_act;
	int				curr_act;
	int				to_start;
	int				to_finish;
	int				index_close_in;
	int				sorted;
	char			*str;
}t_save;

int		main(int argc, char **argv);
/////push_swap.c/////
t_save	*ft_init_data(t_save *data);
void	ft_check_arg(int argc, char *str, int i);
int		ft_get_nbr(char *str, int i);
t_elem	*ft_get_new_elem(int res);
void	ft_sort(int argc, t_save *data);
/////create_stack.c/////
t_elem	*ft_last_elem(t_elem *a);
void	ft_add_last(t_elem **a, t_elem *new);
void	ft_add_first(t_elem *a, t_elem *b);
int		ft_index_checksorted_checkduplicate(t_elem *a, int sorted);
void	ft_init_first_b(t_save *data);
/////actions.c/////
void	sa(t_save *data, int output);
void	sb(t_save *data, int output);
void	ss(t_save *data, int output);
void	pa(t_save *data, int output);
void	pb(t_save *data, int output);
/////actions2.c/////
void	ra(t_save *data, int output);
void	rb(t_save *data, int output);
void	rr(t_save *data, int output);
void	rra(t_save *data, int output);
void	rrb(t_save *data, int output);
/////actions3.c/////
void	rrr(t_save *data, int output);
void	ft_print_sa_sb_ss(t_save *data);
void	ft_print_ra_rb_rr(t_save *data);
void	ft_print_rra_rrb_rrr(t_save *data);
void	ft_print_actions(t_save *data, int push);
/////sort_small_stack.c/////
void	ft_sort_3_elem(t_save *data, int argc);
void	ft_sort_5_elem(t_save *data, int argc);
void	ft_rotate_5_elem(t_save *data, t_elem *min, int flag);
int		ft_serch_min_way_for5(t_elem *current);
t_elem	*ft_serch_by_index(t_elem *current, int index);
/////sort_big_stack.c/////
void	ft_sort_big_stack(t_save *data, int argc);
void	ft_serch_min_way(t_save *data);
void	ft_sort_index_close_in(t_save *data);
int		ft_count_to_start_to_finish(t_elem *current);
int		ft_count_steps_to_min_max(t_save *data, t_elem *tmp_b, int steps);
/////rotate_big_stack.c/////
void	ft_rotate_a(t_save *data, t_elem *a, int first_index);
void	ft_rotate_b(t_save *data, t_elem *b, int first_index);
void	ft_rotate_to_min_max(t_save *data);
void	ft_final_rotate(t_save *data);
int		ft_count_elements(t_elem *a);
/////utils.c/////
t_elem	*ft_serch_position(t_elem **a, int index);
t_elem	*ft_serch_max_elem(t_elem *a);
t_elem	*ft_serch_min_elem(t_elem *a);
void	ft_free(t_save *data);
size_t	ft_strlen(const char *s);
/////ch_utils.c/////
int		ft_checksorted(t_elem *a);
void	ft_print_error_and_free(t_save *data, int found, char **str);

#endif
