/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:10:21 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/25 13:34:26 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	str_len_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

char	*sub_str(char *str, int len)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_write(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

void	error(char *str, t_map **head, char **map)
{
	if (head)
		free_list(head, 'r');
	else if (map)
		free_2d(map);
	ft_write("Error : ", 2);
	ft_write(str, 2);
	exit(1);
}
