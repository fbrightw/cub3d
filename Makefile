CC		=	gcc -Wall -Wextra -Werror

NAME	=	cub3D

HDRS	=	includes

SRCS	:=	check/check_in_mapline_odd_ch.c check/check_map.c check/check_texts.c check/check_window.c \
			drawing_3d/sprites.c drawing_3d/walls.c get_info/find_sprites.c \
			map_rays/draw_map.c map_rays/ft_spec_occas.c map_rays/raycast_tools.c map_rays/raycast.c \
			utils/before_exit.c utils/drawing_utils.c utils/floor_ceiling.c utils/screenshot.c utils/set_memories.c \
			utils/texture_utils2.c utils/textures_utils.c utils/utils_for_func_draw_everything.c utils/utils_for_main.c \
			main.c libft/ft_atoi.c libft/ft_calloc.c libft/ft_get_next_line_utils.c libft/ft_get_next_line.c libft/ft_isdigit.c\
			libft/ft_lstadd_back.c libft/ft_lstclear.c libft/ft_lstlast.c libft/ft_lstnew.c libft/ft_lstsize.c \
			libft/ft_memset.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c \
			libft/ft_strlen.c libft/ft_strncmp.c libft/ft_substr.c check/check_surronding_in_map.c

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

MAP		=	map.cub

all:	$(NAME)

bonus:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -g get_info/screen_size.m -Imlx -lmlx -framework OpenGl -framework AppKit -O2 $(SRCS) -o $(NAME)

.c.o:
		$(CC) -I $(HDRS) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)
		rm -f $(NAME)

re:		fclean all

run:	re
		./$(NAME) $(MAP)

.PHONY:	all clean fclean re run