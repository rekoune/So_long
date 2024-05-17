#include "so_long.h"


int main(int ac, char **av)
{
	t_map	*head;

	head = NULL;
	if (ac == 2)
	{
		check_map(av[1], &head);
	}
	while (head)
	{
		printf("%s", head->line);
		head  = head->next;
	}
	//system("leaks so_long");
}
