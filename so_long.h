/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:10:18 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/25 10:56:36 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/Users/arekoune/MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char		*line;
	void		*next;
}				t_map;

typedef struct s_num
{
	int			p;
	int			e;
	int			c;
	int			p_x;
	int			p_y;
	int			e_x;
	int			e_y;
	int			nf;
	int			n_line;
	int			n_char;
	char		**map;
	void		*mlx;
	int			moves;
	mlx_image_t	*player;
	mlx_image_t	*coins;
	mlx_image_t	*ocean;
	mlx_image_t	*exit;
	mlx_image_t	*ground;
	mlx_image_t	*door_open;
	mlx_image_t	*hunt;
	mlx_image_t	*left;
	mlx_image_t	*left_hunt;
	mlx_image_t	*walk;
	mlx_image_t	*up;
	mlx_image_t	*up_left;
	mlx_image_t	*player_left;

}				t_num;

// so_long.c
mlx_image_t		*get_image(char *path, void *mlx, char **map);
void			get_pointers(t_num *num);
void			draw_the_map(char **map, void *mlx, t_num *num);
void			my_key_hok(mlx_key_data_t data, void *param);

// check_map.c
void			get_map_lines(int fd, t_map **head, t_num *num);
char			**check_map(char *str, t_num *num);
void			check_elements(t_map **head, t_num *num);
int				elements_calcul(char *str, t_num *num);
void			check_walls(t_map **head);

// check_map_utils.c
char			**switch_to_array(t_map **head);
char			**copying_map(t_map *head);
void			flood_fill(char **map, int x, int y, int size);
void			check_path(char **map);
void			position(t_num *map);

// list_utils
int				compare(char *s1, char *s2);
t_map			*new_node(char *content);
void			add_back(t_map **head, t_map *new);
int				list_size(t_map *head);
void			free_list(t_map **head, char c);

// utils.c
char			*sub_str(char *str, int len);
void			free_2d(char **str);
void			error(char *str, t_map **head, char **map);
void			ft_write(char *str, int fd);
int				str_len_c(char *str, char c);

// move_player.c
void			move_up(t_num *num, int a);
void			move_down(t_num *num, int a);
void			move_right(t_num *num, int a);
void			move_lift(t_num *num, int a);
void			move_player(t_num *num, char c, int a);

// move_player_utils.c
void			eat_coin(t_num *num, int a);
char			*print_digit(long nb);

#endif