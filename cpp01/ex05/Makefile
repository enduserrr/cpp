NAME	= harl
SRC		= main.cpp Harl.cpp
OBJ_DIR	= obj
OBJ		= $(SRC:.cpp=.o)
INC		= Harl.hpp
CC		= c++
RM		= rm -fr
FLAGS	= -Wall -Wextra -Werror -std=c++11

WHITE_B	= \33[1;97m
RESET 	= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(WHITE_B)BUILT SUCCESFULLY$(RESET)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
