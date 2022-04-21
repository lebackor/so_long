#include <stdio.h>
#include "libft.h"
int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    int fd;
    char *str;
    int i;
    
    i = 0;
    fd = open("t", O_RDONLY);
   // fd = open("bible.txt", O_RDONLY);
   while ((str = get_next_line(fd)) != NULL)
   // while (i < 11)
    {
        printf("%s", str);
        free(str);
        i++;
    }
    //printf("i==%d\n", i);
}
