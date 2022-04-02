
#include "so_long.h"

int	putchr(int keycode, t_data *ptr)
{
	if (!keycode)
		ft_printf("y pas wesh");
	t_data	pt;
//	(void) ptr;
//	(void) pt;

    pt.relative_path = "./itachi.xpm";
	//ptr.j = 0;
	//ft_printf("%p", &ptr->winptr);
	pt.img_height = 0;
	pt.img_width = 0;
	ft_printf("e");
	ptr->img = mlx_xpm_file_to_image(&ptr->ptr, pt.relative_path, &pt.img_width, &pt.img_height);
	ft_printf("%p ", ptr->perso);
	//mlx_put_image_to_window(ptr->ptr, &ptr->winptr, ptr->img, (1 * 50) , (1 * 50));
	mlx_destroy_image(&ptr->ptr, ptr->perso);
    //printf("%p", &ptr->winptr);
	//mlx_destroy_window(&ptr->ptr, &ptr->winptr);
	ft_printf("e");
	
	return (0);
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
	//ft_printf("%p", &ptr.winptr);
	mlx_loop(ptr.ptr);
//ft_printf("x");
//	ft_printf("%p", ptr.perso);

}
