NAME	= cpp04
SRC		= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp
OBJ_DIR	= .obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
CC		= c++
RM		= rm -fr
FLAGS	= -Wall -Wextra -Werror -std=c++11
FSANITIZE = #-g3 -fsanitize=address

WHITE_B	= \33[1;97m
RESET 	= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(FSANITIZE) $(OBJ) -o $(NAME)
	@echo "$(WHITE_B)BUILT SUCCESFULLY$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(FSANITIZE) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re
	clear
	./$(NAME)

.PHONY: all clean fclean re run
