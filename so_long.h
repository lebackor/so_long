#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct s_data{

    void    *ptr;
    void    *winptr;
    void    *img;
    int		bits_per_pixel;
	int		line_length;
	int		endian;
    int x;
    int y;
    int width;
    int len;
    int fd;
    int i;
    int j;
    char *addr;
    char *av;
    char *str;
    char **map;
    char	*relative_path;
    	int		img_width ;
	int		img_height;
} t_data;

int	get_len_file(char *av);
char **ft_fill_map(char *av);
int	check_legit_map(char *av);
int ft_strlendouble(char **str);
int check_legit_map2(t_data map);
int ft_strlenindouble(char **str, int i);
int check_maplines(char **str);
int check_legit_map1(t_data map);
int check_pec(char **str);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    put_win(t_data ptr, char *av);
void	put_floor(t_data ptr);
void    ft_search_char(t_data ptr);
void    ft_put_chr(t_data ptr, t_data win);
void    ft_put_wall(t_data ptr);
#endif
