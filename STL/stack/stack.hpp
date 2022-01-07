#ifndef FT_STACK
# define FT_STACK
#include "../vector/vector.hpp"

/* Page 590 */

namespace ft
{
    /* Наш стек основан на векторе */
    template <class Type_stack, class Container_stack = ft::vector<Type_stack> >
    class stack
    {
    public:
		typedef Container_stack								container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;
		typedef typename container_type::size_type			size_type;

        /* Конструктор с контейнером */
        explicit stack(const container_type & Cont): _container(Cont) 
        {

        }

        /* Конструктор без параметров (берем шаблонный контейнер) */
        stack(): _container(container_type())
        {

        };

        /* Констсруктор копирования  */
        stack(const stack& copy) : _container(copy._container)
        {

        }

        /* Переопределние оператора = */
        stack& operator = (const stack& copy)
        {
            _container = copy._container;
            return *this;
        }

        bool empty() const
        {
		    return _container.empty();
		}
		
        size_type size() const
        {
		    return _container.size();
		}
		
        reference top()
        {
		    return _container.back();
		}
		
        const_reference top() const
        {
		    return _container.back();
		}

		void push(const value_type& value)
        {
		    _container.push_back(value);
		}

		void pop()
        {
		    _container.pop_back();
		}
		
        void swap(stack & other_stack)
        {
		    ft::swap(_container, other_stack._container);
		}

    protected:
		container_type _container;


       
        template <class Type, class Container>
        friend bool operator == (const stack<Type, Container> & x,  const stack<Type, Container> & y);

        template <class Type, class Container>
        friend bool operator < (const stack<Type, Container> & x, const stack<Type, Container> & y);
    };

     /* Определяем операторы */
    template <class Type, class Container>
	bool operator == (const stack<Type, Container> & x, const stack<Type, Container> & y)
	{
	    return (x._container == y._container);
	};

	template <class Type, class Container>
	bool operator != (const stack<Type, Container> & x, const stack<Type, Container> & y)
	{
		return (!(x == y));
	};

	template <class Type, class Container>
    bool operator < (const stack<Type, Container> & x, const stack<Type, Container> & y)
    {
        return (x.c < y.c);
    };

	template <class Type, class Container>
    bool operator > (const stack<Type, Container> & x, const stack<Type, Container> & y)
    {
        return (y < x);
    };

	template <class Type, class Container>
    bool operator >= (const stack<Type, Container> & x, const stack<Type, Container> & y)
    {
        return (!(x < y));
    };

	template <class Type, class Container>
    bool operator <= (const stack<Type, Container> & x, const stack<Type, Container> & y)
    {
        return (!(y < x));
    };


};

#endif