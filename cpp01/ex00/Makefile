NAME	= zombie
SRC		= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJ_DIR	= obj
OBJ		= $(SRC:.cpp=.o)
INC		= Zombie.hpp
CC		= c++
RM		= rm -fr
FLAGS	= -Wall -Wextra -Werror -std=c++11

WHITE_B	= \33[1;97m
RESET 	= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(WHITE_B)ZOMBIE BUILT SUCCESFULLY$(RESET)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
