#ifndef _FT42VECTOR
#define _FT42VECTOR

/* Подключаем для аллокатора */
#include <memory>  


namespace ft
{
    /* T - > тип данных в векторе All -> аллокатор  для выдеения памяти*/
    template<class T, class Alloc = std::allocator<T> > 
    
    class Vector
	{
    public:
        typedef T											value_type;
        typedef Alloc										allocator_type;

        /* Заменяю чтобы легче было обращаться к именам*/
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::reference       reference;         // Так же как и ссылка  на Т
        typedef typename allocator_type::const_pointer   const_pointer;     // Так же как и постоянный указатель на Т
        typedef typename allocator_type::pointer         pointer;           // Так же как и указатель на Т
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::size_type       size_type;          // беззнаковый целый тип, предсатвляет длину любой последовательности который может размещать шаблонный класс распределитель
        typedef typename allocator_type::value_type      value_type;

        typedef pointer                                   Tptr;               // Tpointer											
		typedef const_pointer				              Ctptr;		      // Const Pointer	


    private:





    };
}

#endif