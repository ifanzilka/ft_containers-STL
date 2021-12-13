#ifndef _FT42VECTOR
#define _FT42VECTOR

/* Подключаем для аллокатора */
#include <memory>  

#include "iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

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
    class vector : public Vector_val <T, Alloc> 
    {
    public:
        //typedef T                                           value_type;
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

        /* Конструкторы с итераторами */
		template<class It>
		vector(It F, It L): _base()
        {
			Construct(F, L, &F);
		}
		
        template<class It>
		vector(It F, It L, const allocator_type& Al): _base(Al)
        {
			Construct(F, L, &F);
		}
		
        /* Деструктор */
        ~vector()
        {
			Clear();
		}

        /* Переопределение оператора = */
        vector& operator = (const vector& X)
        {
		    if (this == &X)
                ;
		    else if (X.size() == 0)
		    	Clear();
		    else if (X.size() <= size())
            {
                /* Если наш вектор больше чем тот откуда присваивание */
		    	pointer Q = Ucopy(X.begin(), X.end(), First);
		    	Destroy(Q, Last);
		    	Last = First + X.size();
		    }
		    else
            {
                /* Если размер нового ветора больше */
		    	Destroy(First, Last);
		    	_base::Alval.deallocate(First, End - First);
		    	if(Buy(X.size()))
		    		Last = Ucopy(X.begin(), X.end(), First);
		    }
		    return (*this);
        }



        /******************************************************/
        /*                      Capacity                     */
        /*****************************************************/


        /* Возвращает размер вектора */
        size_type size() const
        {
		    if (First == 0)
                return (0);
			return (Last - First);
		}

        /* Возвращет размер аллоцированной памяти */
        size_type max_size() const
        {
		    return (_base::Alval.max_size());
		}

        /* Изменение размера контейнера чтобы он содержал n элементов */
    	void resize(size_type N, T X)
        {
			if (size() < N)
                insert(end(), N - size(), X);
			else if (N < size())
				erase(begin() + N, end());
		}

		void resize(size_type N)
        {
			resize(N, T());
		}

        /* Возвращаемый размер выделенной емкости хранилища */
        size_type capacity() const
        {
		    if (First == 0)
			    return (0);
			return (End - First);
		}

        /* Проверяет, является ли вектор пустым */
        bool empty() const
        {
		    return (size() == 0);
		}

        /* Запросить изменение вместимости */
    	void reserve(size_type N)
        {
		    if (max_size() < N) // Вызываю исключение
			    Xlen();
		    else if (capacity() < N)
		    {
			    pointer Q = _base::Alval.allocate(N, (void *)0);
			    try
                {
				    Ucopy(begin(), end(), Q);
			    }
			    catch (...)
			    {
				    _base::Alval.deallocate(Q, N);
				    throw ;
			    }
			    if (First != 0)
                {
				    Destroy(First, Last);
				    _base::Alval.deallocate(First, End - First);
			    }
			    End = Q + N;
			    Last = Q + size();
			    First = Q;
		    }
    	}

        /******************************************************/
        /*                    Modifiers                      */
        /*****************************************************/

        /* Assign */
        /* Присваивает вектору новое содержимое, заменяя его текущее содержимое и соответствующим образом изменяя его размер. */
		
        template <class It>
		void assign(It F, It L)
        {
			Assign(F, L, &F);
		}
        
        void assign(size_type N, const T& X)
        {
			T Tx = X;
			erase(begin(), end());
			insert(begin(), N, Tx);
		}

        /* Добавить элемент в конeц */
        void push_back(const T& X)
        {
			insert(end(), X);
		}

        /* Удалить последний элемент */
		void pop_back()
        {
		    erase(end() -1);
		}


        /* Добавление элемента */
        iterator insert(iterator P, const T& X)
        {
			size_type Off;
			if (size() == 0)
				Off = 0;
			else
				Off = P - begin();
			insert(P, (size_type)1, X);
			return (begin() + Off);
		}

		void insert(iterator P, size_type M, const T& X)
        {
			T Tx = X;
			size_type N = capacity();
			if (M == 0)
				;
			else if (max_size() - size() < M)
				Xlen();
			else if (N < size() + M)
            {
				if ((max_size() - N / 2) < N)
					N = 0;
				else
					N = N + N / 2;
				if (N < size() + M)
					N = size() + M;
				pointer S = _base::Alval.allocate(N, (void *) 0);
				pointer Q;
				try
                {
					Q = Ucopy(begin(), P, S);
					Q = Ufill(Q, M, Tx);
					Ucopy(P, end(), Q);
				}
				catch (...)
				{
					Destroy(S, Q);
					_base::Alval.deallocate(S, N);
					throw ;
				}
				if (First != 0)
                {
					Destroy(First, Last);
					_base::Alval.deallocate(First, End - First);
				}
				End = S + N;
				Last = S + size() + M;
				First = S;
			}
			else if ((size_type)(end() - P) < M)
            {
				Ucopy(P, end(), P.base() + M);
				try
                {
					Ufill(Last, M - (end() - P), Tx);
				}
				catch (...)
                {
					Destroy(P.base() + M, Last + M);
					throw;
				}
				Last += M;
				ft::fill(P, end() - M, Tx);
			}
			else
            {
				iterator Oend = end();
				Last = Ucopy(Oend - M, Oend, Last);
				ft::copy_backward(P, Oend - M, Oend);
				ft::fill(P, P + M, Tx);
			}
		}

		template <class It>
		void insert (iterator P, It F, It L)
        {
			Fork(P, F, L, &F);
		}



        protected:

        /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/ 
        /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/ 
        /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/ 
        template <class It>
        /* Вызывается этот конструктор если */
		void Construct (It F, It L, typename ft::enable_if<ft::is_integral<It>::value, It>::type * = nullptr)
        {
			size_type N = (size_type)F;
			if (Buy(N))
			    Last = Ufill(First, N, (T)L);
		}

        /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/ 
        /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/ 
        /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/ 
		template <class It>
		/* Вызывается этот конструктор если */
        void Construct (It F, It L, typename ft::enable_if<!ft::is_integral<It>::value, It>::type * = nullptr)
        {
			Buy(0);
			//insert(begin(), F, L);
		}
        
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
        
        /* Очищаю память */
		void Clear()
        {
            if (First != 0)
            {
                Destroy(First, Last);
                /* Очищаем область */
                _base::Alval.deallocate(First, End - First);
            }
            First = 0, Last = 0, End = 0;
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

        /*****************************************************/
        /*                    Utils                          */
        /*****************************************************/

        /* */
        void Xlen() const
        {
            throw "vector<T> too long";
		    //throw std::length_error("vector<T> too long");
		}
		
        /* */
        void Xran() const
        {
            throw "vector<T> subscript";
		    //throw std::length_error("vector<T> subscript");
		}


        /* Указатель на T .На начало , на полседний элемент , на конец */
        pointer First, Last, End;
    };
}

#endif