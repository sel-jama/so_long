# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 02:02:58 by sel-jama          #+#    #+#              #
#    Updated: 2023/05/04 05:05:14 by sel-jama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c checker_map.c so_long_utils.c display_game.c move_player.c check_map_valid.c\
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c valid_path.c

OBJS = ${SRCS:.c=.o}
	
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

all: ${NAME}

${NAME} : ${OBJS}
	@make -C libft/
	${CC} ${CFLAGS}  ${OBJS} -lmlx -framework OpenGL -framework AppKit libft/libft.a -o ${NAME}

clean :
	@rm -f ${OBJS}
	@make clean -C libft/

fclean : clean
	@rm -f ${NAME}
	@make fclean -C libft/

re : fclean all
