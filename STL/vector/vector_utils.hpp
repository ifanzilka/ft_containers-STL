#ifndef _FT42VECTOR_UTILS
# define _FT42VECTOR_UTILS

#include "../utils/pair.hpp"

namespace ft
{

    /* 
        Верните первую позицию, где два диапазона различаются
        Сравнивает элементы в диапазоне [first1,last1) с элементами в диапазоне, начинающемся с first2, и возвращает первый элемент обеих последовательностей, который не совпадает.

        Элементы сравниваются с помощью оператора== (или pred, в версии (2)).

        Функция возвращает пару итераторов к первому элементу в каждом диапазоне, который не совпадает.
    */

    template <class InIt1, class InIt2> inline
    ft::pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X)
    {
    	for (; F != L && *F == *X; ++F, ++X)
    		;
    	return (pair<InIt1, InIt2>(F, X));
    }

    template <class InIt1, class InIt2, class Pr> inline
    ft::pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X, Pr P)
    {
    	for (; F != L && P(*F, *X); ++F, ++X)
    		;
    	return (pair<InIt1, InIt2>(F, X));
    }


    template <class InIt1, class InIt2> inline
    bool equal (InIt1 F, InIt1 L, InIt2 X)
    {
    	return (ft::mismatch(F, L, X).first == L);
    }

    template <class InIt1, class InIt2, class Pr> inline
    bool equal (InIt1 F, InIt1 L, InIt2 X, Pr P)
    {
        return (ft::mismatch(F, L, X, P).first == L);
    }


    template<class InIt1, class InIt2> inline
    bool lexicographical_compare(InIt1 F1, InIt1 L1, InIt2 F2, InIt2 L2)
    {
        for (; F1 != L1 && F2 != L2; ++F1, ++F2)
        {
            if (*F1 < *F2)
            {
                return (true);
            }
            else if (*F2 < *F1)
            {
                return (false);
            }
        }
        return (F1 == L1 && F2 != L2);
    }

    template<class InIt1, class InIt2, class Pr> inline
    bool lexicographical_compare(InIt1 F1, InIt1 L1, InIt2 F2, InIt2 L2, Pr P)
    {
            for (; F1 != L1 && F2 != L2; ++F1, ++F2)
            {
                if (P(*F1, *F2))
                {
                    return (true);
                }
                else if (P(*F2,*F1))
                {
                    return (false);
                }
            }
            return (F1 == L1 && F2 != L2);
        }
};

#endif