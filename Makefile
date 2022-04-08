SRCS	=	so_long.c\
			check_map.c\
			utils.c\
			check_lmap.c\
			windowsnstuff.c\
			searching.c\
			puting.c\
			cleaning.c\
			keycodes.c\


OBJS = ${SRCS:.c=.o}

CC	=	gcc

CFLAGS = -Wall -Werror -Wextra -g3
LDFLAGS = -L libft -lft
MLXFLAG	=	-L minilibx-linux -lmlx -lXext -lX11

NAME = so_long

LIBFT = libft/libft.a

MLX = 	make -C minilibx-linux

CLEAN_FT	=	make fclean -C libft

CLEAN_MLX	=	make clean -C minilibx-linux

all : ${NAME}

${NAME} :	${OBJS} $(LIBFT)
	$(MLX)
	@$(MAKE) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) ${MLXFLAG} $(LDFLAGS)  -o $@
	@echo "Ca arrive..."

%.o: %.c
	@${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o} ${MLXFLAG}


$(LIBFT)	:
	@make -C libft

clean :
		rm -f ${OBJS} ${LIBFT} 
		${CLEAN_FT}
		${CLEAN_MLX}

fclean :	clean
			rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
