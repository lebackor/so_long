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
    char *av;
    char *str;
    char ***map;
} t_data;

#endif
