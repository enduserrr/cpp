NAME = bureaucrat
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++11
SRCS = main.cpp Bureaucrat.cpp	 AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
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
