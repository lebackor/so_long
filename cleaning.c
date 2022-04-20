/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:47:01 by lebackor          #+#    #+#             */
/*   Updated: 2022/04/20 02:51:08 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *ptr)
{
	mlx_loop_end(ptr->ptr);
	if (ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E'
	&& ptr->coin == ptr->maxcoin)
		ft_printf("YOU W0N\n");
	ft_free_data(ptr);
	free(ptr->ptr);
	free(ptr);
	exit(1);
}

void	ft_free_data(t_data *ptr)
{
	if (ptr->exit)
		mlx_destroy_image(ptr->ptr, ptr->exit);
	if (ptr->wall)
		mlx_destroy_image(ptr->ptr, ptr->wall);
	if (ptr->chr)
		mlx_destroy_image(ptr->ptr, ptr->chr);
	if (ptr->piece)
		mlx_destroy_image(ptr->ptr, ptr->piece);
	if (ptr->sol)
		mlx_destroy_image(ptr->ptr, ptr->sol);
	if (ptr->img)
		mlx_destroy_image(ptr->ptr, ptr->img);
	if (ptr->winptr)
		mlx_destroy_window(ptr->ptr, ptr->winptr);
	if (ptr->ptr)
		mlx_destroy_display(ptr->ptr);
	if (ptr->map)
		ft_free_table(ptr->map);
}

void	ft_left_or_right(int keycode, t_data *ptr)
{
	if ((keycode == 65361 || keycode == 97)
		&& ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) - 1]
		!= '1')
		left(ptr);
	if ((keycode == 65363 || keycode == 100)
		&& (ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj) + 1]
		!= '1'))
		right(ptr);
}
