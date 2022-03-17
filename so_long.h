#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>

typedef struct s_data{

    int x;
    int y;
    int width;
    int len;
    int fd;
    int i;
    int j;
    char *av;
    char *str;
    char **map;
} t_data;

int	get_len_file(char *av);
char **ft_fill_map(char *av);
int	check_legit_map(char *av);
int ft_strlendouble(char **str);
int check_legit_map2(t_data map);
int ft_strlenindouble(char **str);
#endif
