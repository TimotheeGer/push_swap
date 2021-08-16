/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:58:06 by tigerber          #+#    #+#             */
/*   Updated: 2021/08/16 14:55:37 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned char	*temp;

	temp = ptr;
	while (len > 0)
	{
		*temp = c;
		temp++;
		len--;
	}
	return (ptr);
}

int	ft_count_lst(t_list_pile *lst)
{
	t_list_pile	*tmp;
	int			i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	pile_a_is_sort(t_data *d)
{
	t_list_pile	*tmp;

	tmp = d->pile_a;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long int	i;
	long int	res;
	long int	sign;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else
			ft_error(0, "Error\n");
		i++;
	}
	if (sign * res > 2147483647 || sign * res < -2147483648)
		ft_error(0, "Error\n");
	return (sign * res);
}
