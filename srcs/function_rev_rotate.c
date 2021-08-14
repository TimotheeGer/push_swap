/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:38:57 by tigerber          #+#    #+#             */
/*   Updated: 2021/08/14 18:38:09 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	function_rra(t_data *d)
{
	t_list_pile	*tmp;
	t_list_pile	*before;

	if (!d->pile_a)
		return ;
	tmp = d->pile_a;
	while (tmp->next != NULL)
	{
		before = tmp;
		tmp = tmp->next;
	}
	before->next = NULL;
	ft_lstadd_front(&d->pile_a, tmp);
	if (!d->on)
		write(1, "rra\n", 4);
}

void	function_rrb(t_data *d)
{
	t_list_pile	*tmp;
	t_list_pile	*before;

	if (!d->pile_b)
		return ;
	tmp = d->pile_b;
	while (tmp->next != NULL)
	{
		before = tmp;
		tmp = tmp->next;
	}
	before->next = NULL;
	ft_lstadd_front(&d->pile_b, tmp);
	if (!d->on)
		write(1, "rrb\n", 4);
}

void	function_rrr(t_data *d)
{
	if (!d->pile_a || !d->pile_b)
		return ;
	d->on = 1;
	function_rra(d);
	function_rrb(d);
	d->on = 0;
	write(1, "rrr\n", 4);
}
