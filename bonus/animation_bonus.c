/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:36:54 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/29 16:30:57 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_images(t_game *game, mlx_image_t **img, int x, int y)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		image_to_window(game, img[i], x, y);
		i++;
	}
}

void	coin_animation(t_game *game)
{
	if (game->animation.timer == 10)
		enable(game->animation.coin, game->animation.coin[0]);
	else if (game->animation.timer == 20)
		enable(game->animation.coin, game->animation.coin[1]);
	else if (game->animation.timer == 30)
		enable(game->animation.coin, game->animation.coin[2]);
	else if (game->animation.timer == 40)
		enable(game->animation.coin, game->animation.coin[3]);
	else if (game->animation.timer == 50)
		enable(game->animation.coin, game->animation.coin[4]);
	else if (game->animation.timer == 60)
		enable(game->animation.coin, game->animation.coin[5]);
	else if (game->animation.timer == 70)
		enable(game->animation.coin, game->animation.coin[6]);
	else if (game->animation.timer == 80)
		enable(game->animation.coin, game->animation.coin[7]);
	game->animation.timer++;
	if (game->animation.timer == 81)
		game->animation.timer = 0;
}

void	enemy_animation(t_game *game, mlx_image_t **img)
{
	if (game->animation.timer_e == 6)
		enable(img, img[0]);
	else if (game->animation.timer_e == 20)
		enable(img, img[1]);
	else if (game->animation.timer_e == 30)
		enable(img, img[2]);
	else if (game->animation.timer_e == 40)
		enable(img, img[3]);
	else if (game->animation.timer_e == 50)
		enable(img, img[4]);
	else if (game->animation.timer_e == 60)
		enable(img, img[5]);
	else if (game->animation.timer_e == 70)
		enable(img, img[6]);
	else if (game->animation.timer_e == 80)
		enable(img, img[7]);
	game->animation.timer_e++;
	if (game->animation.timer_e == 81)
		game->animation.timer_e = 0;
}

void	update_enemy(t_game *game, char c, int y, int x)
{
	image_to_window(game, game->element.ocean.image[0], x, y);
	game->map.array[y][x] = '0';
	if (c == 'u')
		y = --game->animation.enemy_up.y;
	else if (c == 'd')
		y = ++game->animation.enemy_down.y;
	else if (c == 'r')
		x = ++game->animation.enemy_right.x;
	else if (c == 'l')
		x = --game->animation.enemy_left.x;
	if (game->map.array[y][x] == 'P')
	{
		free_resources(game);
		free_2d(game->map.array, 'e');
	}
	game->map.array[y][x] = 'A';
	check_up_down(game, y, x, c);
	check_right_left(game, y, x, c);
}

void	animation(void *param)
{
	t_game	*game;

	game = param;
	game->animation.enemy_down.counter = 0;
	coin_animation(game);
	find_enemy(game);
	if (game->animation.enemy_down.counter == 1)
		enemy_moves(game);
	else if (game->animation.enemy_down.counter > 1)
	{
		free_resources(game);
		error("Invalid map !\n", NULL, game->map.array);
	}
}
