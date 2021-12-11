NAME		=  	test

CXX			= clang++

CXXFLAGS 	= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp
 
OBJ			= $(SRC:.cpp=.o)

.o			: .cpp

all			: $(NAME)

$(NAME)		:  $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean		:
			rm -rf $(OBJ)

fclean		: clean
			rm -rf $(NAME)

re			: fclean all