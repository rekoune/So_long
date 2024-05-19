/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:10:08 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/19 11:10:09 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_map	*new_node(char *content)
{
	t_map	*node;

	node = malloc(sizeof(t_map));
	node->line = content;
	node->next = NULL;
	return (node);
}

void	add_back(t_map **head, t_map *new)
{
	t_map	*node;

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

int	list_size(t_map *head)
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

void	free_list(t_map **head)
{
	t_map	*node;

	node = *head;
	while (*head)
	{
		node = (*head)->next;
		free(*head);
		*head = node;
	}
	head = NULL;
}