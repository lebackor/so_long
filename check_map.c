#include "so_long.h"

int	check_legit_map(char *av)
{
    t_data  map;

    map.i = 0;
  //  map.j = 0;
    map.map = ft_fill_map(av);
    if (!check_maplines(map.map))
    {
        ft_free_table(map.map);
        return (0);
    }
    map.len = ft_strlendouble(map.map) - 1;
    if (!check_legit_map2(map) || !check_legit_map1(map) || !check_pec(map.map))
 {
     ft_free_table(map.map);
        return (0);
}
    ft_free_table(map.map);
    return (1);
}

int check_legit_map1(t_data map)
{
    while (map.map[0][map.i])
    {
        if (map.map[0][map.i] != '1')
            return (0);
        map.i++;
    }
    map.i = 0;
    while (map.map[map.len][map.i])
    {
        if (map.map[map.len][map.i] != '1')
            return (0);
        map.i++;
    }
    return (1);
}

int check_legit_map2(t_data map)
{
    map.i = 0;
    map.j = 0;
    while (map.i < map.len)
    {
        if (map.map[map.i][0] != '1')
            return (0);
        map.i++;
    }
    map.i = ft_strlenindouble(map.map, 0) - 1;
    while (map.j < map.len)
    {
        if (map.map[map.j][map.i] != '1')
            return (0);
        map.j++;
    }
    if (check_legit_map3(map))
        return (1);
    return (0);
}

int check_legit_map3(t_data map)
{
    map.j = 1;

    while (map.j < map.len - 1)
    {
        map.i = 1;
        while (map.i < ft_strlenindouble(map.map, 0) - 2)
        {
            if (map.map[map.j][map.i] != '0' && map.map[map.j][map.i] != 'P'
                && map.map[map.j][map.i] != 'E' && map.map[map.j][map.i] != 'C'
                && map.map[map.j][map.i] != '1')
                return (0);
            map.i++;
        }
        map.j++;
    }
    return (1);
}

char **ft_fill_map(char *av)
{
	char **str;
	int j;
	t_data fd;

	j = 0;
	fd.i = get_len_file(av);
	//str = ft_calloc(fd.i, sizeof(char *));
	str = malloc(sizeof(char *) * (fd.i + 1));
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
	int i;
	t_data fd;

	i = 0;
	fd.fd = open(av, O_RDONLY);
    fd.str = get_next_line(fd.fd);
    while (fd.str != NULL)
	{
        //if (fd.str)
		free(fd.str);
		fd.str = get_next_line(fd.fd);
		i++;
	}
    free(fd.str);    
	close(fd.fd);
	return (i);
}