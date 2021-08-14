/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:18 by tigerber          #+#    #+#             */
/*   Updated: 2021/08/14 18:36:45 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	PUSH_SWAP_H
# define 	PUSH_SWAP_H

# include <unistd.h>
# include <strings.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>

typedef struct 		s_list_pile
{
	int					nb;
	struct s_list_pile	*next;

}	                t_list_pile;

typedef struct		s_data
{
	t_list_pile		*pile_a;
	t_list_pile		*pile_b;
	int				i;
	int 			j;
	int				on;
	int				middle;
	int				nb_max;
	int				number;
}	t_data;

void			ft_parsing(char **argv, t_data *d);
void			ft_doublon(char **argv);
void			stock_pile_a(int nb, t_data *d);
void			ft_lstadd_back(t_list_pile **alst, t_list_pile *new);
t_list_pile		*ft_lstnew(int content);
void			ft_lstclear(t_list_pile **lst);
void			ft_lstadd_front(t_list_pile **alst, t_list_pile *new);
void 			ft_rev_lst(t_list_pile **head_ref);
int				ft_count_lst(t_list_pile *lst);
int				pile_a_is_sort(t_data *d);
void			ft_error(int i, char *str);
void			*ft_memset(void *ptr, int c, size_t len);
size_t			ft_strlen(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);
void			function_sa(t_data *d);
void			function_sb(t_data *d);
void			function_ss(t_data *d);
void			function_pa(t_data *d);
void			function_pb(t_data *d);
void			function_ra(t_data *d);
void			function_rb(t_data *d);
void			function_rr(t_data *d);
void			function_rra(t_data *d);
void			function_rrb(t_data *d);
void			function_rrr(t_data *d);
void			ft_small_sort(t_data *d);
void			ft_big_sort(t_data *d);
void			small_sort_three(t_data *d);
void			small_sort_four(t_data *data);
void		    small_sort_four_bis(t_data *data);
void			ft_sort_one_hundred(t_data *d);
void			ft_sort_five_hundred(t_data *d);
void			ft_sort_tab_one_hundred(t_data *d, t_list_pile *lst);
void			ft_sort_tab_five_hundred(t_data *d, t_list_pile *lst);
void			check_pos(t_data *d);
void			compare(t_data *d);
void			compare_max(t_data *d);
void			ft_swap(int *a, int *b);
void			check_max(t_data *d);
void			sort_in_tab_max(t_data *d, t_list_pile *lst);
void			ft_free_tab(int *tab, int size);
void			ft_sort_tab_other(t_data *d, t_list_pile *lst);
void			ft_sort_other(t_data *d);
void			check_middle(t_data *d);

#endif
