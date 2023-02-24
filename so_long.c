/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:43:51 by lebackor          #+#    #+#             */
/*   Updated: 2023/01/16 19:18:01 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	random1(t_data *ptr, char *av)
{
	ptr->ptr = mlx_init();
	if (!ptr->ptr)
	{
		ft_printf("Error\n");
		// printf("t\n");
		ft_exit(ptr);
	}
	ptr->i = 0;
	ptr->coin = 0;
	ptr->map = ft_fill_map(av);
	ptr->i = ft_strlenindouble(ptr->map, 0);
	ptr->y = ft_strlendouble(ptr->map);
	ptr->winptr = mlx_new_window(ptr->ptr, 50 * ptr->i, 50 * ptr->y, "so_long");
	ptr->newposj = 0;
	ptr->newposi = 0;
	ptr->av = av;
}

int	ft_check_point(char *av)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(av, O_RDONLY | __O_NOFOLLOW);
	if (fd < 0)
		return (0);
	close(fd);
	while (av[i] != '.' && av[i])
		i++;
	if (!av[i])
		return (0);
	if (ft_strcmp(&av[i], ".ber") != 0)
		return (0);
	return (1);
}

void	ft_lol(t_data *x, void *ptr)
{
	if (!ptr)
	{
		ft_printf("Error\n");
		ft_exit(x);
	}
}

int	ft_texture(t_data *ptr, void *pt, int q)
{
	if (q == 1)
		ft_lol(ptr, pt);
	ptr->exit = mlx_xpm_file_to_image(ptr->ptr, "./sprites/door.xpm",
			&ptr->img_width, &ptr->img_height);
	if (!ptr->exit)
		ft_lol(ptr, ptr->exit);
	ptr->sol = mlx_xpm_file_to_image(ptr->ptr, "./sprites/grass.xpm",
			&ptr->img_width, &ptr->img_height);
	if (!ptr->sol)
		ft_lol(ptr, ptr->sol);
	ptr->wall = mlx_xpm_file_to_image(ptr->ptr, "./sprites/tree.xpm",
			&ptr->img_width, &ptr->img_height);
	if (!ptr->wall)
		ft_lol(ptr, ptr->wall);
	ptr->piece = mlx_xpm_file_to_image(ptr->ptr, "./sprites/coin.xpm",
			&ptr->img_width, &ptr->img_height);
	if (!ptr->piece)
		ft_lol(ptr, ptr->piece);
	return (1);
}
int	main(int ac, char **av)
{
	t_data	*ptr;

	if (ac != 2)
		return (ft_printf("Error\n"));
	ptr = NULL;
	if (!ft_check_point(av[1]) || !check_legit_map(av[1]))
		return (ft_printf("Error\n"));
	ptr = malloc(sizeof(t_data));
	if (!ptr)
	{
		ft_printf("Error\n");
		return (-1);
	}
	*ptr = (t_data){0};
	random1(ptr, av[1]);
	ptr->relative_path = "./sprites/itachi.xpm";
	ft_texture(ptr, NULL, 0);
	put_win(ptr);
	mlx_hook(ptr->winptr, 2, 1L << 0, putchr, ptr);
	mlx_hook(ptr->winptr, 17, 1L << 0, ft_exit, ptr);
	mlx_loop(ptr->ptr);
}
