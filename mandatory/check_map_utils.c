/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:09:52 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/27 09:28:56 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**switch_to_array(t_list **head)
{
	char	**array;
	t_list	*node;
	int		i;

	i = 0;
	node = *head;
	array = malloc((list_size(*head) + 1) * sizeof(char *));
	while (node)
	{
		array[i++] = node->line;
		node = node->next;
	}
	array[i] = NULL;
	return (array);
}

char	**copying_map(t_list *head)
{
	int		i;
	char	**cpy;

	i = list_size(head);
	cpy = malloc((i + 1) * sizeof(char **));
	i = 0;
	while (head)
	{
		cpy[i++] = sub_str(head->line, str_len_c(head->line, '\0'));
		head = head->next;
	}
	cpy[i] = NULL;
	return (cpy);
}

void	flood_fill(char **map, int x, int y, int size)
{
	if (x < 0 || x > str_len_c(map[y], '\0') || y > size || y < 0
		|| map[y][x] == '1')
		return ;
	map[y][x] = '1';
	flood_fill(map, x - 1, y, size);
	flood_fill(map, x + 1, y, size);
	flood_fill(map, x, y - 1, size);
	flood_fill(map, x, y + 1, size);
}

void	check_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && j < str_len_c(map[i], '\n'))
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				error("Invalid map\n", NULL, map);
			j++;
		}
		i++;
	}
}

void	position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j] && game->map.array[i][j] != '\n')
		{
			if (game->map.array[i][j] == 'E')
			{
				game->element.exit.x = j;
				game->element.exit.y = i;
			}
			j++;
		}
		i++;
	}
}
