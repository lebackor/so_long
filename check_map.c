#include "so_long.h"

int	check_legit_map(char *av)
{
    t_data  map;

    map.i = 0;
  //  map.j = 0;
    map.map = ft_fill_map(av);
    map.len = ft_strlendouble(map.map) - 1;
   // ft_printf("%d", map.len);
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
    check_legit_map2(map);
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
    map.i = ft_strlenindouble(map.map) - 1;
  //  ft_printf("%d", map.len);
    while (map.j < map.len)
    {
        if (map.map[map.j][map.i] != '1')
            return (0);
        ft_printf("%s", map.map[map.j][map.i]);
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
	str = ft_calloc(fd.i, sizeof(char *));
	fd.fd = open(av, O_RDONLY);
	while (j < fd.i)
	{
		str[j] = get_next_line(fd.fd);
		printf("%s\n", str[j]);
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
		free(fd.str);
		fd.str = get_next_line(fd.fd);
		i++;
	}
	close(fd.fd);
	return (i);
}