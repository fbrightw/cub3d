# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbrightw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    created: 2020/11/03 13:08:47 by fbrightw          #+#    #+#              #
#    Updated: 2020/11/13 14:00:28 by fbrightw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

CC	=	gcc

NAME	=	libft.a

CFLAGS	=	-Wall -Wextra -Werror

SRCS	:=	$(wildcard ft_*.c)

OBJS	:=	$(SRCS:.c=.o)

RM	=	rm	-f

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM)	$(OBJS)

fclean:	clean
	$(RM)	$(NAME)

re:	clean	all

.PHONY:	all	clean	fclean	re	bonus
