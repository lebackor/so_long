#include "so_long.h"
void    ft_put_chr(t_data *ptr, t_data *win)
{
    if(win->map[win->i + win->newposi][(win->j + win->newposj)] == 'E')
		ptr->relative_path = "./itachi1.xpm";
	else
		ptr->relative_path = "./itachi.xpm";
	
	ptr->img_height = 0;
	ptr->img_width = 0;
//	if (ptr->chr)
//		free(ptr->chr);
	ptr->chr = mlx_xpm_file_to_image(win->ptr, ptr->relative_path, &ptr->img_width, &ptr->img_height);
	mlx_put_image_to_window(win->ptr, win->winptr, ptr->chr, ((ptr->j + win->newposj) * 50) , ((ptr->i + win->newposi) * 50));
	free(ptr->chr);
}

void    ft_put_collec(t_data *ptr, t_data *win)
{
    ptr->relative_path = "./coin.xpm";
	ptr->img_height = 0;
	ptr->img_width = 0;

	ptr->piece = mlx_xpm_file_to_image(win->ptr, ptr->relative_path, &ptr->img_width, &ptr->img_height);
	mlx_put_image_to_window(win->ptr, win->winptr, ptr->piece, (ptr->j * 50) , (ptr->i * 50));
	free(ptr->piece);
	return ;
}

//destro image windows display

void    ft_put_wall1(t_data *ptr, t_data *win)
{
    ptr->relative_path = "./tree.xpm";
	ptr->img_height = 0;
	ptr->img_width = 0;


	ptr->wall = mlx_xpm_file_to_image(win->ptr, ptr->relative_path, &ptr->img_width, &ptr->img_height);
	mlx_put_image_to_window(win->ptr, win->winptr, ptr->wall, (ptr->j * 50)   , (ptr->i * 50) );
	free(ptr->wall);
	return ;
}

void    ft_search_wall(t_data *ptr)
{
    t_data  pt;

    pt.i = 0;
    while (pt.i < ft_strlendouble(ptr->map))
    {
        pt.j = 0;
		while (pt.j < ft_strlenindouble(ptr->map, pt.i))
        {
            if (ptr->map[pt.i][pt.j] == '1')
                ft_put_wall1(&pt, ptr);
            pt.j++;
		}
        pt.i++;
    }
	free(ptr->wall);
    return ;
}
void    ft_put_exit(t_data *ptr, t_data *win)
{
    ptr->relative_path = "./door.xpm";
	//ptr->j = 0;
	ptr->img_height = 0;
	ptr->img_width = 0;
	//ft_printf("%d %d", ptr->i, ptr->j);
	ptr->exit = mlx_xpm_file_to_image(win->ptr, ptr->relative_path, &ptr->img_width, &ptr->img_height);
	mlx_put_image_to_window(win->ptr, win->winptr, ptr->exit, (ptr->j * 50) , (ptr->i * 50));
	free(ptr->exit);
}