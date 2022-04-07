#include "so_long.h"

void    put_win(t_data *ptr)
{
	
	put_floor(ptr);
	ft_search_wall(ptr);
	ft_search_collec(ptr);
	ft_search_char(ptr);
	ft_search_exit(ptr);
}

void	put_floor(t_data *ptr)
{
	ptr->relative_path = "./grass.xpm";
	ptr->j = 0;
	ptr->img_height = 0;
	ptr->img_width = 0;
	ptr->sol = mlx_xpm_file_to_image(ptr->ptr, ptr->relative_path, &ptr->img_width, &ptr->img_height);
	while(ptr->j < ptr->y * 100)
	{	
		ptr->x = 0;
		while (ptr->x < ptr->i * 100)
		{
			mlx_put_image_to_window(ptr->ptr, ptr->winptr, ptr->sol, ptr->x, ptr->j);		
			ptr->x = ptr->x + 50;
			
		}
		ptr->j = ptr->j + 50;
	}

}