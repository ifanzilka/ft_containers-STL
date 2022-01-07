NAME		= test

MEMORY		= memory

VECTOR 		= vector

STACK 		= stack

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

$(STACK):
	$(CXX) $(CXXFLAGS) main_stack.cpp -o stack



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

start_stack: $(STACK)
			@./stack
			@rm stack

clean		:
			rm -rf $(OBJ)

fclean		: clean
			rm -rf $(NAME)

re			: fclean all