NAME		=  	test

MEMORY		=  	memory

CXX			= clang++

CXXFLAGS 	= #-Wall -Wextra -Werror -std=c++98

SRC			= main.cpp
 
OBJ			= $(SRC:.cpp=.o)

.o			: .cpp

all			: $(NAME)

$(NAME)		:  $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(MEMORY):
	$(CXX) $(CXXFLAGS) main_memory.cpp -o memory

start: all
			@./test
			@rm *.o
			@rm test

start_memory: $(MEMORY)
			@./memory
			@rm memory

clean		:
			rm -rf $(OBJ)

fclean		: clean
			rm -rf $(NAME)

re			: fclean all