/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:29:30 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/29 12:02:50 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	up_pointers(t_game *game)
{
	game->animation.enemy_up.image = malloc(9 * sizeof(mlx_image_t));
	game->animation.enemy_up.image[0] = 
		get_image("bonus/textures/enemy1.png", game);
	game->animation.enemy_up.image[1] = 
		get_image("bonus/textures/enemy2.png", game);
	game->animation.enemy_up.image[2] = 
		get_image("bonus/textures/enemy3.png", game);
	game->animation.enemy_up.image[3] = 
		get_image("bonus/textures/enemy4.png", game);
	game->animation.enemy_up.image[4] = 
		get_image("bonus/textures/enemy5.png", game);
	game->animation.enemy_up.image[5] = 
		get_image("bonus/textures/enemy6.png", game);
	game->animation.enemy_up.image[6] = 
		get_image("bonus/textures/enemy7.png", game);
	game->animation.enemy_up.image[7] = 
		get_image("bonus/textures/enemy8.png", game);
	game->animation.enemy_up.image[8] = NULL;
}

void	get_enemy_pointers(t_game *game)
{
	up_pointers(game);
	down_pointers(game);
	left_pointers(game);
	game->animation.enemy_right.image = malloc(9 * sizeof(mlx_image_t));
	game->animation.enemy_right.image[0] = 
		get_image("bonus/textures/right1.png", game);
	game->animation.enemy_right.image[1] = 
		get_image("bonus/textures/right2.png", game);
	game->animation.enemy_right.image[2] = 
		get_image("bonus/textures/right3.png", game);
	game->animation.enemy_right.image[3] = 
		get_image("bonus/textures/right4.png", game);
	game->animation.enemy_right.image[4] = 
		get_image("bonus/textures/right5.png", game);
	game->animation.enemy_right.image[5] = 
		get_image("bonus/textures/right6.png", game);
	game->animation.enemy_right.image[6] = 
		get_image("bonus/textures/right7.png", game);
	game->animation.enemy_right.image[7] = 
		get_image("bonus/textures/right8.png", game);
	game->animation.enemy_right.image[8] = NULL;
}

void	get_coin_pointers(t_game *game)
{
	game->animation.coin = malloc(9 * sizeof(mlx_image_t));
	game->animation.coin[0] = get_image("bonus/textures/coin1.png", game);
	game->animation.coin[1] = get_image("bonus/textures/coin2.png", game);
	game->animation.coin[2] = get_image("bonus/textures/coin3.png", game);
	game->animation.coin[3] = get_image("bonus/textures/coin4.png", game);
	game->animation.coin[4] = get_image("bonus/textures/coin5.png", game);
	game->animation.coin[5] = get_image("bonus/textures/coin6.png", game);
	game->animation.coin[6] = get_image("bonus/textures/coin7.png", game);
	game->animation.coin[7] = get_image("bonus/textures/coin8.png", game);
	game->animation.coin[8] = NULL;
}

void	enable(mlx_image_t **image, mlx_image_t *current_img)
{
	int	i;

	i = 0;
	while (i < 8)
		image[i++]->enabled = 0;
	current_img->enabled = 1;
}

void	disable(mlx_image_t **image)
{
	int	i;

	i = 0;
	while (i < 8)
		image[i++]->enabled = 0;
}
