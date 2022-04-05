
#include "so_long.h"
void	random1(t_data *ptr, char *av)
{
	ptr->ptr = mlx_init();
	ptr->i = 0;
	ptr->coin = 0;
	ptr->map = ft_fill_map(av);
	ptr->i = ft_strlenindouble(ptr->map, 0);
	ptr->y = ft_strlendouble(ptr->map);
	ptr->winptr = mlx_new_window(ptr->ptr, 50 * ptr->i, 50 * ptr->y, "so_long");
	ptr->newposj = 0;
	ptr->newposi = 0;
	ptr->av = av;
}

int main(int ac, char **av)
{
	t_data	*ptr;

	if (ac != 2)
		return (0);
	if (!check_legit_map(av[1]))
		return (ft_printf("Error\n"));
	ptr = malloc(sizeof(t_data));
	random1(ptr, av[1]);
	put_win(ptr);
	mlx_hook(ptr->winptr, 2, 1L<<0, putchr, ptr);
	mlx_hook(ptr->winptr, 17, 1L<<0, ft_exit, ptr);
	mlx_loop(ptr->ptr);
}
