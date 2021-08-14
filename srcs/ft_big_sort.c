/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:25:30 by tigerber          #+#    #+#             */
/*   Updated: 2021/08/14 18:25:02 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_big_sort(t_data *d)
{
	if (ft_count_lst(d->pile_a) == 100)
		ft_sort_one_hundred(d);
	if (ft_count_lst(d->pile_a) == 500)
		ft_sort_five_hundred(d);
	else if (ft_count_lst(d->pile_a) != 100 && ft_count_lst(d->pile_a) != 500)
        ft_sort_other(d);
}

void	ft_sort_one_hundred(t_data *d)
{
	int partition;
	int size_partition;

	partition = 5;
	while (partition)
	{
		ft_sort_tab_one_hundred(d, d->pile_a);
		size_partition = 20;
		while (size_partition)
		{
			check_pos(d);
			compare(d);
			size_partition--;
		}
		partition--;
	}
	while (ft_count_lst(d->pile_b))
	{
		ft_sort_tab_one_hundred(d, d->pile_b);
		check_max(d);
		compare_max(d);
	}
}

void	ft_sort_five_hundred(t_data *d)
{
	int partition;
	int size_partition;

	partition = 10;
	while (partition)
	{
		ft_sort_tab_five_hundred(d, d->pile_a);
		size_partition = 50;
		while (size_partition)
		{
			check_pos(d);
			compare(d);
			size_partition--;
		}
		partition--;
	}
	while (ft_count_lst(d->pile_b))
	{
		ft_sort_tab_five_hundred(d, d->pile_b);
		check_max(d);
		compare_max(d);
	}
}

void	ft_sort_other(t_data *d)
{
	int count;

	count = 0;
	while (ft_count_lst(d->pile_a))
	{
		ft_sort_tab_other(d, d->pile_a);
		while (count < ft_count_lst(d->pile_a) - 1)
		{
			check_middle(d);
			compare(d);
			count++;
		}
		count = 0;
		if (ft_count_lst(d->pile_a) == 2)
		{
            if (d->pile_a->nb > d->pile_a->next->nb)
				function_sa(d);
            break;
		}
	}
    while (ft_count_lst(d->pile_b))
	{
		ft_sort_tab_other(d, d->pile_b);
		check_max(d);
		compare_max(d);
	}
}
