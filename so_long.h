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
    void    *chr;
    void    *wall;
    void    *piece;
    void    *exit;
    void    *sol;
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
    int coin;
    int maxcoin;
    char *addr;
    char *av;
    char *str;
    char **map;
    char	*relative_path;
    int		img_width ;
	int		img_height;
    int     newposj;
    int     newposi;
    int     movements;
    int sumposi;
    int sumposj;

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
void    put_win(t_data *ptr);
void	put_floor(t_data *ptr);
void    ft_search_char(t_data *ptr);
void    ft_put_chr(t_data *ptr, t_data *win);
void    ft_put_wall1(t_data *ptr, t_data *win);
void    ft_put_collec(t_data *ptr, t_data *win);
void    ft_search_collec(t_data *ptr);
void    ft_search_wall(t_data *ptr);
void    ft_search_exit(t_data *ptr);
void    ft_put_exit(t_data *ptr, t_data *win);
int	putchr(int keycode, t_data *ptr);
void    left(t_data *ptr);
void    right(t_data *ptr);
void    up(t_data *ptr);
void    down(t_data *ptr);
int	putchr(int keycode, t_data *ptr);
int    ft_exit(t_data *ptr);
void    ft_free_data(t_data *ptr);
int check_legit_map3(t_data map);
char	*del_b(char *str);
char	*del_a(char *str);
char	*ft_read(char *before, int fd);
char	*get_next_line(int fd);
int	ft_check(char *str);
int	ft2_strlen(char *str);
char	*freenquit(char *free1, char *free2, char *rtn);
char	*ft2_strdup(char *str);
char	*strmcat(char *s1, char *s2);
int ft_texture(t_data *ptr, void *pt, int q);
void	ft_lol(t_data *x, void *ptr);
void    ft_left_or_right(int keycode, t_data *ptr);
#endif
