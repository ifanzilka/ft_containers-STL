#include <iostream>
#include "../STL/stack/stack.hpp"

#ifndef COLOR

# define COLOR
# define F_NONE		"\033[37m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define CYANE		"\033[36m"
# define WHITE		"\033[1m"
# define YELLOW	    "\033[0;33m"
# define BLUE		"\033[34m" 
# define PURPLE     "\033[0;35m"

/* 
** Bold font  
** param [1; in range [1, 4]
*/
# define B_GRAY      "\033[1;30m"
# define B_WHITE     "\033[1;37m"
# define B_RED       "\033[1;31m"
# define B_YELLOW    "\033[1;33m"
# define B_GREEN     "\033[1;32m"
# define B_CYAN      "\033[1;36m"
# define B_BLUE      "\033[1;34m"
# define B_PURPLE    "\033[1;35m"

#endif

void test_vector()
{
    ft::stack<int> stack;
	ft::stack<int> stack1;

    /* Проверяем что стек пустой*/
	assert(stack1.empty());

    /* Добвляем в стек числа */
	for (int i = 0; i < 30; i++)
		stack1.push(i);
    
    /* Проверяем что стек не пустой */
	assert(!stack1.empty());
	
    /* Проверяем размер*/
    assert(stack1.size() == 30);
	
    /* Меняем местами стеки */
    stack.swap(stack1);
	
    /* Пустота */
    assert(stack1.empty());

    /* По циклу вводим */
	while (!stack.empty())
    {
	    std::cout << stack.top() << " ";
		stack.pop();
	}
    std::cout << "\n";


    /* ПРоверка операторов*/
    if (stack1 == stack)
        std::cout << "(stack1 == stack)\n";
    else
         std::cout << "(stack1 != stack)\n";

	stack.push(0);

    if (stack1 == stack)
        std::cout << "(stack1 == stack)\n";
    else
         std::cout << "(stack1 != stack)\n";

   
    
    std::cout << std::endl;

    std::cout << GREEN <<"SUCCESS testing  <stack>" <<  F_NONE <<std::endl;
}

int main()
{   
    test_vector();

    // std::cout <<B_WHITE <<"SUCCESS testing  <vector>" <<  F_NONE <<std::endl;
    // std::cout <<B_RED <<"SUCCESS testing  <vector>" <<  F_NONE <<std::endl;
    // std::cout <<B_YELLOW <<"SUCCESS testing  <vector>" <<  F_NONE <<std::endl;
    // std::cout <<B_GREEN <<"SUCCESS testing  <vector>" <<  F_NONE <<std::endl;
    // std::cout <<B_CYAN <<"SUCCESS testing  <vector>" <<  F_NONE <<std::endl;
    // std::cout <<B_PURPLE <<"SUCCESS testing  <vector>" <<  F_NONE <<std::endl;
    // std::cout <<B_BLUE <<"SUCCESS testing  <vector>" <<  F_NONE <<std::endl;

    return (0);
}