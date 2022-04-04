
#include "so_long.h"
/*
int	putchr(int keycode, t_data *ptr)
{
	if (!keycode)
		ft_printf("y pas wesh");

    ptr->relative_path = "./itachi.xpm";
	ptr->img_height = 0;
	ptr->img_width = 0;

	ptr->img = mlx_xpm_file_to_image(&ptr->ptr, ptr->relative_path, &ptr->img_width, &ptr->img_height);

	mlx_put_image_to_window(&ptr->ptr, ptr->winptr, ptr->img, (1 * 50) , (1 * 50));

	return (0);
}*/

int	putchr(int keycode, t_data *ptr)
{

	ptr->img = mlx_xpm_file_to_image(ptr->ptr, "./grass.xpm", &ptr->img_width, &ptr->img_height);
	if (keycode == 65361 && ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) - 1] != '1')//GAUCHE
	{
		if(ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) - 1] == 'C')
		{
			ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) - 1] = '0';
			ptr->coin++;
			printf("COIN DETECTED\n");
		}
		if(ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) - 1] == 'E')
		{
			if (ptr->coin == ptr->maxcoin)
				exit(1);
				//fonctionexit
		}
		if(ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E')
			ptr->img = mlx_xpm_file_to_image(ptr->ptr, "./coin.xpm", &ptr->img_width, &ptr->img_height);
		mlx_put_image_to_window(ptr->ptr, ptr->winptr, ptr->img, (ptr->j + ptr->newposj) * 50, (ptr->i + ptr->newposi) * 50);
		ptr->newposj =ptr->newposj - 1 ;
		ft_search_char(ptr);
	}
	if (keycode == 65363) // DROITE
	{
		if (ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) + 1] != '1')
		{
			if (ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) + 1] == 'C')
			{
				ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) + 1] = '0';
				ptr->coin++;
				printf("COIN DETECTED\n");
			}
		if(ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) + 1] == 'E')
		{
			if (ptr->coin == ptr->maxcoin)
				exit(1);
				//fonctionexit
		}
		printf("%c\n",ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)]);
		if(ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E')
		{

			ptr->img = mlx_xpm_file_to_image(ptr->ptr, "./coin.xpm", &ptr->img_width, &ptr->img_height);
		}

		mlx_put_image_to_window(ptr->ptr, ptr->winptr, ptr->img, (ptr->j + ptr->newposj) * 50, (ptr->i + ptr->newposi) * 50);
		ptr->newposj =ptr->newposj + 1 ;
		ft_search_char(ptr);
		}
	}
	if (keycode == 65364) // EN BAS LA
	{
		if (ptr->map[(ptr->i + ptr->newposi + 1)][ptr->j + ptr->newposj] != '1')
		{
			if (ptr->map[(ptr->i + ptr->newposi + 1)][ptr->j + ptr->newposj] == 'C')
			{
				ptr->map[(ptr->i + ptr->newposi + 1)][ptr->j + ptr->newposj] = '0';
				ptr->coin++;
				printf("COIN DETECTED\n");
			}
		if(ptr->map[(ptr->i + ptr->newposi + 1)][ptr->j + ptr->newposj] == 'E')
		{
			if (ptr->coin == ptr->maxcoin)
				exit(1);
				//fonctionexit
		}
		if(ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E')
			ptr->img = mlx_xpm_file_to_image(ptr->ptr, "./coin.xpm", &ptr->img_width, &ptr->img_height);
		mlx_put_image_to_window(ptr->ptr, ptr->winptr, ptr->img, (ptr->j + ptr->newposj) * 50, (ptr->i + ptr->newposi) * 50);
		ptr->newposi =ptr->newposi + 1 ;
		ft_search_char(ptr);
		}
	}
	if (keycode == 65362) // HAUT
	{
		if (ptr->map[(ptr->i + ptr->newposi - 1)][ptr->j + ptr->newposj] != '1')
		{
			if (ptr->map[(ptr->i + ptr->newposi - 1)][ptr->j + ptr->newposj] == 'C')
			{
				ptr->map[(ptr->i + ptr->newposi - 1)][ptr->j + ptr->newposj] = '0';
				ptr->coin++;
				printf("COIN DETECTED\n");
			}
		if(ptr->map[(ptr->i + ptr->newposi - 1)][ptr->j + ptr->newposj] == 'E')
		{
			if (ptr->coin == ptr->maxcoin)
				exit(1);
				//fonctionexit
		}
		if(ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E')
			ptr->img = mlx_xpm_file_to_image(ptr->ptr, "./coin.xpm", &ptr->img_width, &ptr->img_height);
		
		mlx_put_image_to_window(ptr->ptr, ptr->winptr, ptr->img, (ptr->j + ptr->newposj) * 50, (ptr->i + ptr->newposi) * 50);
		ptr->newposi =ptr->newposi - 1 ;
		ft_search_char(ptr);
		}
	}
	
	return (0);
}

int main(int ac, char **av)
{
	//t_data data;
//	int i = 0;
//	int j;
	t_data	*ptr;


	if (ac != 2)
		return (0);
	if (!check_legit_map(av[1]))
		return (ft_printf("Error\n"));
	ptr = malloc(sizeof(t_data));
	ptr->ptr = mlx_init();
	ptr->i = 0;
	ptr->coin = 0;
	ptr->map = ft_fill_map(av[1]);
	ptr->i = ft_strlenindouble(ptr->map, 0);
	ptr->y = ft_strlendouble(ptr->map);
	ptr->winptr = mlx_new_window(ptr->ptr, 50 * ptr->i, 50 * ptr->y, "so_long");
	ptr->newposj = 0;
	ptr->newposi = 0;
	ptr->av = av[1];
	put_win(ptr);
	mlx_hook(ptr->winptr, 2, 1L<<0, putchr, ptr);
	mlx_loop(ptr->ptr);
//ft_printf("x");
//	ft_printf("%p", ptr.perso);

}
