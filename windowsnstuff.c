#include "so_long.h"


void    put_win(t_data ptr, char *av)
{

  //  void    *img;
//	t_data	i;

	ptr.i = 0;
	ptr.map = ft_fill_map(av);
	ptr.i = ft_strlenindouble(ptr.map, 0);
	ptr.y = ft_strlendouble(ptr.map);
	ptr.winptr = mlx_new_window(ptr.ptr, 50 * ptr.i, 50 * ptr.y, "so_long");
//	ptr.img = mlx_new_image(ptr.ptr, 1980, 800);
//	ptr.addr = mlx_get_data_addr(ptr.img, &ptr.bits_per_pixel, &ptr.line_length,
//								&ptr.endian);
	put_floor(ptr);
	ptr.perso = ft_search_char(ptr);
	//ft_printf("%p", ptr.perso);
	ft_search_collec(ptr);
	ft_search_exit(ptr);
	mlx_hook(ptr.winptr, 2, 1L<<0, putchr, &ptr);
		///ft_printf("%p", ptr->ptr);
	//free(ptr.map);
}

void	put_floor(t_data ptr)
{
	ptr.relative_path = "./grass.xpm";
	ptr.j = 0;
	ptr.img_height = 0;
	ptr.img_width = 0;
	ptr.img = mlx_xpm_file_to_image(ptr.ptr, ptr.relative_path, &ptr.img_width, &ptr.img_height);
	mlx_put_image_to_window(ptr.ptr, ptr.winptr, ptr.img, 0, 0);
	while(ptr.j < ptr.y * 100)
	{	
		ptr.x = 0;
		while (ptr.x < ptr.i * 100)
		{
			mlx_put_image_to_window(ptr.ptr, ptr.winptr, ptr.img, ptr.x, ptr.j);
			ptr.x = ptr.x + 50;
		}
		ptr.j = ptr.j + 50;
	}
	//ft_put_wall(ptr);
	ft_search_wall(ptr);
//	mlx_put_image_to_window(ptr.ptr, ptr.winptr, ptr.img, 100, 1000);
}