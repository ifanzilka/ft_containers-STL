#include <iostream>
#include "../STL/vector/vector.hpp"
#include <vector>

int main()
{
    //std::vector<int> v1(8, 10);
    ft::vector<int> v2(8, 10);
    ft::vector<int> v3(v2.begin(), v2.end());


    //ft::vector<int> v3(1,2);
    //ft::vector<int> v4(v1.begin(), v1.end());



    return (0);
}