/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:42:51 by tigerber          #+#    #+#             */
/*   Updated: 2021/08/12 16:19:13 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stock_pile_a(int nb, t_data *d)
{
	ft_lstadd_back(&d->pile_a, ft_lstnew(nb));
}

void	ft_parsing(char **argv, t_data *d)
{
	int	i;

	i = 1;
	ft_doublon(argv);
	while (argv[i])
	{
		stock_pile_a(ft_atoi(argv[i]), d);
		i++;
	}
}

void	ft_doublon(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (argv[i])
	{
		while (argv[j])
		{
			if (!ft_strcmp(argv[i], argv[j]))
				ft_error(0, "Error\n");
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_error(int i, char *str)
{
	if (i == 0)
	{
		write(2, str, ft_strlen(str));
		exit(0);
	}
}
