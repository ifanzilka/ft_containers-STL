#ifndef _FT42ITERATOR
#define _FT42ITERATOR

#include "iterator_tag.hpp"


namespace ft
{
    typedef long int ptrdiff_t;

    template <class C, class T, class D = ptrdiff_t, class Pt = T*, class Rt = T&>  
	struct iterator
	{
		typedef C		iterator_category;
		typedef T		value_type;
		typedef D		difference_type;
		typedef Pt		pointer;
		typedef Rt		reference;
	};




}

#endif