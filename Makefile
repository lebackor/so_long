SRCS	=	so_long.c\
			check_map.c\
			utils.c\
			check_lmap.c\


OBJS = ${SRCS:.c=.o}

CC	=	gcc

CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L libft -lft
MLXFLAG	=	-L minilibx-linux -lmlx -lXext -lX11

NAME = so_long

LIBFT = libft/libft.a

CLEAN_FT	=	make fclean -C libft

all : ${NAME}

${NAME} :	${OBJS} $(LIBFT)
	@$(MAKE) $(LIBFT)
	@$(CC) ${MLXFLAG} $(CFLAGS) $(OBJS) $(LDFLAGS)  -o $@
	@echo "Ca arrive..."

%.o: %.c
	@${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}


$(LIBFT)	:
	@make -C libft


clean :
		rm -f ${OBJS} ${LIBFT} 
		${CLEAN_FT}

fclean :	clean
			rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
