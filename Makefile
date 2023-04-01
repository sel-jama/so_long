# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 02:02:58 by sel-jama          #+#    #+#              #
#    Updated: 2023/04/01 02:17:49 by sel-jama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c checker_map.c so_long_utils.c

OBJS = ${SRCS: .c=.o}
	
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

all: ${NAME}

${NAME} : ${OBJS}
	make -C libft/
	${CC} ${CFLAGS} ${OBJS} libft/libft.a -o ${NAME}

clean :
	rm -f ${OBJS}
	make clean -C libft/

fclean : clean
	rm -f ${NAME}
	make fclean -C libft/

re : fclean all
