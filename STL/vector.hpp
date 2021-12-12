#ifndef _FT42VECTOR
#define _FT42VECTOR

/* Подключаем для аллокатора */
#include <memory>  
#include "iterator.hpp"

namespace ft
{
    /* Шаблонный класс vector value*/
    template <class T, class A>
    class Vector_val
    {
    protected:
    
        Vector_val(A Al = A()) : Alval(Al)
        {
        
        }
        /* Грубо говоря задали аллокатор */

        //typedef typename A::template
        //   rebind<T>::other Alty;
        //Alty Alval;
        
        typedef std::allocator<T> allocator_type;
        allocator_type Alval;
	};
    
    /* T - > тип данных в векторе All -> аллокатор  для выдеения памяти*/
    template<class T, class Alloc = std::allocator<T> > 
    class vector
    {
    public:
        typedef T                                           value_type;
        typedef Alloc                                       allocator_type;
        
        /* Класс от которого будем наследоваться*/       
        typedef Vector_val<T, Alloc>						_base;
        
        /* Заменяю чтобы легче было обращаться к именам*/
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::reference          reference;         // Так же как и ссылка  на Т
        typedef typename allocator_type::const_pointer      const_pointer;     // Так же как и постоянный указатель на Т
        typedef typename allocator_type::pointer            pointer;           // Так же как и указатель на Т
        typedef typename allocator_type::difference_type    difference_type;
        typedef typename allocator_type::size_type          size_type;          // беззнаковый целый тип, предсатвляет длину любой последовательности который может размещать шаблонный класс распределитель
        typedef typename allocator_type::value_type         value_type;

        typedef pointer                                     Tptr;               // T pointer											
        typedef const_pointer				                Ctptr;		      // Const Pointer	

    
        typedef random_acsees_iterator<value_type, difference_type, Tptr, reference, Tptr, reference> 
        iterator;
        
        typedef random_acsees_iterator<value_type, difference_type, Ctptr, const_reference, Tptr, reference> 
        const_iterator;
		
        typedef ft::reverse_iterator<iterator> 
        reverse_iterator;
		
        typedef ft::reverse_iterator<const_iterator>
		const_reverse_iterator;
        
        
        /* Constructors */
        vector () : _base()
        {
            Buy(0);
        }
        
        /* Конструктор с аллокатором */
        explicit vector (const allocator_type& Al): _base(Al)
        {
            Buy(0);
        }
        
        /* Конструктор с размером  */
        explicit vector (size_type N): _base()
        {
            if (Buy(N))
                Last = Ufill(First, N, T());
        }
        
        /* Констурктор размер и тип */
        vector (size_type N, const T& V): _base()
        {
            if (Buy(N))
                Last = Ufill(First, N, V);
        }
		
        /* Конструктор размер тип и аллокатор*/
        vector (size_type N, const T& V, const allocator_type& Al): _base(Al)
        {
            if (Buy(N))
                Last = Ufill(First, N, V);
        }	
        
        /*Конустркутор с вектором */
        vector(const vector& X): _base(X.Alval)
        {
            if (Buy(X.size()))
                Last = Ucopy(X.begin(), X.end(), First);
        }


		template<class It>
			vector(It F, It L)
				:_base() {
					Construct(F, L, &F);
		}
		template<class It>
			vector(It F, It L, const allocator_type& Al)
				:_base(Al) {
					Construct(F, L, &F);
		}
		~vector() {
			Clear();
		}

        protected:
        
        /* Выделяем память и заполянем нулями*/
        bool Buy(size_type N)
        {
            First = 0, Last = 0, End = 0;
            if (N == 0)
                return (false);
            else
            {
                First = _base::Alval.allocate(N, (void *)0);
                Last = First;
                End = First + N;
                return (true);
            }
        }
        
        /* Вызываем деструкторы */
        void Destroy(pointer F, pointer L)
        {
            for(; F != L; ++F)
                _base::Alval.destroy(F);
        }
        
        /* Копируем зачения от First до Last*/
        template<class It>
		pointer Ucopy(It F, It L, pointer Q)
        {
			pointer Qs = Q;
			try
            {
				for(; F != L; ++Q, ++F)
					_base::Alval.construct(Q, *F);
			}
			catch (...)
			{
				Destroy(Qs, Q);
				throw;
			}
			return (Q);
		}

        /* Вызываю конутсрукторы в области памяти */
    	pointer Ufill(pointer Q, size_type N, const T& X)
        {
            pointer Qs = Q;
            try
            {
                for(; 0 < N; --N, ++Q)
                    _base::Alval.construct(Q, X);
		    }
            catch (...)
            {
                Destroy(Qs, Q);
                throw;
		    }
		    return (Q);
	    }

        /* Указатель на T */
        /* На начало , на полседний элемент , на конец */
        pointer First, Last, End;
    };
}

#endif