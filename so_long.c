
#include "so_long.h"


int main(int ac, char **av)
{
	//t_data data;
//	int i = 0;
//	int j;
	t_data	ptr;
	void	*img;
	char	*relative_path = "./test.xpm";
	int		img_width = 10;
	int		img_height = 50;

	if (ac != 2)
		return (0);
	if (!check_legit_map(av[1]))
		return (ft_printf("Error\n"));
	ptr.ptr = mlx_init();
	ptr.i = 0;
	ptr.winptr = mlx_new_window(ptr.ptr, 1980, 800, "so_long");
	ptr.img = mlx_new_image(ptr.ptr, 1980, 800);
	ptr.addr = mlx_get_data_addr(ptr.img, &ptr.bits_per_pixel, &ptr.line_length,
								&ptr.endian);
	while (ptr.i++ < 500)
		my_mlx_pixel_put(&ptr, ptr.i, 5, 0x00FF0000);
	img = mlx_xpm_file_to_image(ptr.ptr, relative_path, &img_width, &img_height);
	printf("X%d %dX", img_width, img_height);
	mlx_put_image_to_window(ptr.ptr, ptr.winptr, ptr.img, 0, 0);
	mlx_put_image_to_window(ptr.ptr, ptr.winptr, img, 0, 0);
	mlx_loop(ptr.ptr);

}
