/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:09:56 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/30 16:27:48 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	elements_calcul(char *str, t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = str_len_c(str, '\n');
	while (str[i] && i < len)
	{
		if (str[i] != 'P' && str[i] != 'C' && str[i] != 'E' && str[i] != '0'
			&& str[i] != '1')
			return (0);
		if (str[i] == 'P')
		{
			game->element.player.counter++;
			game->map.nf = 1;
			game->element.player.x = i;
		}
		else if (str[i] == 'E')
			game->element.exit.counter++;
		else if (str[i] == 'C')
			game->element.coin.counter++;
		i++;
	}
	return (1);
}

void	check_elements(t_list **head, t_game *game)
{
	t_list	*node;
	int		i;
	int		a;

	i = 0;
	node = *head;
	game->map.nf = 0;
	while (node)
	{
		a = elements_calcul(node->line, game);
		if (a == 0)
			break ;
		if (game->map.nf == 1)
		{
			game->element.player.y = i;
			game->map.nf = 0;
		}
		node = node->next;
		i++;
	}
	if (game->element.coin.counter < 1 || game->element.player.counter != 1
		|| game->element.exit.counter != 1 || a == 0)
		error("Invalid map\n", head, NULL);
}

void	get_list_lines(int fd, t_list **head, t_game *game)
{
	t_list	*node;
	int		size;

	game->element.player.counter = 0;
	game->element.exit.counter = 0;
	game->element.coin.counter = 0;
	game->element.player.x = 0;
	game->element.player.y = 0;
	node = new_node(get_next_line(fd));
	size = str_len_c(node->line, '\n');
	game->map.n_char = size;
	while (node->line)
	{
		add_back(head, node);
		node = new_node(get_next_line(fd));
		if (node->line && size != str_len_c(node->line, '\n'))
			error("Invalid map\n", head, NULL);
	}
	game->map.n_line = list_size(*head);
	if (game->map.n_line > 17 || game->map.n_char > 34)
		error("Invalid map\n", head, NULL);
	free(node);
}

void	check_walls(t_list **head)
{
	t_list	*node;
	int		i;

	node = *head;
	i = 0;
	while (node->line[i] && i < str_len_c(node->line, '\n'))
		if (node->line[i++] != '1')
			error("Invalid map\n", head, NULL);
	while (node->next)
	{
		if (node->line[0] != '1' || node->line[str_len_c(node->line, '\n')
				- 1] != '1')
			error("Invalid map\n", head, NULL);
		node = node->next;
	}
	i = 0;
	while (node->line[i] && i < str_len_c(node->line, '\n'))
		if (node->line[i++] != '1')
			error("Invalid map\n", head, NULL);
}

char	**check_map(char *str, t_game *game)
{
	int		fd;
	char	**map;
	char	**map_copy;
	t_list	*head;

	head = NULL;
	if (compare(str + (str_len_c(str, '\0') - 4), ".ber") != 0)
		error("Map file format not corect\n", NULL, NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		error("Map file not exist\n", NULL, NULL);
	get_list_lines(fd, &head, game);
	check_elements(&head, game);
	check_walls(&head);
	map = switch_to_array(&head);
	map_copy = copying_map(head);
	flood_fill(map_copy, game->element.player.x, game->element.player.y,
		list_size(head));
	check_path(map_copy, map);
	free_2d(map_copy, 'a');
	free_list(&head, 'n');
	return (map);
}
