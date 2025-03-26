#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 10:26:53 by asalo             #+#    #+#              #
#    Updated: 2025/03/26 11:05:00 by asalo            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = bureaucrat
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++11
SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	clear
	./$(NAME)

.PHONY: all clean fclean re run
