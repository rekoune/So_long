/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:59:15 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/27 20:47:37 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	eat_coin(t_game *game, int a)
{
	mlx_image_to_window(game->mlx, game->element.ocean.image[0],
		game->element.player.x * 75, game->element.player.y * 75);
	if (a == 0)
		mlx_image_to_window(game->mlx, game->element.player.image[7],
			game->element.player.x * 75, game->element.player.y * 75);
	else
		mlx_image_to_window(game->mlx, game->element.player.image[6],
			game->element.player.x * 75, game->element.player.y * 75);
	game->element.coin.counter--;
}

char	*get_digit(long nb)
{
	char	str[12];
	char	*s;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (nb == 0)
		str[i++] = '0';
	while (nb)
	{
		str[i++] = (nb % 10) + 48;
		nb = nb / 10;
	}
	str[i] = '\0';
	s = malloc(i * sizeof(char));
	i--;
	while (i >= 0)
	{
		s[j] = str[i];
		j++;
		i--;
	}
	s[j] = '\0';
	return (s);
}

void	get_player_pointers(t_game *game)
{
	game->element.player.image = malloc(9 * sizeof(mlx_image_t));
	game->element.player.image[0] = get_image("bonus/textures/player.png",
			game);
	game->element.player.image[1] = get_image("bonus/textures/player_left.png",
			game);
	game->element.player.image[2] = get_image("bonus/textures/walking.png",
			game);
	game->element.player.image[3] = get_image("bonus/textures/left.png", game);
	game->element.player.image[4] = get_image("bonus/textures/up.png", game);
	game->element.player.image[5] = get_image("bonus/textures/up_left.png",
			game);
	game->element.player.image[6] = get_image("bonus/textures/hunt.png", game);
	game->element.player.image[7] = get_image("bonus/textures/left_hunt.png",
			game);
	game->element.player.image[8] = NULL;
}

mlx_image_t	*get_image(char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
	{
		free_resources(game);
		error("Load png fails\n", NULL, game->map.array);
	}
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
	{
		free_resources(game);
		error("Texture to img fails\n", NULL, game->map.array);
	}
	mlx_delete_texture(texture);
	return (img);
}

void	image_to_window(t_game *game, mlx_image_t *img, int j, int i)
{
	mlx_image_to_window(game->mlx, img, j * 75, i * 75);
}
