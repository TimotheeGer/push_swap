/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:49:27 by tigerber          #+#    #+#             */
/*   Updated: 2021/08/16 14:57:41 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstadd_back(t_list_pile **alst, t_list_pile *new)
{
	t_list_pile	*end_list;

	if (!alst || !new)
		return ;
	if (*alst)
	{
		end_list = *alst;
		while (end_list->next != NULL)
			end_list = end_list->next;
		end_list->next = new;
	}
	else
		*alst = new;
}

t_list_pile	*ft_lstnew(int content)
{
	t_list_pile	*new_list;

	new_list = malloc(sizeof(t_list_pile));
	if (!(new_list))
		return (NULL);
	new_list->nb = content;
	new_list->next = NULL;
	return (new_list);
}

void	ft_lstclear(t_list_pile **lst)
{
	t_list_pile	*tmp;
	t_list_pile	*temp;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		temp = tmp->next;
		free(tmp);
		tmp = temp;
	}
	*lst = NULL;
}

void	ft_lstadd_front(t_list_pile **alst, t_list_pile *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

void	ft_rev_lst(t_list_pile **head_ref)
{
	t_list_pile	*prev;
	t_list_pile	*current;
	t_list_pile	*next;

	prev = NULL;
	current = *head_ref;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}
