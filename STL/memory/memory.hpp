#ifndef FT_MEMORY
# define FT_MEMORY

/* page 175 ... */

# define FARQ far
# define PDFT long
# define SIZT unsigned long // меняется в зависимости от системы

#include <iostream>
namespace ft
{
    // /*

    // // template <class T> inline
    // // T FARQ *Allocate(SIZT N, T FARQ *)
    // // {
    // //     return ((T FARQ *) operator new(N * sizeof(T))));
    // // }

    // /* Шаблонная функция Allocate */
    // template <class T> inline    
    // /* Выделяю память */
    // T*  Allocate(SIZT N, T*)
    // {
    //     return ((T*)operator new (N * sizeof(T)));
    // }

    // /* Шаблонная функция  Construct */
    // template <class T1,class T2> inline
    // void    Construct(T1 *P, const T2 & V)
    // {
    //     new ((void *)P) T1(V);
    // }


    // /* Шаблонная функция Destroy */
    // template <class T> inline
    // void Destroy(T *P)
    // {
    //     P->~T();
    // }

    // template<class T>
    // class allocator
    // {
    // public:
    //     typedef SIZT        size_type;
    //     typedef PDFT        difference_type;
    //     typedef T*          pointer;
    //     typedef const T*    const_pointer;
    //     typedef T&          reference;
    //     typedef const T&    const_reference;
    //     typedef T           value_type;

    //     /* 
    //     ** Этот шаблонны класс определяет тип other 
    //     ** Его предназначение обеспечить доступность 
    //     ** allocator<U> имея обьект типа allocator<T>
    //     */
    //     template <class U>
    //     struct rebind
    //     {
    //         typedef allocator<U> other;
    //     };

    //     pointer address(reference X) const
    //     {
    //         return (&X);
    //     }

    //     const_pointer address(const_reference X) const
    //     {
    //         return (&X); 
    //     }

    //     /* Конструкторы  */
    //     allocator()
    //     {
    //         //std::cout << "1\n";
    //     }

    //     /* Конструктор c аллокатором  */
    //     allocator(const allocator <T> &)
    //     {
    //         //std::cout << "2\n";
    //     }

    //     /* Создаем конструктор на основе другого типа */
    //     template <class U>
    //     allocator(const allocator <U> &)
    //     {
            
    //     }

    //     template <class U>
    //     allocator<T> & operator=(const allocator <U> &)
    //     {
    //         return (*this);
    //     }

    //     template <class U>
    //     pointer allocate(size_type N, const U *)
    //     {
    //         return (Allocate(N, (pointer)0));    
    //     }

        
    //     pointer allocate(size_type N)
    //     {
    //         return (Allocate(N, (pointer)0));    
    //     }

    //     void deallocate(pointer P, size_type)
    //     {
    //         operator delete(P);
    //     }

    //     void construct(pointer P, const T& V)
    //     {
    //         Construct(P, V);
    //     }

    //     void destroy(pointer P)
    //     {
    //         Destroy(P);
    //     }

    //     SIZT max_size() const
    //     {
    //         SIZT N = (SIZT)(-1) / sizeof(T);
    //         if (N > 0)
    //         {
    //             return (N);
    //         }
    //         else
    //         {
    //             return (1);
    //         }
    //     }
  
    // }; */


    template <class T>
   	class allocator
    {
        public:		
			typedef T					value_type;
			typedef T*					pointer;
			typedef const T*			const_pointer;
			typedef T&					reference;
			typedef const T& 			const_reference;
			typedef size_t				size_type;
			typedef unsigned    int     difference_type;


            /* 
            ** Этот шаблонны класс определяет тип other 
            ** Его предназначение обеспечить доступность 
            ** allocator<U> имея обьект типа allocator<T>
            */
			template <class U>
			struct rebind
            {
				typedef allocator<U> other;
			};

			pointer address(reference value) const
            {
                return &value;
            }

			const_pointer address(const_reference value) const
            {
                return &value;
            }

			allocator() throw()
            {

            }

			allocator(const allocator&) throw()
            {

            }
			
            /* Создаем конструктор на основе другого типа */
            template <class U>
			allocator (const allocator<U>&) throw()
            {

            }

			~allocator() throw()
            {

            }

			// size_type max_size() const throw()
            // {
			// 	return std::numeric_limits<size_t>::max() / sizeof(T);
			// }

            size_type max_size() const
            {
                size_type N = (size_type)(-1) / sizeof(T);
                if (N > 0)
                {
                    return (N);
                }
                else
                {
                    return (1);
                }
            }

			pointer allocate(size_type num)
            {
                pointer ret;
                size_t  size = num * sizeof(value_type);

                try
                {
                    ret = reinterpret_cast<pointer>(::operator new(size));
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                return ret;
			}

			void construct(pointer p, const T& value)
            {
				new ((void*)p) T(value);
			}

			void destroy(pointer p) 
            {
				p->~T();
			}

			void deallocate(pointer p, size_type num)
            {
				(void)num;
				::operator delete((void*)p);
			}
   };

};

#endif