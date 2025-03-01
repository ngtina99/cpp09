NAME = PmergeMe

SRC_DIR = ./src/
SRC = main.cpp PmergeMe.cpp
OBJ = $(addprefix $(SRC_DIR), $(SRC:.cpp=.o))

INC_DIR = ./inc/
MAIN_INC = -I $(INC_DIR)
INCS = $(shell find $(INC_DIR) -type f \( -name "*.hpp" -o -name "*.tpp" \))

CC = c++
RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) $(MAIN_INC) -o $(NAME)

$(SRC_DIR)%.o: $(SRC_DIR)%.cpp $(INCS)
	$(CC) $(CPPFLAGS) $(MAIN_INC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re