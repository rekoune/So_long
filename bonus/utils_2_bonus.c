/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:32:40 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/29 11:18:02 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_objects(t_object object, mlx_t *mlx)
{
	int	i;

	i = 0;
	while (object.image && object.image[i])
		mlx_delete_image(mlx, object.image[i++]);
	free(object.image);
}

void	player_image_to_window(t_game *game, mlx_image_t *img)
{
	mlx_image_to_window(game->mlx, img, game->element.player.x * 75,
		game->element.player.y * 75);
}

void	down_pointers(t_game *game)
{
	game->animation.enemy_down.image = NULL;
	game->animation.enemy_down.image = malloc(9 * sizeof(mlx_image_t));
	game->animation.enemy_down.image[0] = 
		get_image("bonus/textures/down_1.png", game);
	game->animation.enemy_down.image[1] = 
		get_image("bonus/textures/down_2.png", game);
	game->animation.enemy_down.image[2] = 
		get_image("bonus/textures/down_3.png", game);
	game->animation.enemy_down.image[3] = 
		get_image("bonus/textures/down_4.png", game);
	game->animation.enemy_down.image[4] = 
		get_image("bonus/textures/down_5.png", game);
	game->animation.enemy_down.image[5] = 
		get_image("bonus/textures/down_6.png", game);
	game->animation.enemy_down.image[6] = 
		get_image("bonus/textures/down_7.png", game);
	game->animation.enemy_down.image[7] = 
		get_image("bonus/textures/down_8.png", game);
	game->animation.enemy_down.image[8] = NULL;
}

void	left_pointers(t_game *game)
{
	game->animation.enemy_left.image = NULL;
	game->animation.enemy_left.image = malloc(9 * sizeof(mlx_image_t));
	game->animation.enemy_left.image[0] = 
		get_image("bonus/textures/left_1.png", game);
	game->animation.enemy_left.image[1] = 
		get_image("bonus/textures/left_2.png", game);
	game->animation.enemy_left.image[2] = 
		get_image("bonus/textures/left_3.png", game);
	game->animation.enemy_left.image[3] = 
		get_image("bonus/textures/left_4.png", game);
	game->animation.enemy_left.image[4] = 
		get_image("bonus/textures/left_5.png", game);
	game->animation.enemy_left.image[5] = 
		get_image("bonus/textures/left_6.png", game);
	game->animation.enemy_left.image[6] = 
		get_image("bonus/textures/left_7.png", game);
	game->animation.enemy_left.image[7] = 
		get_image("bonus/textures/left_8.png", game);
	game->animation.enemy_left.image[8] = NULL;
}

void	player_direction(t_game *game, char c, int a)
{
	if (c == 'W')
		move_up(game, a);
	else if (c == 'A')
		move_left(game, a);
	else if (c == 'S')
		move_down(game, a);
	else if (c == 'D')
		move_right(game, a);
}
