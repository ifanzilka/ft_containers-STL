#ifndef _FT42ITERATOR
#define _FT42ITERATOR
#include "iterator_tag.hpp"

/*
** Iterator такая штука которая хранит указатель на тип 
**
*/


namespace ft
{
    typedef long int ptrdiff_t;

	/* T* -> указатель T& -> ссылка */
	template <class C, class T, class D = ptrdiff_t, class Pt = T*, class Rt = T&>  
	struct iterator
	{
		typedef C		iterator_category;
		typedef T		value_type;
		typedef D		difference_type;
		typedef Pt		pointer;
		typedef Rt		reference;
	};

	/* Наследуемся и говорим */
	template  <class T, class D, class Pt, class Rt>
	struct bidirection_iterator: public iterator<bidirectional_iterator_tag, T, D, Pt, Rt>
	{

	};

	/* Наследуемся и говорим  (iterator tag)*/
	template  <class T, class D, class Pt, class Rt>
	struct Ranit: public iterator<random_access_iterator_tag, T, D, Pt, Rt> 
	{

	};

	/* Чтобы запрашивать свойства*/
	template <class It>
	struct iterator_traits
	{
		typedef typename It::iterator_category	iterator_category;
		typedef typename It::value_type 		value_type;
		typedef typename It::difference_type 	difference_type;
		typedef typename It::pointer 			pointer;
		typedef typename It::reference 			reference;
	};

	
	template<class T>
	struct iterator_traits<T *>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T 							value_type;
		typedef ptrdiff_t 					difference_type;
		typedef T 							*pointer;
		typedef T& 							reference;
	};
		

	template<class T>
	struct iterator_traits<const T *>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T 							value_type;
		typedef ptrdiff_t 					difference_type;
		typedef T 							*pointer;
		typedef T& 							reference;
	};


	template < class C, class T, class D, class Pt, class Rt> inline
	/* Штука чтобы определит с каким итератором работаем для послседующих перегрузок*/
	C Iter_cat (const iterator<C, T, D, Pt, Rt>&)
	{
		C x;
		return (x);
	}

	/*
	inline подставим код функции вместо перехода 
	*/

	template <class T> inline
	random_access_iterator_tag Iter_cat(const T*)
	{
		random_access_iterator_tag x;
		return (x);
	}

	// TEMPLATE FUNCTION Distance

	template <class InIt> inline
	typename iterator_traits<InIt>::difference_type
	distance (InIt F, InIt L)
	{
		typename iterator_traits<InIt>::difference_type
		N =  0;
		Distance2(F, L, N, Iter_cat(F));
		return (N);
	}

	template <class InIt, class D> inline
	void Distance(InIt F, InIt L, D& N)
	{
		Distance2(F, L, N, Iter_cat(F));
	}

	template <class InIt, class D> inline
	void Distance2(InIt F, InIt L, D& N, ft::input_iterator_tag)
	{
		for(; F != L; ++F)
			++N;
	}

	template <class InIt, class D> inline
	void Distance2(InIt F, InIt L, D& N, forward_iterator_tag)
	{
		for(; F != L; ++F)
			++N;
	}

	template <class InIt, class D> inline
	void Distance2(InIt F, InIt L, D& N, bidirectional_iterator_tag)
	{
		for(; F != L; ++F)
			++N;
	}

	template <class InIt, class D> inline
	void Distance2(InIt F, InIt L, D& N, random_access_iterator_tag){
		N += L - F;
	}

	/* Шаблонный класс random_acsees_iterator */

	template <class T, class D, class Pt, class Rt, class Pt2, class Rt2>
	class random_acsees_iterator : public iterator<random_access_iterator_tag, T, D, Pt, Rt> 
	{
		public:

			typedef random_acsees_iterator<T, D, Pt, Rt, Pt2, Rt2> Myt;
			
			/* Конуструктор */
			random_acsees_iterator()
			{

			};

			/*Вызывает при подачи указателя на тип */
			explicit random_acsees_iterator(Pt P): current (P) 
			{
	
			}

			/*Вызывает при подачи итератора (просто инициализирую текущий поинтер так же)*/
			random_acsees_iterator(const random_acsees_iterator<T, D, Pt, Rt, Pt2, Rt2> &X): current (X.base())
			{

			}
			
			template <class _T, class _D, class _Pt, class _Rt, class _Pt2, class _Rt2>
			random_acsees_iterator(const random_acsees_iterator<_T, _D, _Pt, _Rt, _Pt2, _Rt2> &X): current (X.base())
			{

			}

			/* Возвращаем указатель */
			Pt base() const
			{ 
				return (current);
			}
			
			/* Возвращаем ссылку при разыменовании  */
			Rt operator * () const
			{
				return (*current);
			}
			
			Pt operator -> () const
			{
				return (&**this);
			}
			
			/* Инкриментируем */
			Myt& operator++ ()
			{
				++current;
				return (*this);
			}
			
			Myt operator ++ (int)
			{
				Myt Tmp = *this;
				++current;
				return (Tmp);
			}
			
			/* Дикрементируем */
			Myt& operator-- ()
			{
				--current;
				return (*this);
			}
			
			Myt operator -- (int)
			{
				Myt Tmp = *this;
				--current;
				return (Tmp);
			}
			
			bool operator == (int Y) const
			{
				return (current == (Pt)Y);
			}
			
			bool operator == (const Myt& Y) const
			{
				return (current == Y.current);
			}
			
			bool operator != (const Myt& Y) const
			{
				return (!(*this == Y));
			}
			
			Myt& operator += (D N)
			{ 
				current += N;
				return (*this);
			}

			Myt operator + (D N) const
			{
				return (Myt(current + N));
			}
			
			Myt& operator -= (D N)
			{ 
				current -= N;
				return (*this);
			}

			Myt operator - (D N) const
			{
				return (Myt(current - N));
			}
			
			Rt operator [] (D N) const
			{
				return (*(*this + N));
			}
			
			bool operator < (const Myt& Y) const
			{ 
				return (current < Y.current);
			}
			
			bool operator > (const Myt& Y) const
			{
				return (Y < *this);
			}
			
			bool operator <= (const Myt& Y) const
			{
				return (!(Y < *this));
			}
			bool operator >= (const Myt& Y) const
			{ 
				return (!(*this < Y));
			}
			D operator - (const Myt& Y)
			{
				return (current - Y.current);
			}
		protected:
			/* pointer */
			Pt current;
	};
	
	template <class T, class D, class Pt, class Rt, class Pt2, class Rt2, class D0> inline
	random_acsees_iterator <T, D, Pt, Rt, Pt2, Rt2>
	operator + (D0 N, const random_acsees_iterator<T, D, Pt, Rt, Pt2, Rt2>& Y)
	{
		return (Y + static_cast<D>(N));
	}

	
	/* Шаблонный класс reverse_iterator */

	template <class RanIt>
	/* Наследуюсь */
	class reverse_iterator: public iterator <typename iterator_traits<RanIt>::iterator_category, typename iterator_traits<RanIt>::value_type, typename iterator_traits<RanIt>::difference_type, typename iterator_traits<RanIt>::pointer, typename iterator_traits<RanIt>::reference>
	{
		public:
			typedef 			reverse_iterator<RanIt> Myt;
			typedef typename	iterator_traits<RanIt>::difference_type D;
			typedef typename 	iterator_traits<RanIt>::pointer Pt;
			typedef typename 	iterator_traits<RanIt>::reference Rt;
			typedef RanIt 		iterator_type; /* Обычный итератор */

			reverse_iterator()
			{

			}
			
			/* Конструктор с другим итератором */
			/* rbegin -> end */
			/* rend -> begin */
			explicit reverse_iterator(RanIt X): current(X)
			{

			}
			
			/* Возвращаю обычный итератор  */
			RanIt base() const
			{
				return (current);
			}
			
			template <class U>
			reverse_iterator (const reverse_iterator<U>& X): current (X.base())
			{

			}

			Rt operator * () const
			{
				RanIt Tmp = current;
				return (*--Tmp);
			}
			
			Pt operator -> () const
			{
				return (&**this);
			}
			
			Myt& operator ++ ()
			{
				--current;
				return (*this);
			}
			
			Myt operator ++ (int){
				Myt Tmp = *this;
				--current;
				return (Tmp);
			}

			Myt& operator -- ()
			{
				++current;
				return (*this);
			}

			Myt operator -- (int)
			{
				Myt Tmp = *this;
				++current;
				return (Tmp);
			}

			Myt& operator += (D N)
			{
				current -= N;
				return (*this);
			}

			Myt operator + (D N) const
			{
				return (Myt(current - N));
			}

			Myt operator - (D N) const
			{
				return (Myt(current + N));
			}

			Myt& operator -= (D N)
			{
				current += N;
				return (*this);
			}
			Rt operator [] (D N) const
			{
				return (*(*this + N));
			}

		protected:
			/* Iterarator обычный */
			RanIt current;
	};

	// reverse_iterator TEMPLATE OPERATORS
	template <class RanIt, class RanIt1> inline
	typename reverse_iterator<RanIt>::D operator - (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	{
		return (Y.base() - X.base());
	}

	template <class RanIt, class RanIt1> inline
	bool operator == (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	{
		return (X.base() == Y.base());
	}

	template <class RanIt, class RanIt1> inline
	bool operator != (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	{
		return (!(X ==Y));
	}


	template <class RanIt, class RanIt1> inline
	bool operator < (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	{
		return (Y.base() < X.base());
	}

	template <class RanIt, class RanIt1> inline
	bool operator > (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	{
		return (Y < X);
	}

	template <class RanIt, class RanIt1> inline
	bool operator <= (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	{
		return (!(Y < X));
	}

	template <class RanIt, class RanIt1> inline
	bool operator >= (const reverse_iterator<RanIt>& X, const reverse_iterator<RanIt1>& Y)
	{
		return (!(X < Y));
	}
}

#endif