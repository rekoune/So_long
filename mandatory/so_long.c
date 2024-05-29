/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:09:46 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/29 17:00:50 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_pointers(t_game *game)
{
	get_player_pointers(game);
	game->element.coin.image = malloc(2 * sizeof(mlx_image_t));
	game->element.coin.image[0] = 
		get_image("mandatory/textures/coins.png", game);
	game->element.coin.image[1] = NULL;
	game->element.ground.image = malloc(2 * sizeof(mlx_image_t));
	game->element.ground.image[0] = 
		get_image("mandatory/textures/ground.png", game);
	game->element.ground.image[1] = NULL;
	game->element.ocean.image = malloc(2 * sizeof(mlx_image_t));
	game->element.ocean.image[0] = 
		get_image("mandatory/textures/ocean.png", game);
	game->element.ocean.image[1] = NULL;
	game->element.exit.image = malloc(3 * sizeof(mlx_image_t));
	game->element.exit.image[0] = 
		get_image("mandatory/textures/exit.png", game);
	game->element.exit.image[1] = 
		get_image("mandatory/textures/door_open.png", game);
	game->element.exit.image[2] = NULL;
}

void	draw_the_map(t_game *game)
{
	int	i;
	int	j;

	get_pointers(game);
	position(game);
	i = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j] && game->map.array[i][j] != '\n')
		{
			if (game->map.array[i][j] == '1')
				image_to_window(game, game->element.ground.image[0], j, i);
			else
				image_to_window(game, game->element.ocean.image[0], j, i);
			if (game->map.array[i][j] == 'C')
				image_to_window(game, game->element.coin.image[0], j, i);
			else if (game->map.array[i][j] == 'E')
				image_to_window(game, game->element.exit.image[0], j, i);
			j++;
		}
		i++;
	}
	player_image_to_window(game, game->element.player.image[0]);
}

void	my_key_hok(mlx_key_data_t data, void *param)
{
	t_game		*game;
	static int	a;

	game = (t_game *)param;
	if ((data.key == MLX_KEY_W || data.key == MLX_KEY_UP) && data.action)
		move_player(game, 'W', a);
	else if ((data.key == MLX_KEY_A || data.key == MLX_KEY_LEFT) && data.action)
	{
		a = 0;
		move_player(game, 'A', a);
	}
	else if ((data.key == MLX_KEY_S || data.key == MLX_KEY_DOWN) && data.action)
		move_player(game, 'S', a);
	else if ((data.key == MLX_KEY_D || data.key == MLX_KEY_RIGHT)
		&& data.action)
	{
		a = 1;
		move_player(game, 'D', a);
	}
	else if (data.key == MLX_KEY_ESCAPE && data.action)
	{
		free_resources(game);
		free_2d(game->map.array, 'e');
	}
}

void	free_resources(t_game *game)
{
	free_objects(game->element.player, game->mlx);
	free_objects(game->element.ocean, game->mlx);
	free_objects(game->element.ground, game->mlx);
	free_objects(game->element.coin, game->mlx);
	free_objects(game->element.exit, game->mlx);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.map.array = NULL;
	game.element.player.image = NULL;
	game.element.ocean.image = NULL;
	game.element.ground.image = NULL;
	game.element.coin.image = NULL;
	game.element.exit.image = NULL;
	game.moves = 0;
	if (ac == 2)
	{
		game.map.array = check_map(av[1], &game);
		game.mlx = mlx_init(game.map.n_char * 75, game.map.n_line * 75,
				"so_long", false);
		if (!game.mlx)
			error("Mlx fails !\n", NULL, game.map.array);
		draw_the_map(&game);
		mlx_key_hook(game.mlx, &my_key_hok, &game);
		mlx_loop(game.mlx);
		free_2d(game.map.array, 'a');
		free_resources(&game);
	}
}
