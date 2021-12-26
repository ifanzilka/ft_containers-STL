#ifndef _FT42VECTOR
#define _FT42VECTOR

/* Подключаем для аллокатора */
#include <memory>  

/* Utils (swap), (copy) */
#include "../utils/utils.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/is_integral.hpp"


#include "../iterator/iterator.hpp"


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

        /*  Use function : 
        **  Alval.allocate / Alval.deallocate
        **  Alval.destroy
        **  Alval.max_size
        */  

	};
    
    /* T - > тип данных в векторе All -> аллокатор  для выдеения памяти*/
    template<class T, class Alloc = std::allocator<T> > 
    class vector : public Vector_val <T, Alloc> 
    {
    public:
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
            //std::cout << "vector(It F, It L): _base()\n";
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


        allocator_type get_allocator() const
        {
			return (_base::Alval);
		}

        /*****************************************************/
        /*                      Iterators                    */
        /*****************************************************/

        /* мы вызваем конуструктор итератора с указателем на первый элемент */
        iterator begin()
        {
			return (iterator(First));
		}

        /* мы вызваем конуструктор итератора с указателем на первый элемент */
		const_iterator begin() const
        {
			return (const_iterator(First));
		}

        /* мы вызваем конуструктор итератора с указателем на последний элемент */
		iterator end()
        {
			return (iterator(Last));
		}

        /* мы вызваем конуструктор итератора с указателем на последний элемент */
		const_iterator end() const
        {
			return (const_iterator(Last));
		}

        /* мы вызваем конуструктор реверсивного  итератора с указателем на последний элемент */
		reverse_iterator rbegin()
        {
			return (reverse_iterator(end()));
		}

        /* мы вызваем конуструктор реверсивного  итератора с указателем на последний элемент */
		const_reverse_iterator rbegin() const
        {
			return (const_reverse_iterator(end()));
		}

        /* мы вызваем конуструктор реверсивного  итератора с указателем на первый элемент */
		reverse_iterator rend()
        {
			return (reverse_iterator(begin()));
		}
		
        /* мы вызваем конуструктор реверсивного  итератора с указателем на первый элемент */
        const_reverse_iterator rend() const
        {
			return (const_reverse_iterator(begin()));
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

        /* Изменение размера контейнера чтобы он содержал n элементов !!!!*/
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
        /*                 Element access                    */
        /*****************************************************/

        /* Пеоеопределение операторов */
        const_reference operator[] (size_type N) const
        {   
            /* К итератору прибавили N  и разыменовали */
            return (*(begin() + N));
		}

		reference operator[] (size_type N)
        {
            /* К итератору прибавили N  и разыменовали */
            return (*(begin() + N));
		}

        /* N element , отличие от [] тем что проверяется диапозон и выкидыаетя исключение out_of_range */
        const_reference at(size_type N) const
        {
			if (size() <= N)
                Xran();
			return (*(begin() + N));
		}

		reference at(size_type N)
        {
            if (size() <= N)
				Xran();
			return (*(begin() + N));	
		}

        /* Возращает первый эдлемент */
        reference front()
        {
            /* Создали итератор и разыменовали */
		    return(*begin());
		}

		const_reference front() const
        {
            /* Создали итератор и разыменовали */
			return(*begin());
		}

		/* Возвращает последний элемент */
        reference back()
        {
            //std::cout << "reference back()\n";
		    return(*(end() - 1));
		}

		
        const_reference back() const
        {
            return(*(end() - 1));
		}

        /******************************************************/
        /*                    Modifiers                      */
        /*****************************************************/
        
        /***********/
        /* Assign */
        /**********/
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

        /************/
        /* push_back*/
        /***********/

        /* Добавить элемент в конeц */
        void push_back(const T& X)
        {
			insert(end(), X);
		}

        /************/
        /* pop_back*/
        /***********/

        /* Удалить последний элемент */
		void pop_back()
        {
		    erase(end() -1);
		}

        /************/
        /* Insert   */
        /***********/

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
			
		}

		template <class It>
		void insert (iterator P, It F, It L)
        {
            //std::cout << "void insert (iterator P, It F, It L)\n";
		}

        /***********/
        /* Erase   */
        /***********/

        /* Стирание элементов*/
	    iterator erase(iterator P)
        {
            /* копируем элементы с позции P + 1 (грубо говоря смещаем на одну позцицию)*/
            ft::copy(P + 1, end(), P);
			Destroy(Last - 1, Last);
			--Last;
			return (P);
		}
		
        /*  Стираем в промежутке */
        iterator erase(iterator F, iterator L)
        {
        	if (F != L)
            {
				pointer S  = ft::copy(L, end(), F.base());
				Destroy(S, Last);
				Last = S;
			}
			return (F);
		}

        /**********/
        /*  Swap  */
        /**********/

        /* Поменять местами содержимое */
        void swap(vector &X)
        {
            /* Если совпали алокаторы*/
            if (_base::Alval == X.Alval)
            {
                ft::swap(First, X.First);
				ft::swap(Last, X.Last);
				ft::swap(End, X.End);
            }
            else
            {
                vector Tmp = *this;
				*this = X, X = Tmp;
            }

		}

        /***********/
        /*  Clear  */
        /***********/
        
        /* Очищаем */
        void clear()
        {
            erase(begin(), end());
		}

        /***************/
        /* PROTECTED   */
        /***************/

        protected:

        /* Вызывается этот конструктор если пришли числа */
        /* enable_if <True, T> */
        template <class It>
       
		void Construct (It F, It L, typename ft::enable_if<ft::is_integral<It>::value, It>::type * = nullptr)
        {
            //std:: cout << "number\n";
            //std:: cout << !ft::is_integral<It>::value << std::cout << "2\n";
			size_type N = (size_type)F;
			if (Buy(N))
			    Last = Ufill(First, N, (T)L);
		}

        /* Вызывается этот конструктор если пришли итераторы */
        /* enable_if <false, T> */
		template <class It>
        void Construct (It F, It L, typename ft::enable_if<!ft::is_integral<It>::value, It>::type * = nullptr)
        {
            //std::cout << "void Construct (It F, It L, typename ft::enable_if<!ft::is_integral<It>::value, It>::type * = nullptr)\n";
			Buy(0);
			insert(begin(), F, L);
		}
        
        /* Вызывается этот конструктор если пришли числа */
        template <class It>
		void Assign(It F, It L, typename ft::enable_if<ft::is_integral<It>::value, It>::type * = nullptr )
        {
		    assign((size_type)F, (T)L);
		}

        /* Вызывается этот конструктор если пришли итераторы */	
        template <class It>
		void Assign(It F, It L,  typename ft::enable_if<!ft::is_integral<It>::value, It>::type * = nullptr)
        {
			erase(begin(), end());
			Insert(begin(), F, L, Iter_cat(L));
		}


        template<class It>
		void Insert(iterator P, It F, It L, input_iterator_tag)
        {
			for(; F != L; ++F, ++P)
				P = insert(P, *F);
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

        /* Вызываем деструкторы  */
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
            //std::cout<< "Standart construct: !" << X << "!\n";
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

        /* lengt error*/
        void Xlen() const
        {
            throw "vector<T> too long";
		    //throw std::length_error("vector<T> too long");
		}
		
        /*  Out of range */
        void Xran() const
        {
            throw "vector<T> subscript";
		    //throw std::length_error("vector<T> subscript");
		}

        /* Указатель на T .На начало , на полседний элемент , на конец */
        pointer First, Last, End;

    };    

    /*****************************************************/
    /*             Overload operators                    */
    /*****************************************************/

    // template<class T, class allocator_type> inline
	// bool operator == (const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
    // {
	// 	return (X.size() == Y.size() && ft::equal(X.begin(), X.end(), Y.begin()));
	// }

	// template<class T, class allocator_type> inline
	// bool operator != (const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
    // {
	//     return (!(X == Y));
	// }

	// template<class T, class allocator_type> inline
	// bool operator < (const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
    // {
	// 	return (ft::lexicographical_compare(X.begin(), X.end(), Y.begin(), Y.end()));
	// }
	
    // template<class T, class allocator_type> inline
	// bool operator > (const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
    // {
	// 	return (Y < X);
	// }
	
    // template<class T, class allocator_type> inline
	// bool operator >= (const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
    // {
	// 	return (!(X < Y));
	// }
	
    // template<class T, class allocator_type> inline
	// bool operator <= (const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
    // {
	// 	return (!(Y < X));
	// }
	
	// template<class T, class allocator_type> inline
	// void swap (vector<T, allocator_type>& X, vector<T, allocator_type>& Y)
    // {
	// 	X.swap(Y);
	// }

}

#endif