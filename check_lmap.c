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