/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:21:37 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/28 20:22:39 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	go_up(t_game *game, int *direction)
{
	disable(game->animation.enemy_left.image);
	enemy_animation(game, game->animation.enemy_up.image);
	if (game->animation.timer_e == 80
		&& game->map.array[game->animation.enemy_up.y
			- 1][game->animation.enemy_up.x] != '1'
		&& game->map.array[game->animation.enemy_up.y
			- 1][game->animation.enemy_up.x] != 'C')
	{
		update_enemy(game, 'u', game->animation.enemy_up.y,
			game->animation.enemy_up.x);
		print_images(game, game->animation.enemy_up.image,
			game->animation.enemy_up.x, game->animation.enemy_up.y);
	}
	else if (game->map.array[game->animation.enemy_up.y
			- 1][game->animation.enemy_up.x] != '0'
		&& game->map.array[game->animation.enemy_up.y
			- 1][game->animation.enemy_up.x] != 'P')
		*direction = 1;
}

void	go_down(t_game *game, int *direction)
{
	position(game, &game->animation.enemy_down.x, &game->animation.enemy_down.y,
		'A');
	disable(game->animation.enemy_right.image);
	enemy_animation(game, game->animation.enemy_down.image);
	if (game->animation.timer_e == 80
		&& game->map.array[game->animation.enemy_up.y
			+ 1][game->animation.enemy_up.x] != '1'
		&& game->map.array[game->animation.enemy_up.y
			+ 1][game->animation.enemy_up.x] != 'C')
	{
		update_enemy(game, 'd', game->animation.enemy_down.y,
			game->animation.enemy_down.x);
		print_images(game, game->animation.enemy_down.image,
			game->animation.enemy_down.x, game->animation.enemy_down.y);
	}
	else if (game->map.array[game->animation.enemy_up.y
			+ 1][game->animation.enemy_up.x] != '0'
		&& game->map.array[game->animation.enemy_up.y
			+ 1][game->animation.enemy_up.x] != 'P')
		*direction = 3;
}

void	go_right(t_game *game, int *direction)
{
	position(game, &game->animation.enemy_right.x,
		&game->animation.enemy_right.y, 'A');
	disable(game->animation.enemy_up.image);
	enemy_animation(game, game->animation.enemy_right.image);
	if (game->animation.timer == 80
		&& game->map.array[game->animation.enemy_right.y][game->animation.enemy_right.x
			+ 1] != '1'
		&& game->map.array[game->animation.enemy_right.y][game->animation.enemy_right.x
			+ 1] != 'C')
	{
		update_enemy(game, 'r', game->animation.enemy_right.y,
			game->animation.enemy_right.x);
		print_images(game, game->animation.enemy_right.image,
			game->animation.enemy_right.x, game->animation.enemy_right.y);
	}
	else if (game->map.array[game->animation.enemy_right.y][game->animation.enemy_right.x
			+ 1] != '0'
		&& game->map.array[game->animation.enemy_right.y][game->animation.enemy_right.x
			+ 1] != 'P')
		*direction = 2;
}

void	go_left(t_game *game, int *direction)
{
	position(game, &game->animation.enemy_left.x, &game->animation.enemy_left.y,
		'A');
	disable(game->animation.enemy_down.image);
	enemy_animation(game, game->animation.enemy_left.image);
	if (game->animation.timer == 80
		&& game->map.array[game->animation.enemy_left.y][game->animation.enemy_left.x
			- 1] != '1'
		&& game->map.array[game->animation.enemy_left.y][game->animation.enemy_left.x
			- 1] != 'C')
	{
		update_enemy(game, 'l', game->animation.enemy_left.y,
			game->animation.enemy_left.x);
		print_images(game, game->animation.enemy_left.image,
			game->animation.enemy_left.x, game->animation.enemy_left.y);
	}
	else if (game->map.array[game->animation.enemy_left.y][game->animation.enemy_left.x
			- 1] != '0'
		&& game->map.array[game->animation.enemy_left.y][game->animation.enemy_left.x
			- 1] != 'P')
		*direction = 0;
}

void	enemy_moves(t_game *game)
{
	static int direction;

	position(game, &game->animation.enemy_up.x, &game->animation.enemy_up.y,
		'A');
	if (direction == 0)
		go_up(game, &direction);
	else if (direction == 1)
		go_right(game, &direction);
	else if (direction == 2)
		go_down(game, &direction);
	else if (direction == 3)
		go_left(game, &direction);
}