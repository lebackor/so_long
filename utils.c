#include "so_long.h"

int ft_strlendouble(char **str)
{
    t_data  i;

    i.i = 0;

    while (str[i.i] != NULL)
        i.i++;
    return (i.i);
}

int ft_strlenindouble(char **str, int i)
{
    t_data  p;

    p.i = 0;
    while (str[i][p.i])
        p.i++;
    return (p.i);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}