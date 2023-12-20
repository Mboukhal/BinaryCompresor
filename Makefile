.DEFAULT_GOAL		= run

NAME				= comp

CC					= c++

OPTION				= -Wall -Wextra -Werror

CFILES				= main.cpp utils.cpp

OBJ					= $(CFILES:.cpp=.o)

.cpp.o:
	@ $(CC) -std=c++11 -c $< -o $@

$(NAME): $(OBJ)
	@ $(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@ $(RM) $(OBJ)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

run: all clean
	@ # reset
	@ ./$(NAME)
	@ rm -rf .vscode

.PHONY: re fclean all clean