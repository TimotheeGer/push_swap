/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_swap_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:29:14 by tigerber          #+#    #+#             */
/*   Updated: 2021/08/14 18:38:58 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	function_sa(t_data *d)
{
	t_list_pile	*tmp;

	if (!d->pile_a || !d->pile_a->next)
		return ;
	tmp = d->pile_a->next;
	d->pile_a->next = d->pile_a->next->next;
	tmp->next = d->pile_a;
	d->pile_a = tmp;
	if (!d->on)
		write(1, "sa\n", 3);
}

void	function_sb(t_data *d)
{
	t_list_pile	*tmp;

	if (!d->pile_b || !d->pile_b->next)
		return ;
	tmp = d->pile_b->next;
	d->pile_b->next = d->pile_b->next->next;
	tmp->next = d->pile_b;
	d->pile_b = tmp;
	if (!d->on)
		write(1, "sb\n", 3);
}

void	function_ss(t_data *d)
{
	if (!d->pile_a || !d->pile_b)
		return ;
	d->on = 1;
	function_sa(d);
	function_sb(d);
	d->on = 0;
	write(1, "ss\n", 3);
}

void	function_pa(t_data *d)
{
	t_list_pile	*tmp;

	if (!d->pile_b)
		return ;
	tmp = d->pile_b;
	d->pile_b = d->pile_b->next;
	ft_lstadd_front(&d->pile_a, tmp);
	write(1, "pa\n", 3);
}

void	function_pb(t_data *d)
{
	t_list_pile	*tmp;

	if (!d->pile_a)
		return ;
	tmp = d->pile_a;
	d->pile_a = d->pile_a->next;
	ft_lstadd_front(&d->pile_b, tmp);
	write(1, "pb\n", 3);
}
