/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:10:18 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/19 11:10:19 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	*line;
	void	*next;
}			t_map;

typedef struct s_num
{
	int		p;
	int		e;
	int		c;
	int		p_x;
	int		p_y;
	int		nf;
}			t_num;

// so_long.c

// check_map.c
void		get_map_lines(int fd, t_map **head);
char		**check_map(char *str, t_map **head);
void		check_elements(t_map **head, t_num *num);
void		elements_calcul(char *str, t_num *num);
void		check_walls(t_map **head);

// check_map_utils.c
char		**switch_to_array(t_map **head);
char		**copying_map(t_map *head);
void		flood_fill(char **map, int x, int y, int size);
void		check_path(char **map);

// list_utils
int			compare(char *s1, char *s2);
t_map		*new_node(char *content);
void		add_back(t_map **head, t_map *new);
int			list_size(t_map *head);
void		free_list(t_map **head);

// utils.c
char		*sub_str(char *str, int len);
void		free_2d(char **str);
void		error(char *str);
void		ft_write(char *str, int fd);
int			str_len_c(char *str, char c);

#endif