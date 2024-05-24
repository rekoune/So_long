/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:09:46 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/24 11:51:33 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position(t_num *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] && map->map[i][j] != '\n')
		{
			if (map->map[i][j] == 'E')
			{
				map->e_x = j;
				map->e_y = i;
			}
			j++;
		}
		i++;
	}
}
void	add_elements(char c, int j, int i, void *mlx, t_num *num)
{
	if (c == 'C')
		mlx_image_to_window(mlx, num->coins, j * 75, i * 75);
	else if(c == 'E')
		mlx_image_to_window(mlx, num->exit, j * 75, i * 75);
}

mlx_image_t *get_image(char *path,void *mlx)
{
	mlx_texture_t *texture;
	mlx_image_t	*img;
	
	texture = mlx_load_png(path);
	if (!texture)
		error("Load png fails\n");
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error("Texture to img fails\n");
	mlx_delete_texture(texture);
	return(img);
}

void	get_pointers(t_num *num)
{
	num->coins = get_image("img/coins.png",num->mlx);
	num->ocean = get_image("img/ocean.png",num->mlx);
	num->ground = get_image("img/ground.png",num->mlx);
	num->player = get_image("img/player.png",num->mlx);
	num->player_left = get_image("img/player_left.png",num->mlx);
	num->walking = get_image("img/walking.png",num->mlx);
	num->left = get_image("img/left.png",num->mlx);
	num->hunt = get_image("img/hunt.png",num->mlx);
	num->left_hunt = get_image("img/left_hunt.png",num->mlx);
	num->up = get_image("img/up.png",num->mlx);
	num->up_left = get_image("img/up_left.png",num->mlx);
	num->door_open = get_image("img/door_open.png",num->mlx);
	num->exit = get_image("img/exit.png",num->mlx);
}
void	draw_the_map(char **map, void *mlx, t_num *num)
{
	int	i;
	int	j;
	
	get_pointers(num);
	position(num);
	i = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == '1')
				mlx_image_to_window(mlx, num->ground, j * 75, i * 75);
			else
				mlx_image_to_window(mlx, num->ocean, j * 75, i * 75);
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P')
				add_elements(map[i][j], j, i, mlx, num);
			j++;
		}
		i++;
	}
	mlx_image_to_window(mlx, num->player, num->p_x * 75, num->p_y * 75);
}

void	move_player(t_num *num, char c, int a)
{
	
	if (num->map[num->p_y][num->p_x] != 'E')
		num->map[num->p_y][num->p_x] = '0';
	if (c == 'W' && num->map[num->p_y - 1][num->p_x] != '1')
		move_up(num, a);		
	else if (c == 'A' && num->map[num->p_y][num->p_x - 1] != '1')
		move_lift(num, a);
	else if (c == 'S' && num->map[num->p_y + 1][num->p_x] != '1')
		move_down(num, a);
	else if (c == 'D' && num->map[num->p_y][num->p_x + 1] != '1')
		move_right(num, a);
	if (num->map[num->p_y][num->p_x] == 'C')
	{
		if (num->map[num->p_y][num->p_x] != 'E')
			mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
		if (c == 'A')
			mlx_image_to_window(num->mlx, num->left_hunt, num->p_x* 75, num->p_y * 75);
		else 
			mlx_image_to_window(num->mlx, num->hunt, num->p_x* 75, num->p_y * 75);
			
		num->c--;
	}	
	if (num->c == 0)
		mlx_image_to_window(num->mlx, num->door_open, num->e_x* 75, num->e_y * 75);
	if (num->c == 0 && num->map[num->p_y][num->p_x] == 'E')
		exit(0);
		
	if (num->map[num->p_y][num->p_x] != 'E')
		num->map[num->p_y][num->p_x] = 'P';
	return;
}

void	my_key_hok(mlx_key_data_t data, void *param)
{
	t_num *map;
	static int a;
	
	map = (t_num *) param;
	if ((data.key == MLX_KEY_W || data.key == MLX_KEY_UP) && data.action)
		move_player(map, 'W', a);
	else if ((data.key == MLX_KEY_A || data.key == MLX_KEY_LEFT)&& data.action)
	{
		a = 0;
		move_player(map, 'A', a);
	}
	else if ((data.key == MLX_KEY_S || data.key == MLX_KEY_DOWN) && data.action)
		move_player(map, 'S', a);
	else if ((data.key == MLX_KEY_D || data.key == MLX_KEY_RIGHT) && data.action)
	{
		a = 1;
		move_player(map, 'D', a);
	}
	else if(data.key == MLX_KEY_ESCAPE && data.action)
		exit(0);
}

int	main(int ac, char **av)
{
	t_num num;
	void *mlx ;
	char	**map;

	map = NULL;
	if (ac == 2)
	{
		map = check_map(av[1], &num);
		num.map = map;
		mlx = mlx_init(num.n_char * 75, num.n_line * 75, "so_long", false);
		if(!mlx)
		{
			printf("mlx fails\n");
			return(0);
		}
		num.mlx = mlx;
		
		draw_the_map(map, mlx, &num);
		mlx_key_hook(mlx ,&my_key_hok, &num);
		mlx_loop(mlx);
	}
}
