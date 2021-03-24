CC		=	gcc 

NAME	=	cub3D

# CFLAGS	=	-g

LIBFT	=	libft

HDRS	=	includes

SRCS	:=	$(wildcard drawing_3d/*.c get_info/*.c map_rays/*.c utils/*.c check/*.c main.c)

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

MAP		=	map.cub

all:	$(NAME)

$(NAME):	$(OBJS)
		make -C $(LIBFT)
		cp libft/libft.a ./$(NAME)
		$(CC) ./libft/libft.a get_info/*.m -g -O3 -Imlx -lmlx -framework OpenGl -framework AppKit $(SRCS) -o $(NAME)

.c.o:
		$(CC) -I $(HDRS) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

fclean:	clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)
		rm -f libft.a
		rm -f $(NAME)

re:		fclean all

run:	re
		./$(NAME) $(MAP)

.PHONY:	all clean fclean re run
