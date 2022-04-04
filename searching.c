#include "so_long.h"

void    *ft_search_char(t_data *ptr)
{
    t_data  pt;

    pt.i = 0;
    pt.j = 0;

   
    while (pt.i < ft_strlendouble(ptr->map))
    {
        pt.j = 0;
        while (pt.j < ft_strlenindouble(ptr->map, pt.i))
        {
            if (ptr->map[pt.i][pt.j] == 'P')
            {
                ptr->i = pt.i;
                ptr->j = pt.j;
                ft_put_chr(&pt, ptr);
            }
            pt.j++;
        }
        pt.i++;
    }
    return (NULL);
}

void    ft_search_collec(t_data *ptr)
{
    t_data  pt;

    pt.i = 0;
    pt.j = 0;
    ptr->maxcoin = 0;
    while (pt.i < ft_strlendouble(ptr->map))
    {
        pt.j = 0;
        while (pt.j < ft_strlenindouble(ptr->map, pt.i))
        {
            if (ptr->map[pt.i][pt.j] == 'C')
            {
                ft_put_collec(&pt, ptr);
                ptr->maxcoin++;
            }
            pt.j++;
        }
        pt.i++;
    }
    return ;
}

void    ft_search_exit(t_data *ptr)
{
    t_data  pt;

    pt.i = 0;
    pt.j = 0;
    while (pt.i < ft_strlendouble(ptr->map))
    {
        pt.j = 0;
        while (pt.j < ft_strlenindouble(ptr->map, pt.i))
        {
            if (ptr->map[pt.i][pt.j] == 'E')
                ft_put_exit(&pt, ptr);
            pt.j++;
        }
        pt.i++;
    }
    return ;
}
