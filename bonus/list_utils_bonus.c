/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:10:08 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/27 13:15:26 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

t_list	*new_node(char *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->line = content;
	node->next = NULL;
	return (node);
}

void	add_back(t_list **head, t_list *new)
{
	t_list	*node;

	node = *head;
	if (!(*head))
		*head = new;
	else
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
}

int	list_size(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	free_list(t_list **head, char c)
{
	t_list	*node;

	node = *head;
	while (*head)
	{
		node = (*head)->next;
		if (c == 'r')
			free((*head)->line);
		free(*head);
		*head = node;
	}
	head = NULL;
}
