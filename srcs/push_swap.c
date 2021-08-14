/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:29:41 by tigerber          #+#    #+#             */
/*   Updated: 2021/08/14 18:39:23 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	d;

	ft_memset(&d, 0, sizeof(t_data));
	if (argc < 3)
		return (0);
	ft_parsing(argv, &d);
	if (pile_a_is_sort(&d))
		return (0);
    if (ft_count_lst(d.pile_a) > 1 && ft_count_lst(d.pile_a) < 5)
        ft_small_sort(&d);
    if (ft_count_lst(d.pile_a) >= 5)
        ft_big_sort(&d);
	ft_lstclear(&d.pile_a);
	ft_lstclear(&d.pile_b);
	return (0);
}