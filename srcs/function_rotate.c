/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:49:06 by tigerber          #+#    #+#             */
/*   Updated: 2021/08/14 18:38:21 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	function_ra(t_data *d)
{
	t_list_pile	*tmp;

	if (!d->pile_a)
		return ;
	tmp = d->pile_a;
	d->pile_a = d->pile_a->next;
	ft_lstadd_back(&d->pile_a, tmp);
	tmp->next = NULL;
	if (!d->on)
		write(1, "ra\n", 3);
}

void	function_rb(t_data *d)
{
	t_list_pile	*tmp;

	if (!d->pile_b)
		return ;
	tmp = d->pile_b;
	d->pile_b = d->pile_b->next;
	ft_lstadd_back(&d->pile_b, tmp);
	tmp->next = NULL;
	if (!d->on)
		write(1, "rb\n", 3);
}

void	function_rr(t_data *d)
{
	if (!d->pile_a || !d->pile_b)
		return ;
	d->on = 1;
	function_ra(d);
	function_rb(d);
	d->on = 0;
	write(1, "rr\n", 3);
}
