NAME = RPN
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++23
SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
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