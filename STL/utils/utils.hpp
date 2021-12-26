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

    template<class FwdIt, class T> inline
	void fill(FwdIt F, FwdIt L, const T& X)
    {
		for (; F != L; ++F)
			*F = X;
	}

	template<class OutIt, class Sz, class T> inline
	void fill(OutIt F, Sz N, const T& X)
    {
		for (; 0 < N; --N, ++F)
			*F = X;
	}


    /* C Last до First  приравниваю значения в X*/
    template <class BidIt1, class BidIt2> inline
	BidIt2 copy_backward(BidIt1 F, BidIt1 L, BidIt2 X)
    {
		while (F != L)
			*--X = *--L;
		return (X);
	}

}
#endif