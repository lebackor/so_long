/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:09:01 by lebackor          #+#    #+#             */
/*   Updated: 2022/04/20 03:00:32 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlendouble(char **str)
{
	t_data	i;

	i.i = 0;
	while (str[i.i] != NULL)
		i.i++;
	return (i.i);
}

int	ft_strlenindouble(char **str, int i)
{
	t_data	p;

	p.i = 0;
	while (str[i][p.i])
		p.i++;
	return (p.i);
}

char	**ft_fill_map(char *av)
{
	int		j;
	char	**str;
	t_data	fd;

	j = 0;
	fd.i = get_len_file(av);
	str = malloc(sizeof(char *) * (fd.i + 1));
	if (!str)
	{
		ft_printf("Error\n");
		ft_exit(&fd);
	}
	fd.fd = open(av, O_RDONLY);
	while (j < fd.i)
	{
		str[j] = get_next_line(fd.fd);
		j++;
	}
	str[j] = NULL;
	return (str);
}

int	get_len_file(char *av)
{
	t_data	fd;
	int		i;

	i = 0;
	fd.fd = open(av, O_RDONLY);
	fd.str = get_next_line(fd.fd);
	while (fd.str != NULL)
	{
		free(fd.str);
		fd.str = get_next_line(fd.fd);
		i++;
	}
	free(fd.str);
	close(fd.fd);
	return (i);
}
