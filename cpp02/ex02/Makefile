NAME	= cpp02
SRC		= main.cpp Fixed.cpp
OBJ		= $(SRC:.cpp=.o)
FLAGS	= -Wall -Wextra -Werror -std=c++11

WHITE_B	= \33[1;97m
RESET 	= \033[0m

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(WHITE_B)BUILT SUCCESFULLY$(RESET)"

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
