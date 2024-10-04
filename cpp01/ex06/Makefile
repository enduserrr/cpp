NAME	= filter
SRC	= main.cpp Harl.cpp
OBJ_DIR	= obj
OBJ	= $(SRC:.cpp=.o)
INC	= Harl.hpp
CC	= c++
RM	= rm -fr
FLAGS	= -Wall -Wextra -Werror -std=c++11

WHITE_B	= \33[1;97m
RES	= \033[0m

all	:$(NAME)

$(NAME)	:$(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(WHITE_B)BUILT SUCCESSFULLY$(RES)"

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY all clean fclean re
