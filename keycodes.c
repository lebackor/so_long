#include "so_long.h"

int	putchr(int keycode, t_data *ptr)
{
//	printf("%p\n", ptr->exit);
    if (keycode == 65307)
        ft_exit(ptr);
  // ft_printf("%d", keycode);
	ptr->img = mlx_xpm_file_to_image(ptr->ptr, "./grass.xpm", &ptr->img_width, &ptr->img_height);
	if ((keycode == 65361 || keycode == 97) && ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) - 1] != '1')//GAUCHE
        left(ptr);
	if ((keycode == 65363 || keycode == 100) && (ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) + 1] != '1')) // DROITE
        right(ptr);
	if ((keycode == 65364 || keycode == 115) && (ptr->map[(ptr->i + ptr->newposi + 1)][ptr->j + ptr->newposj] != '1')) // EN BAS LA
        down(ptr);
	if ((keycode == 65362 || keycode == 119) && (ptr->map[(ptr->i + ptr->newposi - 1)][ptr->j + ptr->newposj] != '1')) // HAUT
        up(ptr);
	if (ptr->img)
	{
		mlx_destroy_image(ptr->ptr, ptr->img);
		ptr->img = NULL;
	}
	return (0);
}

void    left(t_data *ptr)
{
	if(ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) - 1] == 'C')
	{
		ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) - 1] = '0';
		ptr->coin++;
		ft_printf("Coin collected : %d\n", ptr->coin);
	}
	if(ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E')
	{
		mlx_destroy_image(ptr->ptr, ptr->img);
		ptr->img = NULL;
		ptr->img = mlx_xpm_file_to_image(ptr->ptr, "./door.xpm", &ptr->img_width, &ptr->img_height);
	}
	mlx_put_image_to_window(ptr->ptr, ptr->winptr, ptr->img, (ptr->j + ptr->newposj) * 50, (ptr->i + ptr->newposi) * 50);
	ptr->newposj =ptr->newposj - 1 ;
	ft_search_char(ptr);
	ptr->movements++;
	ft_printf("Total movements : %d\n", ptr->movements);
	if (ptr->coin == ptr->maxcoin && ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E')
		ft_exit(ptr);
}
void    right(t_data *ptr)
{
	if (ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) + 1] == 'C')
	{
		ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) + 1] = '0';
		ptr->coin++;
		ft_printf("Coin collected : %d\n", ptr->coin);
	}
	if(ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E')
	{
		mlx_destroy_image(ptr->ptr, ptr->img);
		ptr->img = NULL;
		ptr->img = mlx_xpm_file_to_image(ptr->ptr, "./door.xpm", &ptr->img_width, &ptr->img_height);
	}
	mlx_put_image_to_window(ptr->ptr, ptr->winptr, ptr->img, (ptr->j + ptr->newposj) * 50, (ptr->i + ptr->newposi) * 50);
	ptr->newposj =ptr->newposj + 1 ;
	ft_search_char(ptr);
	ptr->movements++;
	ft_printf("Total movements : %d\n", ptr->movements);
	if (ptr->coin == ptr->maxcoin && ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E')
		ft_exit(ptr);
}
void    up(t_data *ptr)
{
	if (ptr->map[(ptr->i + ptr->newposi - 1)][ptr->j + ptr->newposj] == 'C')
	{
		ptr->map[(ptr->i + ptr->newposi - 1)][ptr->j + ptr->newposj] = '0';
		ptr->coin++;
		ft_printf("Coin collected : %d\n", ptr->coin);
	}
	if(ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E')
	{
		mlx_destroy_image(ptr->ptr, ptr->img);
		ptr->img = NULL;
		ptr->img = mlx_xpm_file_to_image(ptr->ptr, "./door.xpm", &ptr->img_width, &ptr->img_height);
	}
	mlx_put_image_to_window(ptr->ptr, ptr->winptr, ptr->img, (ptr->j + ptr->newposj) * 50, (ptr->i + ptr->newposi) * 50);
	ptr->newposi =ptr->newposi - 1 ;
	ft_search_char(ptr);
	ptr->movements++;
	ft_printf("Total movements : %d\n", ptr->movements);
	if (ptr->coin == ptr->maxcoin && ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E')
		ft_exit(ptr);  
}
void    down(t_data *ptr)
{
    if (ptr->map[(ptr->i + ptr->newposi + 1)][ptr->j + ptr->newposj] == 'C')
	{
		ptr->map[(ptr->i + ptr->newposi + 1)][ptr->j + ptr->newposj] = '0';
		ptr->coin++;
		ft_printf("Coin collected : %d\n", ptr->coin);
	}
	if(ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E')
	{
		mlx_destroy_image(ptr->ptr, ptr->img);
		ptr->img = NULL;
		ptr->img = mlx_xpm_file_to_image(ptr->ptr, "./door.xpm", &ptr->img_width, &ptr->img_height);
	}
	mlx_put_image_to_window(ptr->ptr, ptr->winptr, ptr->img, (ptr->j + ptr->newposj) * 50, (ptr->i + ptr->newposi) * 50);
	ptr->newposi =ptr->newposi + 1 ;
	ft_search_char(ptr);
	ptr->movements++;
	ft_printf("Total movements : %d\n", ptr->movements);
	if (ptr->coin == ptr->maxcoin && ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E')
	    ft_exit(ptr);
}