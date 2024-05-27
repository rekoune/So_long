#include "so_long_bonus.h"

void	get_coin_pointers(t_game *game)
{
	game->animation.coin = malloc(9 * sizeof(mlx_image_t));
	game->animation.coin[0] = get_image("bonus/textures/coin1.png", game);
	game->animation.coin[1] = get_image("bonus/textures/coin2.png", game);
	game->animation.coin[2] = get_image("bonus/textures/coin3.png", game);
	game->animation.coin[3] = get_image("bonus/textures/coin4.png", game);
	game->animation.coin[4] = get_image("bonus/textures/coin5.png", game);
	game->animation.coin[5] = get_image("bonus/textures/coin6.png", game);
	game->animation.coin[6] = get_image("bonus/textures/coin7.png", game);
	game->animation.coin[7] = get_image("bonus/textures/coin8.png", game);
	game->animation.coin[8] = NULL;

	game->animation.enemy_up = malloc(9 * sizeof(mlx_image_t));
	game->animation.enemy_up[0] = get_image("bonus/textures/enemy1.png", game);
	game->animation.enemy_up[1] = get_image("bonus/textures/enemy2.png", game);
	game->animation.enemy_up[2] = get_image("bonus/textures/enemy3.png", game);
	game->animation.enemy_up[3] = get_image("bonus/textures/enemy4.png", game);
	game->animation.enemy_up[4] = get_image("bonus/textures/enemy5.png", game);
	game->animation.enemy_up[5] = get_image("bonus/textures/enemy6.png", game);
	game->animation.enemy_up[6] = get_image("bonus/textures/enemy7.png", game);
	game->animation.enemy_up[7] = get_image("bonus/textures/enemy8.png", game);
	game->animation.enemy_up[8] = NULL;
}

void	print_coins(t_game *game, mlx_image_t **img, int x, int y)
{
	int	i;

	i = 0;
	while(i < 8)
	{
		image_to_window(game, img[i], x, y);
		i++;
	}
}

void	enable(mlx_image_t **image, mlx_image_t *current_img)
{
	int i;

	i = 0;
	while (i < 8)
		image[i++]->enabled = 0;
	current_img->enabled = 1;
}
void	coin_animation(t_game *game)
{
		if (game->animation.timer == 10)
			enable(game->animation.coin, game->animation.coin[0]);
		else if (game->animation.timer == 20)
			enable(game->animation.coin, game->animation.coin[1]);
		else if (game->animation.timer == 30)
			enable(game->animation.coin, game->animation.coin[2]);
		else if (game->animation.timer == 40)
			enable(game->animation.coin, game->animation.coin[3]);
		else if (game->animation.timer == 50)
			enable(game->animation.coin, game->animation.coin[4]);
		else if (game->animation.timer == 60)
			enable(game->animation.coin, game->animation.coin[5]);
		else if (game->animation.timer == 70)
			enable(game->animation.coin, game->animation.coin[6]);
		else if (game->animation.timer == 80)
			enable(game->animation.coin, game->animation.coin[7]);
		game->animation.timer++;
	if (game->animation.timer == 81)
		game->animation.timer = 0;
}

void	enemy_animation(t_game *game)
{
	if (game->animation.timer_e == 10)
		enable(game->animation.enemy_up, game->animation.enemy_up[0]);
	else if (game->animation.timer_e == 20)
		enable(game->animation.enemy_up, game->animation.enemy_up[1]);
	else if (game->animation.timer_e == 30)
		enable(game->animation.enemy_up, game->animation.enemy_up[2]);
	else if (game->animation.timer_e == 40)
		enable(game->animation.enemy_up, game->animation.enemy_up[3]);
	else if (game->animation.timer_e == 50)
		enable(game->animation.enemy_up, game->animation.enemy_up[4]);
	else if (game->animation.timer_e == 60)
		enable(game->animation.enemy_up, game->animation.enemy_up[5]);
	else if (game->animation.timer_e == 70)
		enable(game->animation.enemy_up, game->animation.enemy_up[6]);
	else if (game->animation.timer_e == 80)
		enable(game->animation.enemy_up, game->animation.enemy_up[7]);
	game->animation.timer_e++;
	if (game->animation.timer_e == 81)
		game->animation.timer_e = 0;
}

void	animation(void *param)
{
	t_game *game;

	game = param;
	coin_animation(game);
	enemy_animation(game);
}