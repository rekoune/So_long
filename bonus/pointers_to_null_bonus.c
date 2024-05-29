/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_to_null_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:04:13 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/29 12:04:34 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	turn_to_null(t_game *game)
{
	game->animation.coin = NULL;
	game->animation.enemy_up.image = NULL;
	game->animation.enemy_down.image = NULL;
	game->animation.enemy_left.image = NULL;
	game->animation.enemy_right.image = NULL;
	game->element.coin.image = NULL;
	game->element.player.image = NULL;
	game->element.exit.image = NULL;
	game->element.ground.image = NULL;
	game->element.ocean.image = NULL;
}
