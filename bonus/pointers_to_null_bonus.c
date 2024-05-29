/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_to_null_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:04:13 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/29 16:34:59 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	turn_to_null(t_game *game)
{
	game->animation.coin = NULL;
	game->animation.enemy_up.image = NULL;
	game->animation.enemy_down.image = NULL;
	game->animation.enemy_left.image = NULL;
	game->animation.enemy_right.image = NULL;
	game->element.coin.image = NULL;
	game->element.player.image = NULL;
	game->element.exit.image = NULL;
	game->element.ground.image = NULL;
	game->element.ocean.image = NULL;
}

void	check_up_down(t_game *game, int y, int x, char c)
{
	if ((game->map.array[y - 1][x] != '0'
		&& game->map.array[y - 1][x] != 'P') && c == 'u')
	{
		if (game->map.array[y][x + 1] != '0' && 
			game->map.array[y][x + 1] != 'P')
			print_images(game, game->animation.enemy_down.image, x, y);
		else
			print_images(game, game->animation.enemy_right.image, x, y);
	}
	else if ((game->map.array[y + 1][x] != '0'
		&& game->map.array[y + 1][x] != 'P') && c == 'd')
	{
		if (game->map.array[y][x - 1] != '0' && 
			game->map.array[y][x - 1] != 'P')
			print_images(game, game->animation.enemy_up.image, x, y);
		else
			print_images(game, game->animation.enemy_left.image, x, y);
	}
}

void	check_right_left(t_game *game, int y, int x, char c)
{
	if ((game->map.array[y][x + 1] != '0'
		&& game->map.array[y][x + 1] != 'P') && c == 'r')
	{
		if (game->map.array[y + 1][x] != '0' && 
			game->map.array[y + 1][x] != 'P')
			print_images(game, game->animation.enemy_left.image, x, y);
		else
			print_images(game, game->animation.enemy_down.image, x, y);
	}
	else if ((game->map.array[y][x - 1] != '0'
		&& game->map.array[y][x - 1] != 'P') && c == 'l')
	{
		if (game->map.array[y - 1][x] != '0' && 
			game->map.array[y - 1][x] != 'P')
			print_images(game, game->animation.enemy_right.image, x, y);
		else
			print_images(game, game->animation.enemy_up.image, x, y);
	}
}

int	find_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j])
		{
			if (game->map.array[i][j] == 'A')
				game->animation.enemy_down.counter++;
			j++;
		}
		i++;
	}
	return (0);
}
