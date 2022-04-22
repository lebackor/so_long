/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puting.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:09:36 by lebackor          #+#    #+#             */
/*   Updated: 2022/04/20 02:18:50 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_chr(t_data *ptr, t_data *win)
{
	win->relative_path = "./sprites/itachi.xpm";
	win->chr = mlx_xpm_file_to_image(win->ptr, win->relative_path,
			&ptr->img_width, &ptr->img_height);
	if (!win->chr)
		ft_texture(win, win->chr, 1);
	if ((win->map[win->i + win->newposi][(win->j + win->newposj)] == 'E'))
	{
		if (win->chr)
		{
			mlx_destroy_image(win->ptr, win->chr);
			win->chr = NULL;
		}
		win->relative_path = "./sprites/itachi1.xpm";
		win->chr = mlx_xpm_file_to_image(win->ptr, win->relative_path,
				&ptr->img_width, &ptr->img_height);
		if (!win->chr)
			ft_texture(win, win->chr, 1);
	}
	mlx_put_image_to_window(win->ptr, win->winptr, win->chr,
		((ptr->j + win->newposj) * 50), ((ptr->i + win->newposi) * 50));
	mlx_destroy_image(win->ptr, win->chr);
	win->chr = NULL;
}

void	ft_put_collec(t_data *ptr, t_data *win)
{
	mlx_put_image_to_window(win->ptr, win->winptr,
		win->piece, (ptr->j * 50), (ptr->i * 50));
	return ;
}

void	ft_put_wall1(t_data *ptr, t_data *win)
{
	mlx_put_image_to_window(win->ptr, win->winptr,
		win->wall, (ptr->j * 50), (ptr->i * 50));
	return ;
}

void	ft_search_wall(t_data *ptr)
{
	t_data	pt;

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
	return ;
}

void	ft_put_exit(t_data *ptr, t_data *win)
{
	mlx_put_image_to_window(win->ptr, win->winptr,
		win->exit, (ptr->j * 50), (ptr->i * 50));
}
