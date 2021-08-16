/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:40:45 by tigerber          #+#    #+#             */
/*   Updated: 2021/08/16 15:12:11 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size - 1)
	{
		i++;
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
			}
			j++;
		}
	}
}

void	ft_sort_tab_one_hundred(t_data *d, t_list_pile *lst)
{
	t_list_pile	*tmp;
	int			j;
	int			*tab;

	tmp = lst;
	j = 0;
	tab = malloc(sizeof(int) * ft_count_lst(lst));
	if (tab == NULL)
		return ;
	if (!lst)
		return ;
	while (tmp)
	{
		tab[j] = tmp->nb;
		tmp = tmp->next;
		j++;
	}
	ft_sort_int_tab(tab, ft_count_lst(lst));
	if (ft_count_lst(lst) > 19)
		d->number = tab[19];
	d->nb_max = tab[ft_count_lst(lst) - 1];
	free(tab);
}

void	ft_sort_tab_five_hundred(t_data *d, t_list_pile *lst)
{
	t_list_pile	*tmp;
	int			j;
	int			*tab;

	tmp = lst;
	j = 0;
	tab = malloc(sizeof(int) * ft_count_lst(lst));
	if (tab == NULL)
		return ;
	if (!lst)
		return ;
	while (tmp)
	{
		tab[j] = tmp->nb;
		tmp = tmp->next;
		j++;
	}
	ft_sort_int_tab(tab, ft_count_lst(lst));
	if (ft_count_lst(lst) > 49)
		d->number = tab[49];
	d->nb_max = tab[ft_count_lst(lst) - 1];
	free(tab);
}

void	ft_sort_tab_other(t_data *d, t_list_pile *lst)
{
	t_list_pile	*tmp;
	int			j;
	int			*tab;

	tmp = lst;
	j = 0;
	tab = malloc(sizeof(int) * ft_count_lst(lst));
	if (tab == NULL)
		exit (0);
	if (!lst)
		return ;
	while (tmp)
	{
		tab[j] = tmp->nb;
		tmp = tmp->next;
		j++;
	}
	ft_sort_int_tab(tab, ft_count_lst(lst));
	d->middle = tab[ft_count_lst(lst) / 2];
	d->nb_max = tab[ft_count_lst(lst) - 1];
	free(tab);
}
