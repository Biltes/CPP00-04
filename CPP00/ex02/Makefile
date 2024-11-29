# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 16:07:09 by migupere          #+#    #+#              #
#    Updated: 2024/11/26 16:07:19 by migupere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

SRC = Account.cpp tests.cpp

OBJS = ${SRC:.cpp=.o}

INCLUDE = -I .

CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98

.cpp.o:
		${CC} ${CPPFLAGS} ${INCLUDE} -c $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
		${CC} ${CPPFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re: clean all

.PHONY: all clean re