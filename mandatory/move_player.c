/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:19:22 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/27 16:23:35 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game, int a)
{
	char	*str;

	if (game->map.array[game->element.player.y][game->element.player.x] != 'E')
	{
		player_image_to_window(game, game->element.ocean.image[0]);
		player_image_to_window(game, game->element.player.image[4]);
	}
	if (game->map.array[game->element.player.y
			- 1][game->element.player.x] == '1')
		return ;
	player_image_to_window(game, game->element.ocean.image[0]);
	if (game->map.array[game->element.player.y][game->element.player.x] == 'E')
		player_image_to_window(game, game->element.exit.image[0]);
	game->element.player.y--;
	if (a == 0)
		player_image_to_window(game, game->element.player.image[5]);
	else
		player_image_to_window(game, game->element.player.image[4]);
	game->moves++;
	str = get_digit(game->moves);
	ft_write("moves = ", 1);
	ft_write(str, 1);
	ft_write("\n", 1);
	free(str);
}

void	move_down(t_game *game, int a)
{
	char	*str;

	if (game->map.array[game->element.player.y][game->element.player.x] != 'E')
	{
		player_image_to_window(game, game->element.ocean.image[0]);
		player_image_to_window(game, game->element.player.image[0]);
	}
	if (game->map.array[game->element.player.y
			+ 1][game->element.player.x] == '1')
		return ;
	player_image_to_window(game, game->element.ocean.image[0]);
	if (game->map.array[game->element.player.y][game->element.player.x] == 'E')
		player_image_to_window(game, game->element.exit.image[0]);
	game->element.player.y++;
	if (a == 0)
		player_image_to_window(game, game->element.player.image[1]);
	else
		player_image_to_window(game, game->element.player.image[0]);
	str = get_digit(++game->moves);
	ft_write("moves = ", 1);
	ft_write(str, 1);
	ft_write("\n", 1);
	free(str);
}

void	move_right(t_game *game, int a)
{
	char	*str;

	if (game->map.array[game->element.player.y][game->element.player.x] != 'E')
	{
		player_image_to_window(game, game->element.ocean.image[0]);
		player_image_to_window(game, game->element.player.image[2]);
	}
	if (game->map.array[game->element.player.y][game->element.player.x
		+ 1] == '1')
		return ;
	player_image_to_window(game, game->element.ocean.image[0]);
	if (game->map.array[game->element.player.y][game->element.player.x] == 'E')
		player_image_to_window(game, game->element.exit.image[0]);
	game->element.player.x++;
	player_image_to_window(game, game->element.player.image[2]);
	game->moves++;
	str = get_digit(game->moves);
	ft_write("moves = ", 1);
	ft_write(str, 1);
	ft_write("\n", 1);
	free(str);
	(void)a;
}

void	move_lift(t_game *game, int a)
{
	char	*str;

	if (game->map.array[game->element.player.y][game->element.player.x] != 'E')
	{
		player_image_to_window(game, game->element.ocean.image[0]);
		player_image_to_window(game, game->element.player.image[3]);
	}
	if (game->map.array[game->element.player.y][game->element.player.x
		- 1] == '1')
		return ;
	player_image_to_window(game, game->element.ocean.image[0]);
	if (game->map.array[game->element.player.y][game->element.player.x] == 'E')
		player_image_to_window(game, game->element.exit.image[0]);
	game->element.player.x--;
	player_image_to_window(game, game->element.player.image[3]);
	game->moves++;
	str = get_digit(game->moves);
	ft_write("moves = ", 1);
	ft_write(str, 1);
	ft_write("\n", 1);
	free(str);
	(void)a;
}

void	move_player(t_game *game, char c, int a)
{
	if (game->map.array[game->element.player.y][game->element.player.x] != 'E')
		game->map.array[game->element.player.y][game->element.player.x] = '0';
	if (c == 'W')
		move_up(game, a);
	else if (c == 'A')
		move_lift(game, a);
	else if (c == 'S')
		move_down(game, a);
	else if (c == 'D')
		move_right(game, a);
	if (game->map.array[game->element.player.y][game->element.player.x] == 'C')
		eat_coin(game, a);
	if (game->element.coin.counter == 0)
		mlx_image_to_window(game->mlx, game->element.exit.image[1],
			game->element.exit.x * 75, game->element.exit.y * 75);
	if (game->element.coin.counter == 0
		&& game->map.array[game->element.player.y]
		[game->element.player.x] == 'E')
	{
		free_resources(game);
		free_2d(game->map.array, 'e');
	}
	if (game->map.array[game->element.player.y][game->element.player.x] != 'E')
		game->map.array[game->element.player.y][game->element.player.x] = 'P';
}
