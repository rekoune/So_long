/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:10:18 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/27 21:30:24 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "/Users/arekoune/MLX42/include/MLX42/MLX42.h"
# include "get_next_line_bonus.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	char			*line;
	void			*next;
}					t_list;

typedef struct s_object
{
	mlx_image_t		**image;
	int				counter;
	int				x;
	int				y;
}					t_object;

typedef struct s_element
{
	t_object		player;
	t_object		coin;
	t_object		exit;
	t_object		ocean;
	t_object		ground;
}					t_element;

typedef struct s_map
{
	char			**array;
	int				n_line;
	int				n_char;
	int				nf;
}					t_map;

typedef struct s_animation
{
	mlx_image_t 	**coin;
	mlx_image_t		**enemy_up;
	mlx_image_t		**enemy_down;
	mlx_image_t		**enemy_right;
	mlx_image_t		**enemy_left;
	int				timer;
	int				timer_e;
	
}					t_animation;


typedef struct s_game
{
	t_element		element;
	t_map			map;
	mlx_t			*mlx;
	t_animation		animation;
	unsigned int	moves;
}					t_game;

// so_long.c
void				get_pointers(t_game *game);
void				draw_the_map(t_game *game);
void				my_key_hok(mlx_key_data_t data, void *param);
void				free_resources(t_game *game);

// check_map.c
void				get_list_lines(int fd, t_list **head, t_game *game);
char				**check_map(char *str, t_game *game);
void				check_elements(t_list **head, t_game *game);
int					elements_calcul(char *str, t_game *game);
void				check_walls(t_list **head);

// check_map_utils.c
char				**switch_to_array(t_list **head);
char				**copying_map(t_list *head);
void				flood_fill(char **map, int x, int y, int size);
void				check_path(char **map);
void				position(t_game *game);

// list_utils
int					compare(char *s1, char *s2);
t_list				*new_node(char *content);
void				add_back(t_list **head, t_list *new);
int					list_size(t_list *head);
void				free_list(t_list **head, char c);

// utils.c
char				*sub_str(char *str, int len);
void				free_2d(char **str, char c);
void				error(char *str, t_list **head, char **map);
void				ft_write(char *str, int fd);
int					str_len_c(char *str, char c);

// move_player.c
void				move_up(t_game *game, int a);
void				move_down(t_game *game, int a);
void				move_right(t_game *game, int a);
void				move_left(t_game *game, int a);
void				move_player(t_game *game, char c, int a);

// move_player_utils.c
void				eat_coin(t_game *game, int a);
char				*get_digit(long nb);
void				get_player_pointers(t_game *game);
mlx_image_t			*get_image(char *path, t_game *game);
void				image_to_window(t_game *game, mlx_image_t *img, 
						int j, int i);

//utils_2.c
void				free_objects(t_object object, mlx_t *mlx);
void				player_image_to_window(t_game *game, mlx_image_t *img);

//animation.c
void				animation(void *game);
void				print_coins(t_game *game, mlx_image_t **img, int x, int y);
void				get_coin_pointers(t_game *game);

#endif