# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kscordel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 17:47:39 by kscordel          #+#    #+#              #
#    Updated: 2022/12/27 18:20:35 by kscordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libftprintf.a

SRC =	printf.c
	puts.c

OBJ = $(SRC:.c=.o)

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

%(NAME):	${OBJ}
			ar rc ${NAME} ${OBJ} printf.h

all:		${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
