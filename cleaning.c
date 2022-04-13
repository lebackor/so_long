#include "so_long.h"

int    ft_exit(t_data *ptr)
{
      
    mlx_loop_end(ptr->ptr);
    if (ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E' && ptr->coin == ptr->maxcoin)
        ft_printf("YOU WoN\n");  
    if (ptr->exit)
    {
        printf("exit\n");
        mlx_destroy_image(ptr->ptr, ptr->exit);
    }
    if (ptr->wall)
    {
        printf("wall\n");
        mlx_destroy_image(ptr->ptr, ptr->wall);
    }
    if (ptr->chr)
    {
        printf("char\n");
        mlx_destroy_image(ptr->ptr, ptr->chr);
    }
    if (ptr->piece)
    {
        printf("piece\n");
        mlx_destroy_image(ptr->ptr, ptr->piece);
    }
    if (ptr->sol)
    {
        printf("sol\n");
        mlx_destroy_image(ptr->ptr, ptr->sol);
    }
    if (ptr->img)
    {
        printf("img\n");
        mlx_destroy_image(ptr->ptr, ptr->img);
    }
    if (ptr->winptr)
    {
        printf("windows\n");
        mlx_destroy_window(ptr->ptr, ptr->winptr);
    }
    if (ptr->ptr)
    {
        printf("ptr\n");
        mlx_destroy_display(ptr->ptr);
    }
    if(ptr->map)
        ft_free_table(ptr->map);
    free(ptr->ptr);
    free(ptr);
    exit(1);
}

void    ft_free_data(t_data *ptr)
{
    ///if (ptr->addr)
       // free(ptr->addr);
   // if (ptr->av)
        //free(ptr->av);
    if (ptr->str)
        free(ptr->str);
    if(ptr->map)
        ft_free_table(ptr->map);
     ft_printf("e");
  //  free(ptr);
  //  if (ptr->relative_path)
    //    free(ptr->relative_path);
}