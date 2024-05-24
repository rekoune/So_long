/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:09:46 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/24 20:20:58 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*get_image(char *path, void *mlx)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		error("Load png fails\n");
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error("Texture to img fails\n");
	mlx_delete_texture(texture);
	return (img);
}

void	get_pointers(t_num *num)
{
	num->coins = get_image("img/coins.png", num->mlx);
	num->ocean = get_image("img/ocean.png", num->mlx);
	num->ground = get_image("img/ground.png", num->mlx);
	num->player = get_image("img/player.png", num->mlx);
	num->player_left = get_image("img/player_left.png", num->mlx);
	num->walk = get_image("img/walking.png", num->mlx);
	num->left = get_image("img/left.png", num->mlx);
	num->hunt = get_image("img/hunt.png", num->mlx);
	num->left_hunt = get_image("img/left_hunt.png", num->mlx);
	num->up = get_image("img/up.png", num->mlx);
	num->up_left = get_image("img/up_left.png", num->mlx);
	num->door_open = get_image("img/door_open.png", num->mlx);
	num->exit = get_image("img/exit.png", num->mlx);
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
	t_num		*map;
	static int	a;

	map = (t_num *)param;
	if ((data.key == MLX_KEY_W || data.key == MLX_KEY_UP) && data.action)
		move_player(map, 'W', a);
	else if ((data.key == MLX_KEY_A || data.key == MLX_KEY_LEFT) && data.action)
	{
		a = 0;
		move_player(map, 'A', a);
	}
	else if ((data.key == MLX_KEY_S || data.key == MLX_KEY_DOWN) && data.action)
		move_player(map, 'S', a);
	else if ((data.key == MLX_KEY_D || data.key == MLX_KEY_RIGHT)
		&& data.action)
	{
		a = 1;
		move_player(map, 'D', a);
	}
	else if (data.key == MLX_KEY_ESCAPE && data.action)
		exit(0);
}

int	main(int ac, char **av)
{
	t_num	num;
	void	*mlx;
	char	**map;

	map = NULL;
	num.moves = 0;
	if (ac == 2)
	{
		map = check_map(av[1], &num);
		num.map = map;
		mlx = mlx_init(num.n_char * 75, num.n_line * 75, "so_long", false);
		if (!mlx)
			error("Mlx fails !\n");
		num.mlx = mlx;
		draw_the_map(map, mlx, &num);
		mlx_key_hook(mlx, &my_key_hok, &num);
		mlx_loop(mlx);
	}
}
