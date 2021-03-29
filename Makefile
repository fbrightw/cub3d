cc		=	gcc

NAME	=	cub3D

# cfLAGS	=	-g

LIBfT	=	libft

HDRS	=	includes

SRcS	:=	$(wildcard drawing_3d/*.c get_info/*.c map_rays/*.c utils/*.c check/*.c main.c)

OBJS	=	$(SRcS:.c=.o)

RM		=	rm -f

MAP		=	map.cub

all:	$(NAME)

$(NAME):	$(OBJS)
		make -c $(LIBfT)
		cp libft/libft.a ./$(NAME)
		$(cc) ./libft/libft.a get_info/*.m -g -Imlx -lmlx -framework OpenGl -framework AppKit -O2 $(SRcS) -o $(NAME) -fsanitize=address

.c.o:
		$(cc) -I $(HDRS) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(OBJS)
		make clean -c $(LIBfT)

fclean:	clean
		$(RM) $(NAME)
		make fclean -c $(LIBfT)
		rm -f libft.a
		rm -f $(NAME)

re:		fclean all

run:	re
		./$(NAME) $(MAP)

.PHONY:	all clean fclean re run
