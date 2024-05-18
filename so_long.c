#include "so_long.h"


int main(int ac, char **av)
{
	t_map	*head;
	char	**map = NULL;

	head = NULL;
	if (ac == 2)
	{
		map = check_map(av[1], &head);
	}
	// while (*map)
	// {
	// 	printf("%s", *map);
	// 	map++;
	// }
	system("leaks so_long");
}
