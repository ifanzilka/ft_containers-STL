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

$(VECTOR):
	$(CXX) $(CXXFLAGS) main_vector.cpp -o vector

start: all
			@./test
			@rm *.o
			@rm test

start_memory: $(MEMORY)
			@./memory
			@rm memory

start_vector: $(VECTOR)
			@./vector
			@rm vector

clean		:
			rm -rf $(OBJ)

fclean		: clean
			rm -rf $(NAME)

re			: fclean all