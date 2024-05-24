#include "so_long.c"

void	move_up(t_num *num, int a)
{
	mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
	if (num->map[num->p_y][num->p_x] == 'E')
		mlx_image_to_window(num->mlx, num->exit, num->p_x* 75, num->p_y * 75);
	num->p_y--;
	if (a == 0)
		mlx_image_to_window(num->mlx, num->up_left, num->p_x * 75, num->p_y * 75);
	else
		mlx_image_to_window(num->mlx, num->up, num->p_x * 75, num->p_y * 75);
}

void	move_down(t_num *num, int a)
{
	mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
	if (num->map[num->p_y][num->p_x] == 'E')
	mlx_image_to_window(num->mlx, num->exit, num->p_x* 75, num->p_y * 75);
	num->p_y++;
	if (a == 0)
		mlx_image_to_window(num->mlx, num->player_left, num->p_x * 75, num->p_y * 75);
	else
		mlx_image_to_window(num->mlx, num->player, num->p_x * 75, num->p_y * 75);
}

void	move_right(t_num *num, int a)
{
	mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
	if (num->map[num->p_y][num->p_x] == 'E')
	 	mlx_image_to_window(num->mlx, num->exit, num->p_x* 75, num->p_y * 75);
	num->p_x++;
	mlx_image_to_window(num->mlx, num->walking, num->p_x * 75, num->p_y * 75);
	(void) a;
}

void	move_lift(t_num *num, int a)
{
	mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
	if (num->map[num->p_y][num->p_x] == 'E')
	 	mlx_image_to_window(num->mlx, num->exit, num->p_x* 75, num->p_y * 75);
	num->p_x--;
	mlx_image_to_window(num->mlx, num->left, num->p_x * 75, num->p_y * 75);
	(void) a;
}