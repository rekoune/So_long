/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:09:46 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/21 15:56:21 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_num num;
	void *mlx ;
	char	**map;
	int		i = 0;
	int		j;
	mlx_texture_t *texture;

	map = NULL;
	if (ac == 2)
	{
		map = check_map(av[1], &num);
		mlx = mlx_init(num.n_char * 90, num.n_line * 90, "so_long", true);
		while (i < num.n_line)
		{
			j = 0;
			while (j < num.n_char)
			{
				if (map[i][j] == '1')
				{
					texture=  mlx_load_png("img/ground.png");
					mlx_image_t *img = mlx_texture_to_image(mlx, texture);
					mlx_image_to_window(mlx, img,  (j * 90), (i * 90));
				}
				else if (map[i][j] == '0' || map[i][j] =='C' || map[i][j] == 'E'|| map[i][j] == 'P')
				{
					texture=  mlx_load_png("img/ocean.png");
					mlx_image_t *img = mlx_texture_to_image(mlx, texture);
					mlx_image_to_window(mlx, img,  (j * 90), (i * 90));
				}
				if (map[i][j] == 'P')
				{
					texture=  mlx_load_png("img/player.png");
					mlx_image_t *img = mlx_texture_to_image(mlx, texture);
					mlx_image_to_window(mlx, img,  (j * 90), (i * 90));
				}
				else if (map[i][j] == 'E')
				{
					texture=  mlx_load_png("img/door_open.png");
					mlx_image_t *img = mlx_texture_to_image(mlx, texture);
					mlx_image_to_window(mlx, img,  (j * 90), (i * 90));
				}
				else if (map[i][j] == 'C')
				{
					texture=  mlx_load_png("img/coins.png");
					mlx_image_t *img = mlx_texture_to_image(mlx, texture);
					mlx_image_to_window(mlx, img,  (j * 90), (i * 90));
				}
				j++;
			}
			i++;
		}
		 mlx_loop(mlx);
		

	}
}
