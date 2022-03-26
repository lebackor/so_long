#include "so_long.h"

void    ft_search_char(t_data ptr)
{
    t_data  pt;

    pt.i = 0;
    pt.j = 0;
    while (pt.i < ft_strlendouble(ptr.map))
    {
        pt.j = 0;
        while (pt.j < ft_strlenindouble(ptr.map, pt.i))
        {
            if (ptr.map[pt.i][pt.j] == 'C')
            {
                ft_put_chr(pt, ptr);
                return ;
            }
            pt.j++;
        }
        pt.i++;
    }
    return ;
}

void    ft_put_chr(t_data ptr, t_data win)
{
    ptr.relative_path = "./itachi.xpm";
	//ptr.j = 0;
	ptr.img_height = 0;
	ptr.img_width = 0;
    ft_printf("%d %d", ptr.i, ptr.j);
	ptr.img = mlx_xpm_file_to_image(win.ptr, ptr.relative_path, &ptr.img_width, &ptr.img_height);
	mlx_put_image_to_window(win.ptr, win.winptr, ptr.img, (ptr.j * 100) , (ptr.i * 100));
}

void    ft_put_wall(t_data ptr)
{
    t_data x;

    x.relative_path = "./tree.xpm";
    x.j = 0;
	x.img_height = 0;
	x.img_width = 0;
	x.img = mlx_xpm_file_to_image(ptr.ptr, x.relative_path, &x.img_width, &x.img_height);
	mlx_put_image_to_window(ptr.ptr, ptr.winptr, x.img, 0, 0);
    while(x.j < ptr.y * 100)
	{	
		x.x = 0;
		while (x.x < ptr.i * 100)
		{
            if ((x.x == 0) || (x.j == 0) || (x.j == (ft_strlendouble(ptr.map)) * 90) || (x.x == (ft_strlenindouble(ptr.map, 0) - 0.5) * 100))
			    mlx_put_image_to_window(ptr.ptr, ptr.winptr, x.img, x.x, x.j);
			x.x = x.x + 50;
		}
		x.j = x.j + 50;
	}   
}