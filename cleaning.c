#include "so_long.h"

int    ft_exit(t_data *ptr)
{
      
    if (ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E' && ptr->coin == ptr->maxcoin)
        ft_printf("YOU WIN\n");
   
    ft_free_data(ptr);
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
    if (ptr->exit)
        mlx_destroy_image(ptr->ptr, ptr->exit);
    if (ptr->chr)
        mlx_destroy_image(ptr->ptr, ptr->chr);
   if (ptr->piece)
        mlx_destroy_image(ptr->ptr, ptr->piece);    
    if (ptr->wall)
        mlx_destroy_image(ptr->ptr, ptr->wall);
    if (ptr->sol)
        mlx_destroy_image(ptr->ptr, ptr->sol);
     ft_printf("e");
  //  free(ptr);
  //  if (ptr->relative_path)
    //    free(ptr->relative_path);
}