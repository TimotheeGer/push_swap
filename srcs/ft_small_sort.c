/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:05:40 by tigerber          #+#    #+#             */
/*   Updated: 2021/08/14 18:33:21 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_small_sort(t_data *d)
{
	if (ft_count_lst(d->pile_a) == 2)
		function_sa(d);
	if (ft_count_lst(d->pile_a) == 3)
		small_sort_three(d);
	if (ft_count_lst(d->pile_a) == 4)
		small_sort_four(d);    
}

void	small_sort_three(t_data *d)
{
	int	a;
	int	b;
	int	c;

	a = d->pile_a->nb;
	b = d->pile_a->next->nb;
	c = d->pile_a->next->next->nb;
	if (a > b && b < c && c > a)
		function_sa(d);
	if (a > b && b > c && c < a)
	{
		function_sa(d);
		function_rra(d);
	}
	if (a > b && b < c && c < a)
		function_ra(d);
	if (a < b && b > c && c > a)
	{
		function_sa(d);
		function_ra(d);
	}
	if (a < b && b > c && c < a)
		function_rra(d);
}

void	small_sort_four(t_data *data)
{
	int	a;
	int	b;
	int	c;
	int	d;

	function_pb(data);
	small_sort_three(data);
	a = data->pile_a->nb;
	b = data->pile_a->next->nb;
	c = data->pile_a->next->next->nb;
	d = data->pile_b->nb;
	if (d < a)
		function_pa(data);
	else if (d > a && d < b)
	{
		function_pa(data);
		function_sa(data);
	}
	else if (d > c)
	{
		function_pa(data);
		function_ra(data);
	}
	else if (d < c)
	    small_sort_four_bis(data);
}

void    small_sort_four_bis(t_data *data)
{
	function_rra(data);
	function_pa(data);
	function_ra(data);
	function_ra(data); 
}
