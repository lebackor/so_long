
#include "so_long.h"

int	putchr(int keycode, t_data win)
{
	t_data	ptr;
//	(void) win;
	if (!keycode)
		ft_printf("y pas wesh");
    ptr.relative_path = "./itachi.xpm";
	//ptr.j = 0;
	ptr.img_height = 0;
	ptr.img_width = 0;
	ptr.img = mlx_xpm_file_to_image(win.ptr, ptr.relative_path, &ptr.img_width, &ptr.img_height);
	//printf("%p", ptr.img);
	mlx_put_image_to_window(win.ptr, win.winptr, ptr.img,  50 , 50);
	return (1);
}

int main(int ac, char **av)
{
	//t_data data;
//	int i = 0;
//	int j;
	t_data	ptr;


	if (ac != 2)
		return (0);
	if (!check_legit_map(av[1]))
		return (ft_printf("Error\n"));
	ptr.ptr = mlx_init();
	put_win(ptr, av[1]);
//	ft_printf("%p", ptr.perso);
	mlx_loop(ptr.ptr);
//	ft_printf("%p", ptr.perso);

}
