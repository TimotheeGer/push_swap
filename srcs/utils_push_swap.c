/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:48:12 by tigerber          #+#    #+#             */
/*   Updated: 2021/08/14 18:17:40 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_pos(t_data *d)
{
	t_list_pile	*tmp;

	tmp = d->pile_a;
	while (tmp)
	{
		if (tmp->nb <= d->number)
			break ;
		tmp = tmp->next;
		d->i++;
	}
	ft_rev_lst(&d->pile_a);
	tmp = d->pile_a;
	while (tmp)
	{
		if (tmp->nb <= d->number)
			break ;
		tmp = tmp->next;
		d->j++;
	}
	ft_rev_lst(&d->pile_a);
}

void	check_max(t_data *d)
{
	t_list_pile	*tmp;

	tmp = d->pile_b;
	while (tmp)
	{
		if (tmp->nb == d->nb_max)
			break ;
		tmp = tmp->next;
		d->i++;
	}
	ft_rev_lst(&d->pile_b);
	tmp = d->pile_b;
	while (tmp)
	{
		if (tmp->nb == d->nb_max)
			break ;
		tmp = tmp->next;
		d->j++;
	}
	ft_rev_lst(&d->pile_b);
}

void	check_middle(t_data *d)
{
	t_list_pile *tmp;

	tmp = d->pile_a;
	while (tmp)
	{
		if (tmp->nb < d->middle)
			break ;
		tmp = tmp->next;
		d->i++;
	}
	ft_rev_lst(&d->pile_a);
	tmp = d->pile_a;
	while (tmp)
	{
		if (tmp->nb < d->middle)
			break ;
		tmp = tmp->next;
		d->j++;
	}
	ft_rev_lst(&d->pile_a);
}

void	compare(t_data *d)
{
	if (d->i > 0)
	{
		if (d->j < d->i)
		{
			while (d->j >= 0)
			{
				function_rra(d);
				d->j--;
			}
		}
		else if (d->i <= d->j)
		{
			while (d->i > 0)
			{
				function_ra(d);
				d->i--;
			}
		}
	}
	function_pb(d);
	d->i = 0;
	d->j = 0;
	
}

void	compare_max(t_data *d)
{
	if (d->i > 0)
	{
		if (d->j < d->i)
		{
			while (d->j >= 0)
			{
				function_rrb(d);
				d->j--;
			}
		}
		else if (d->i <= d->j)
		{
			while (d->i > 0)
			{
				function_rb(d);
				d->i--;
			}
		}
	}
	function_pa(d);
	d->i = 0;
	d->j = 0;
}
