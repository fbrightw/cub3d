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

cc	=	gcc

NAME	=	libft.a

cFLAGS	=	-Wall -wextra -werror

SRcS	:=	$(wildcard ft_*.c)

#SRcS_B	:=	$(wildcard ft_lst*.c)

#SRcS	:=	$(filter-out $(SRcS_B),$(SRcS))

OBJS	:=	$(SRcS:.c=.o)

#OBJS_B	:=	$(SRcS_B:.c=.o)

RM	=	rm	-f

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

.c.o:
	$(cc) $(cFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM)	$(OBJS)

fclean:	clean
	$(RM)	$(NAME)

re:	clean	all

.PHONY:	all	clean	fclean	re	bonus
