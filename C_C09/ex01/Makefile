# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chcampet <chcampet@student42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 19:24:13 by chcampet          #+#    #+#              #
#    Updated: 2020/09/29 17:16:28 by chcampet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= libft.a
LIBS	= ar rcs
CC		= gcc
RM		= rm -f ${SRCS}.c
CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME}:	${OBJS}
			${LIBS} ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${NAME} 

fclean:
	${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re .c.o
