#include <iostream>
#include <vector>

/* Подкючаю свой вектор */
#include "../STL/vector/vector.hpp"


// int main()
// {
    
//     ft::vector<int> v;
//     std::cout << v.size();
    
//     std::vector<int> v2;

//     v.rbegin();

//     return (0);
// }

// template <class T>
// typename std::enable_if<std::is_integral<T>::value,bool>::type   is_odd (T i)
// {
//     return bool(i % 2);
// }

// // 2. второй аргумент шаблона допустим только в том случае, если T является целочисленным типом:
// template < class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
// bool is_even(T i)
// {
//     return !bool(i % 2);
// }

// int main()
// {
//     int i = 1;    // code does not compile if type of i is not integral

//     std::cout << std::boolalpha;
//     std::cout << "i is odd: " << is_odd(i) << std::endl;
//     std::cout << "i is even: " << is_even(i) << std::endl;

//     return 0;
// }
