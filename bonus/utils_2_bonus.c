/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:32:40 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/27 15:21:44 by arekoune         ###   ########.fr       */
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
