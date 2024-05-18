#include "so_long.h"

void	elements_calcul(char *str, t_num *num)
{
	int	i;
	int	len;

	i = 0;
	len = str_len_c(str, '\n');
	while (str[i] && i < len)
		{
			if(str[i] != 'P' && str[i] != 'C' &&
				str[i] != 'E' && str[i] != '0'&&
				str[i] != '1')
				error("Invalid map\n");
			if(str[i] == 'P')
			{
				num->p++;
				num->nf = 1;
				num->p_x = i;
			}
			else if(str[i] == 'E')
				num->e++;
			else if(str[i] == 'C')
				num->c++;
			i++;
		}
}

void	check_elements(t_map **head, t_num *num)
{
	t_map	*node;
	int		i;

	i = 0;
	node = *head;
	num->p = 0; 
	num->e = 0; 
	num->c = 0;
	num->p_x = 0;
	num->p_y = 0;
	num->nf = 0;
	while(node)
	{
		elements_calcul(node->line, num);
		if (num->nf == 1)
		{
			num->p_y = i;
			num->nf = 0;
		}
		node = node->next;
		i++;
	}
	printf("P = %d, E = %d, C = %d, x = %d, y = %d\n", num->p, num->e, num->c, num->p_x, num->p_y);
	if (num->c < 1 || num->p != 1 || num->e != 1)
		error("Invalid map\n");
}

void	get_map_lines(int fd, t_map **head)
{
	t_map *node;
	int	size;
	
	node = new_node(get_next_line(fd));
	size = str_len_c(node->line, '\n');
	while (node->line)
	{
		add_back(head, node);
		node = new_node(get_next_line(fd));
		if (node->line && size != str_len_c(node->line, '\n'))
			error("Invalid map\n");
	}
	free(node);
}

void	check_walls(t_map **head)
{
	t_map *node;
	int		i;

	node = *head;
	i = 0;
	while (node->line[i] && i < str_len_c(node->line, '\n'))
		if (node->line[i++] != '1')
			error("Invalid map\n");
	while (node->next)
	{
		if (node->line[0] != '1' || node->line[str_len_c(node->line, '\n') - 1] != '1')
			error("Invalid map\n");
		node = node->next;
	}
	i = 0;
	while (node->line[i] && i < str_len_c(node->line, '\n'))
		if (node->line[i++] != '1')
			error("Invalid map\n");
}

int	list_size(t_map *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return(i);
}

char **switch_to_array(t_map **head)
{
	char **array;
	t_map *node;
	int		i;

	i = 0;
	node = *head;
	array = malloc ((list_size(*head) + 1) * sizeof(char *));
	while(node)
	{
		array[i++] = node->line;
		node = node->next;
	}
	array[i] = NULL;
	return(array);
}

void	free_list(t_map **head)
{
	t_map *node;

	node = *head;
	while (*head)
	{
		node = (*head)->next;
		free(*head); 
		*head = node;
	}
	head = NULL;
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

char **copying_map(t_map *head)
{
	int	i;
	char **cpy;

	i = list_size(head);
	cpy = malloc((i + 1) * sizeof(char **));
	i = 0;
	while (head)
	{
		cpy[i++] = sub_str(head->line, str_len_c(head->line, '\0'));
		head = head->next;
	}
	cpy[i] = NULL;
	return(cpy);
}

void	flood_fill(char **map, int	x, int	y, int size)
{
	if (x < 0 || x > str_len_c(map[y], '\0') || y > size || y < 0 || map[y][x] == '1')
		return;
	map[y][x] = '1';
	flood_fill(map, x - 1, y, size);
	flood_fill(map, x + 1, y, size);
	flood_fill(map, x, y - 1, size);
	flood_fill(map, x, y + 1, size);
}

void	check_path(char **map)
{
	int i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && j < str_len_c(map[i], '\n'))
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				error("Invalid map\n");
			j++;
		}
		i++;
	}
}

char	**check_map(char *str, t_map **head)
{
	int	fd;
	char	**map;
	char	**map_copy;
	t_num	num;

	if (compare(str + (str_len_c(str, '\0') - 4), ".ber") != 0)
		error("Map file format not corect\n");
	fd = open(str, O_RDWR);
	if (fd == -1)
		error("Map file not exist\n");
	get_map_lines(fd, head);
	check_elements(head, &num);
	check_walls(head);
	map = switch_to_array(head);
	map_copy = copying_map(*head);
	flood_fill(map_copy, num.p_x, num.p_y, list_size(*head));
	check_path(map_copy);
	free_list(head);
	return(map);
}
