#include "so_long.h"

int check_maplines(char **str)
{
    t_data i;

    i.i = 0;
    i.j = ft_strlendouble(str);
    i.len = ft_strlenindouble(str, 0);
    while (i.i < i.j)
    {
        if (i.len != ft_strlenindouble(str, i.i))
            return (0);
        i.i++;
    }
    return (1);
}

int check_pec(char **str)
{
    t_data  i;

    i.i = 0;
    i.y = 0;
    i.x = 0;
    i.width = 0;

    while (i.i < ft_strlendouble(str))
    {
        i.j = 0;
        while (i.j < ft_strlenindouble(str, i.i))
        {
            if (str[i.i][i.j] == 'P')
                i.y++;
            if (str[i.i][i.j] == 'C')
                i.x++;
            if (str[i.i][i.j] == 'E')
                i.width++;
            i.j++;
        }
        i.i++;
    }
    if (i.y == 1 && i.x >= 1 && i.width == 1)
        return (1);
    return (0);
}