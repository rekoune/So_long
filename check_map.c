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
				num->p++;
			else if(str[i] == 'E')
				num->e++;
			else if(str[i] == 'C')
				num->c++;
			i++;
		}
}

void	check_elements(t_map **head)
{
	t_map	*node;
	t_num	num;

	node = *head;
	num.p = 0; 
	num.e = 0; 
	num.c = 0;
	while(node)
	{
		elements_calcul(node->line, &num);
		node = node->next;
	}
	if (num.c < 1 || num.p != 1 || num.e != 1)
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

void	check_map(char *str, t_map **head)
{
	int	fd;

	if (compare(str + (str_len_c(str, '\0') - 4), ".ber") != 0)
		error("Map file forma not corect\n");
	fd = open(str, O_RDWR);
	if (fd == -1)
		error("Map file not exist\n");
	get_map_lines(fd, head);
	check_elements(head);
	check_walls(head);
}
