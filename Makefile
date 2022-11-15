# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlevilla <rlevilla@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 02:35:28 by rlevilla          #+#    #+#              #
#    Updated: 2022/11/15 21:23:49 by rlevilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf_bucket.c ft_printf_char.c ft_printf_s.c ft_printf_int.c ft_printf_u.c ft_printf_x.c ft_printf_majx.c ft_printf_p.c ft_printf.c

OBJS	= ${SRCS:.c=.o}
CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

OPTIONS	= -I

NAME	= libftprintf.a

all:	${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		ar rcs ${NAME} ${OBJS}
		ranlib ${NAME}

clean:
			${RM} ${OBJS}

fclean:	clean
				${RM} ${NAME}
re:	fclean all

.PHONY: clean fclean all re
