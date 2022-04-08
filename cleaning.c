#include "so_long.h"

int    ft_exit(t_data *ptr)
{
      
    mlx_loop_end(ptr->ptr);
    if (ptr->map[ptr->i + ptr->newposi][(ptr->j + ptr->newposj)] == 'E' && ptr->coin == ptr->maxcoin)
        ft_printf("YOU WIN\n");  
   mlx_destroy_image(ptr->ptr, ptr->wall);
   //free(ptr);
   // mlx_destroy_display(ptr->ptr);

    exit(0);
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