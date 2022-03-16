
#include "so_long.h"

int	get_len_file(char *av);

char **ft_fill_map(char *av)
{
	char **str;
	//int i;
	int j;
	(void) j;
	t_data fd;

//	i = 1;
	j = 1;
	fd.i = get_len_file(av);

	//printf("XXXXX%dXXXXXXX", fd.i);
	//str = ft_calloc(fd.i, sizeof(char *));
	
	str = malloc(sizeof(char *) * (fd.i + 1));
	fd.fd = open(av, O_RDONLY);
	str[0] = get_next_line(fd.fd);
	printf("%s ", str[0]);
	while (j < fd.i)
	{
		str[j] = get_next_line(fd.fd);
		printf("%s ", str[j]);
		j++;
	}
	str[j] = NULL;
	//printf("%s", str);
	return str;
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
int	check_legit_map(char ***str)
{
	(void) str;
	return 1;
}

int main(int ac, char **av)
{
	//t_data data;
//	int i = 0;
//	int j;
	(void) ac;
	ft_fill_map(av[1]);


}
