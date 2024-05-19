/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:09:46 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/19 19:57:21 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_num num;
	char	**map;

	map = NULL;
	if (ac == 2)
	{
		map = check_map(av[1], &num);
		void *mlx = mlx_init(num.n_char * 64, num.n_line * 64, "so_long", true);
		// mlx_texture_t *texture=  mlx_load_png("Photo on 5-19-24 at 6.54 PM.png");
		// mlx_image_t *img = mlx_texture_to_image(mlx, texture);
		// mlx_image_to_window(mlx, img, 0, 0);
		 mlx_loop(mlx);
		

	}
}
