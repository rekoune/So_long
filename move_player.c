/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:19:22 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/25 13:01:37 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_num *num, int a)
{
	char	*str;

	if (num->map[num->p_y][num->p_x] != 'E')
	{
		mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
		mlx_image_to_window(num->mlx, num->up, num->p_x * 75, num->p_y * 75);
	}
	if (num->map[num->p_y - 1][num->p_x] == '1')
		return ;
	mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
	if (num->map[num->p_y][num->p_x] == 'E')
		mlx_image_to_window(num->mlx, num->exit, num->p_x * 75, num->p_y * 75);
	num->p_y--;
	if (a == 0)
		mlx_image_to_window(num->mlx, num->up_left, num->p_x * 75, num->p_y
			* 75);
	else
		mlx_image_to_window(num->mlx, num->up, num->p_x * 75, num->p_y * 75);
	num->moves++;
	str = print_digit(num->moves);
	ft_write("moves = ", 1);
	ft_write(str, 1);
	ft_write("\n", 1);
	free(str);
}

void	move_down(t_num *num, int a)
{
	char	*str;

	if (num->map[num->p_y][num->p_x] != 'E')
	{
		mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
		mlx_image_to_window(num->mlx, num->player, num->p_x * 75, num->p_y
			* 75);
	}
	if (num->map[num->p_y + 1][num->p_x] == '1')
		return ;
	mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
	if (num->map[num->p_y][num->p_x] == 'E')
		mlx_image_to_window(num->mlx, num->exit, num->p_x * 75, num->p_y * 75);
	num->p_y++;
	if (a == 0)
		mlx_image_to_window(num->mlx, num->player_left, num->p_x * 75, num->p_y
			* 75);
	else
		mlx_image_to_window(num->mlx, num->player, num->p_x * 75, num->p_y
			* 75);
	str = print_digit(++num->moves);
	ft_write("moves = ", 1);
	ft_write(str, 1);
	ft_write("\n", 1);
	free(str);
}

void	move_right(t_num *num, int a)
{
	char	*str;

	if (num->map[num->p_y][num->p_x] != 'E')
	{
		mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
		mlx_image_to_window(num->mlx, num->walk, num->p_x * 75, num->p_y * 75);
	}
	if (num->map[num->p_y][num->p_x + 1] == '1')
		return ;
	mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
	if (num->map[num->p_y][num->p_x] == 'E')
		mlx_image_to_window(num->mlx, num->exit, num->p_x * 75, num->p_y * 75);
	num->p_x++;
	mlx_image_to_window(num->mlx, num->walk, num->p_x * 75, num->p_y * 75);
	num->moves++;
	str = print_digit(num->moves);
	ft_write("moves = ", 1);
	ft_write(str, 1);
	ft_write("\n", 1);
	free(str);
	(void)a;
}

void	move_lift(t_num *num, int a)
{
	char	*str;

	if (num->map[num->p_y][num->p_x] != 'E')
	{
		mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
		mlx_image_to_window(num->mlx, num->left, num->p_x * 75, num->p_y * 75);
	}
	if (num->map[num->p_y][num->p_x - 1] == '1')
		return ;
	mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
	if (num->map[num->p_y][num->p_x] == 'E')
		mlx_image_to_window(num->mlx, num->exit, num->p_x * 75, num->p_y * 75);
	num->p_x--;
	mlx_image_to_window(num->mlx, num->left, num->p_x * 75, num->p_y * 75);
	num->moves++;
	str = print_digit(num->moves);
	ft_write("moves = ", 1);
	ft_write(str, 1);
	ft_write("\n", 1);
	free(str);
	(void)a;
}

void	move_player(t_num *num, char c, int a)
{
	if (num->map[num->p_y][num->p_x] != 'E')
		num->map[num->p_y][num->p_x] = '0';
	if (c == 'W')
		move_up(num, a);
	else if (c == 'A')
		move_lift(num, a);
	else if (c == 'S')
		move_down(num, a);
	else if (c == 'D')
		move_right(num, a);
	if (num->map[num->p_y][num->p_x] == 'C')
		eat_coin(num, a);
	if (num->c == 0)
		mlx_image_to_window(num->mlx, num->door_open, num->e_x * 75, num->e_y
			* 75);
	if (num->c == 0 && num->map[num->p_y][num->p_x] == 'E')
	{
		free_2d(num->map);
		exit(0);
	}
	if (num->map[num->p_y][num->p_x] != 'E')
		num->map[num->p_y][num->p_x] = 'P';
}
