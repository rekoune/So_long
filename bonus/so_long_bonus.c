/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:09:46 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/30 17:01:59 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_pointers(t_game *game)
{
	get_player_pointers(game);
	get_coin_pointers(game);
	get_enemy_pointers(game);
	game->element.coin.image = malloc(2 * sizeof(mlx_image_t));
	game->element.coin.image[0] = get_image("bonus/textures/coins.png", game);
	game->element.coin.image[1] = NULL;
	game->element.ground.image = malloc(2 * sizeof(mlx_image_t));
	game->element.ground.image[0] = get_image("bonus/textures/ground.png",
			game);
	game->element.ground.image[1] = NULL;
	game->element.ocean.image = malloc(2 * sizeof(mlx_image_t));
	game->element.ocean.image[0] = get_image("bonus/textures/ocean.png", game);
	game->element.ocean.image[1] = NULL;
	game->element.exit.image = malloc(3 * sizeof(mlx_image_t));
	game->element.exit.image[0] = get_image("bonus/textures/exit.png", game);
	game->element.exit.image[1] = get_image("bonus/textures/door_open.png",
			game);
	game->element.exit.image[2] = NULL;
}

void	draw_the_map(t_game *game)
{
	int	i;
	int	j;

	get_pointers(game);
	position(game, &game->element.exit.x, &game->element.exit.y, 'E');
	i = -1;
	while (game->map.array[++i])
	{
		j = -1;
		while (game->map.array[i][++j] && game->map.array[i][j] != '\n')
		{
			if (game->map.array[i][j] == '1')
				image_to_window(game, game->element.ground.image[0], j, i);
			else
				image_to_window(game, game->element.ocean.image[0], j, i);
			if (game->map.array[i][j] == 'C')
				print_images(game, game->animation.coin, j, i);
			else if (game->map.array[i][j] == 'A')
				print_images(game, game->animation.enemy_up.image, j, i);
			else if (game->map.array[i][j] == 'E')
				image_to_window(game, game->element.exit.image[0], j, i);
		}
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
	int	i;

	i = 0;
	free_objects(game->element.player, game->mlx);
	free_objects(game->element.ocean, game->mlx);
	free_objects(game->element.ground, game->mlx);
	free_objects(game->element.coin, game->mlx);
	free_objects(game->element.exit, game->mlx);
	free_objects(game->animation.enemy_down, game->mlx);
	free_objects(game->animation.enemy_up, game->mlx);
	free_objects(game->animation.enemy_right, game->mlx);
	free_objects(game->animation.enemy_left, game->mlx);
	while (game->animation.coin && game->animation.coin[i])
		mlx_delete_image(game->mlx, game->animation.coin[i++]);
	free(game->animation.coin);
}

int	main(int ac, char **av)
{
	t_game	game;

	turn_to_null(&game);
	game.animation.timer = 0;
	game.animation.timer_e = 0;
	game.map.array = NULL;
	game.moves = 0;
	if (ac == 2)
	{
		game.map.array = check_map(av[1], &game);
		game.mlx = mlx_init(game.map.n_char * 75, game.map.n_line * 75,
				"so_long_bonus", false);
		if (!game.mlx)
			error("Mlx fails !\n", NULL, game.map.array);
		draw_the_map(&game);
		mlx_key_hook(game.mlx, &my_key_hok, &game);
		mlx_loop_hook(game.mlx, &animation, &game);
		mlx_loop(game.mlx);
		free_2d(game.map.array, 'a');
		free_resources(&game);
	}
}
