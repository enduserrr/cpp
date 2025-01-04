NAME	= animal
SRC		= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJ_DIR	= .obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
INC		= Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp
CC		= c++
RM		= rm -fr
FLAGS	= -Wall -Wextra -Werror -std=c++11

WHITE_B	= \33[1;97m
RESET 	= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(WHITE_B)BUILT SUCCESFULLY$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
