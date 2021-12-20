#ifndef _FT42VECTOR_REL
#define _FT42VECTOR_REL

#include "vector.hpp"

namespace ft
{
    //  /* Constructors */
    // template<class T, class Alloc>
    // ft::vector<T, Alloc>::vector () : _base()
    // {
    //     Buy(0);
    // }

    // /* Конструктор с аллокатором */
    // template<class T, class Alloc>
    // ft::vector<T, Alloc> ::vector (const allocator_type& Al): _base(Al)
    // {
    //     Buy(0);
    // }

    /* Выделяем память и заполянем нулями*/
    // template<class T, class Alloc>
    // bool ft::vector<T, Alloc>:: Buy(size_type N)
    // {
    //     First = 0, Last = 0, End = 0;
    //     if (N == 0)
    //         return (false);
    //     else
    //     {
    //         First = _base::Alval.allocate(N, (void *)0);
    //         Last = First;
    //         End = First + N;
    //         return (true);
    //     }
    // }
}
#endif