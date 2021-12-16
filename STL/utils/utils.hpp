# ifndef _FT42_UTILS
#define _FT42_UTILS

namespace ft
{

    /* Меняет местами элементы */
    template <class T>
    void swap( T& a, T& b )
    {
        T tmp(a);

        a = b;
        b = tmp;
    }

    /* Копирует по итераторм от firt до last в result */
    template<class InputIterator, class OutputIterator>
    OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result)
    {
        while (first != last)
        {
            *result = *first;
            ++result;
            ++first;
        }
        return result;
    }


}


#endif