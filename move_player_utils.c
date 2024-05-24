/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:59:15 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/24 20:16:27 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	eat_coin(t_num *num, int a)
{
	mlx_image_to_window(num->mlx, num->ocean, num->p_x * 75, num->p_y * 75);
	if (a == 0)
		mlx_image_to_window(num->mlx, num->left_hunt, num->p_x * 75, num->p_y
			* 75);
	else
		mlx_image_to_window(num->mlx, num->hunt, num->p_x * 75, num->p_y * 75);
	num->c--;
}

char	*print_digit(long nb)
{
	char	str[12];
	char 	*s;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (nb == 0)
		str[i++] = '0';
	while (nb)
	{
		str[i++] = (nb % 10) + 48;
		nb = nb / 10;
	}
	str[i] = '\0';
	s = malloc(i * sizeof(char));
	i--;
	while (i >= 0)
	{
		s[j] = str[i];
		j++;
		i--;
	}
	s[j] = '\0';
	return (s);
}
