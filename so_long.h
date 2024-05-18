#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_map
{
	char	*line;
	void	*next;
}t_map;

typedef struct s_num
{
	int	p;
	int	e;
	int c;
	int	p_x;
	int	p_y;
	int	nf;
}t_num;

//so_long.c

//check_map.c
void	get_map_lines(int fd, t_map **head);
char	**check_map(char *str, t_map **head);
void	check_elements(t_map **head);
void	elements_calcul(char *str, t_num *num);

//utils.c
void	add_back(t_map **head, t_map *new);
t_map	*new_node(char *content);
void	error(char *str);
void	ft_write(char *str, int fd);
int		compare(char *s1, char *s2);
int		str_len_c(char *str, char c);

# endif