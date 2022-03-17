
#include "so_long.h"


int main(int ac, char **av)
{
	//t_data data;
//	int i = 0;
//	int j;
	if (ac != 2)
		return (0);
	if (!check_legit_map(av[1]))
		return (ft_printf("Error\n"));
}
