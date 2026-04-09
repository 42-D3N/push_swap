# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapo <rapo@rapo.rapo>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 14:56:37 by tle-pape          #+#    #+#              #
#    Updated: 2024/12/16 08:40:43 by tle-pape         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCEF = 	src/sanity.c src/main.c src/utils.c src/instructions.c \
		src/utils_2.c src/low_sort.c src/find_median.c src/sort_big.c \
		src/sort_utils.c

OBJS = ${SOURCEF:.c=.o}

NAME = libpushswap.a

PROGNAME = push_swap

all: ${NAME}

${NAME}: ${OBJS}
	cd ./libft && make
	cp ./libft/libft.a .
	mv libft.a ${NAME}
	ar -rcs ${NAME} ${OBJS}
	gcc ./src/*.c ${NAME}
	mv ./a.out ${PROGNAME}
	
clean:
	cd ./libft && make clean
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	cd ./libft && make fclean
	rm -f ${NAME}
	rm -f ${PROGNAME}

re: fclean all
	cd ./libft && make re

%.o: %.c
	gcc -Wall -Wextra -Werror -g -c $< -I include -o $@

.PHONY : all clean fclean re
