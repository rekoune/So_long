/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:09:46 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/25 20:42:24 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_image_t	*get_image(char *path, mlx_t *mlx, char **map)
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
	num->coins = get_image("textures_bonus/coins.png", num->mlx, num->map);
	num->ocean = get_image("textures_bonus/ocean.png", num->mlx, num->map);
	num->ground = get_image("textures_bonus/ground.png", num->mlx, num->map);
	num->player = get_image("textures_bonus/player.png", num->mlx, num->map);
	num->player_left = get_image("textures_bonus/player_left.png", num->mlx,
			num->map);
	num->walk = get_image("textures_bonus/walking.png", num->mlx, num->map);
	num->left = get_image("textures_bonus/left.png", num->mlx, num->map);
	num->hunt = get_image("textures_bonus/hunt.png", num->mlx, num->map);
	num->left_hunt = get_image("textures_bonus/left_hunt.png", num->mlx,
			num->map);
	num->up = get_image("textures_bonus/up.png", num->mlx, num->map);
	num->up_left = get_image("textures_bonus/up_left.png", num->mlx, num->map);
	num->door_open = get_image("textures_bonus/door_open.png", num->mlx,
			num->map);
	num->exit = get_image("textures_bonus/exit.png", num->mlx, num->map);


	num->anime1 = get_image("textures_bonus/anime1.png", num->mlx, num->map);
	num->anime2 = get_image("textures_bonus/anime2.png", num->mlx, num->map);
	num->anime3 = get_image("textures_bonus/anime3.png", num->mlx, num->map);
	num->anime4 = get_image("textures_bonus/anime4.png", num->mlx, num->map);
	num->anime5 = get_image("textures_bonus/anime5.png", num->mlx, num->map);
	num->anime6 = get_image("textures_bonus/anime6.png", num->mlx, num->map);
	num->anime7 = get_image("textures_bonus/anime7.png", num->mlx, num->map);
	num->anime8 = get_image("textures_bonus/anime8.png", num->mlx, num->map);

	
	num->enemy0 = get_image("textures_bonus/enemy0.png", num->mlx, num->map);
	num->enemy1 = get_image("textures_bonus/enemy1.png", num->mlx, num->map);

}

void	draw_the_map(char **map, mlx_t *mlx, t_num *num)
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
			// if (map[i][j] == 'C')
			// 	mlx_image_to_window(num->mlx, num->coins, j * 75, i * 75);
			 if (map[i][j] == 'E')
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

mlx_image_t	*get_coins_anime(t_num *num)
{
	mlx_image_t *img;
	
	img = num->anime1;
	if (num->hona == 10)
		img = num->anime1;
	if (num->hona == 20)
		img = num->anime2;
	if (num->hona == 30)
		img = num->anime3;
	if (num->hona == 40)
		img = num->anime4;
	if (num->hona == 50)
		img = num->anime5;
	if (num->hona == 60)
		img = num->anime6;
	if (num->hona == 70)
		img = num->anime7;
	if (num->hona == 80)
		img = num->anime8;
	return(img);
}
mlx_image_t	*get_enemy_anime(t_num *num)
{
	mlx_image_t *img;
	
	img = num->enemy0;
	if (num->hona == 10)
		img = num->enemy0;
	if (num->hona == 20)
		img = num->enemy1;
	if (num->hona == 30)
		img = num->enemy0;
	if (num->hona == 40)
		img = num->enemy1;
	if (num->hona == 50)
		img = num->enemy0;
	if (num->hona == 60)
		img = num->enemy1;
	if (num->hona == 70)
		img = num->enemy0;
	if (num->hona == 80)
		img = num->enemy1;
	return(img);
}

void	print_anime(t_num *num, int i, int j, char c)
{
	mlx_image_t *img;
	
	if (c == 'C')
		img = get_coins_anime(num);
	else
		img = get_enemy_anime(num);
	mlx_image_to_window(num->mlx, num->ocean, j * 75, i * 75);
	mlx_image_to_window(num->mlx, img, j * 75, i * 75);
}

void	 fun(void *param)
{
	t_num 		*num;
	int		i;
	int		j;

	num = param;
	num->hona++;
	i = 0;
	num = param;
	if( num->hona == 10 || num->hona == 20 || num->hona == 30
		|| num->hona == 40 || num->hona == 50 || num->hona == 60
		|| num->hona == 70 || num->hona == 80)
	{
		while (num->map[i] )
		{
			j = 0;
			while (num->map[i][j])
			{
				if (num->map[i][j] == 'C')
					print_anime(num, i, j, 'C');
				else if (num->map[i][j] == 'A')
					print_anime(num, i, j, 'A');
				j++;	
			}
			i++;
		}
	}
	if (num->hona == 85)
		num->hona = 0;
}

int	main(int ac, char **av)
{
	t_num	num;
	mlx_t	*mlx;
	char	**map;

	num.hona = 0;
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
		mlx_loop_hook(mlx, &fun, &num);
		mlx_loop(mlx);
		free_2d(map);
	}
}
