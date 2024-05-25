/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:09:46 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/25 12:19:56 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*get_image(char *path, void *mlx, char **map)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		error("Load png fails\n", NULL, map);
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error("Texture to img fails\n", NULL, map);
	mlx_delete_texture(texture);
	return (img);
}

void	get_pointers(t_num *num)
{
	num->coins = get_image("textures/coins.png", num->mlx, num->map);
	num->ocean = get_image("textures/ocean.png", num->mlx, num->map);
	num->ground = get_image("textures/ground.png", num->mlx, num->map);
	num->player = get_image("textures/player.png", num->mlx, num->map);
	num->player_left = get_image("textures/player_left.png", num->mlx, num->map);
	num->walk = get_image("textures/walking.png", num->mlx, num->map);
	num->left = get_image("textures/left.png", num->mlx, num->map);
	num->hunt = get_image("textures/hunt.png", num->mlx, num->map);
	num->left_hunt = get_image("textures/left_hunt.png", num->mlx, num->map);
	num->up = get_image("textures/up.png", num->mlx, num->map);
	num->up_left = get_image("textures/up_left.png", num->mlx, num->map);
	num->door_open = get_image("textures/door_open.png", num->mlx, num->map);
	num->exit = get_image("textures/exit.png", num->mlx, num->map);
}

void	draw_the_map(char **map, void *mlx, t_num *num)
{
	int	i;
	int	j;

	get_pointers(num);
	position(num);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == '1')
				mlx_image_to_window(mlx, num->ground, j * 75, i * 75);
			else
				mlx_image_to_window(mlx, num->ocean, j * 75, i * 75);
			if (map[i][j] == 'C')
				mlx_image_to_window(num->mlx, num->coins, j * 75, i * 75);
			else if (map[i][j] == 'E')
				mlx_image_to_window(num->mlx, num->exit, j * 75, i * 75);
			j++;
		}
		i++;
	}
	mlx_image_to_window(mlx, num->player, num->p_x * 75, num->p_y * 75);
}

void	my_key_hok(mlx_key_data_t data, void *param)
{
	t_num		*num;
	static int	a;

	num = (t_num *)param;
	if ((data.key == MLX_KEY_W || data.key == MLX_KEY_UP) && data.action)
		move_player(num, 'W', a);
	else if ((data.key == MLX_KEY_A || data.key == MLX_KEY_LEFT) && data.action)
	{
		a = 0;
		move_player(num, 'A', a);
	}
	else if ((data.key == MLX_KEY_S || data.key == MLX_KEY_DOWN) && data.action)
		move_player(num, 'S', a);
	else if ((data.key == MLX_KEY_D || data.key == MLX_KEY_RIGHT)
		&& data.action)
	{
		a = 1;
		move_player(num, 'D', a);
	}
	else if (data.key == MLX_KEY_ESCAPE && data.action)
	{
		free_2d(num->map);
		exit(0);
	}
}

void	leaks(void)
{
	system("leaks so_long -q");
}

int	main(int ac, char **av)
{
	t_num	num;
	void	*mlx;
	char	**map;

	atexit(leaks);
	map = NULL;
	num.moves = 0;
	if (ac == 2)
	{
		map = check_map(av[1], &num);
		num.map = map;
		mlx = mlx_init(num.n_char * 75, num.n_line * 75, "so_long", false);
		if (!mlx)
			error("Mlx fails !\n", NULL, map);
		num.mlx = mlx;
		draw_the_map(map, mlx, &num);
		mlx_key_hook(mlx, &my_key_hok, &num);
		mlx_loop(mlx);
		free_2d(map);
	}
}
