#include "so_long.h"

int	str_len_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void ft_write(char *str, int fd)
{
	int	i;

	i = 0;
	while(str[i])
		write(fd, &str[i++], 1);
}

void	error(char *str)
{
	ft_write("Error\n", 2);
	ft_write(str, 2);
	exit(1);
}

t_map	*new_node(char *content)
{
	t_map	*node;

	node = malloc(sizeof(t_map));
	node->line = content;
	node->next = NULL;
	return(node);
}

void	add_back(t_map **head, t_map *new)
{
	t_map *node;

	node = *head;
	if (!(*head))
		*head = new;
	else
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
}
