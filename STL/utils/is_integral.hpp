#ifndef _FT42_IS_INTEGRAL_H
# define _FT42_IS_INTEGRAL_H

#include <type_traits>
#include <iostream>

/*
**  Класс признака, определяющий, является ли T типом функции.
**
**  Он наследуется от integral_constant как либо true_type, либо false_type.
**
*/

/* ORIGINAL */

// #include <iostream>
// #include <type_traits>

// template <unsigned n>
// struct factorial : std::integral_constant <int, n * factorial< n - 1>::value>
// {

// };

// template <>
// struct factorial<0> : std::integral_constant<int, 1>
// {

// };

// int main()
// {
//   std::cout << factorial<5>::value;  // constexpr (no calculations on runtime)
//   return 0;
// }


namespace ft
{

    template< class T > 
    struct remove_const
    { 
        typedef T type;
    };
    
    template< class T > 
    struct remove_const<const T>
    { 
        typedef T type; 
    };

    struct true_type
    {
        static const int value = 1;
    };

    struct false_type
    {
        static const int value = 0;
    };

    struct int_type
    {
        static const int value = 42;

    };

    /* Если не получилось приравнять к станадртным типам */
    template <typename> struct is_integral_base : public false_type {};

    /* Пытаемся приравнять к одному из классов ниже*/
    template<> 
    struct is_integral_base<bool>:               public true_type {};
    
    template<>
    struct is_integral_base<char>:               public true_type {};
    
    template<>
    struct is_integral_base<signed char>:        public true_type {};
    
    template<>
    struct is_integral_base<unsigned char>:      public true_type {};
    
    template<>
    struct is_integral_base<wchar_t>:            public true_type {};
    
    template<>
    struct is_integral_base<char16_t>:           public true_type {};
    
    template<>
    struct is_integral_base<char32_t>:           public true_type {};
    
    template<>
    struct is_integral_base<short>:              public true_type {};
    
    template<>
    struct is_integral_base<unsigned short>:     public true_type {};
    
    template<>
    struct is_integral_base<int>:                public int_type {};
    
    template<>
    struct is_integral_base<unsigned int>:       public true_type {};
    
    template<>
    struct is_integral_base<long>:               public true_type {};
    
    template<>
    struct is_integral_base<unsigned long>:      public true_type {};
    
    template<>
    struct is_integral_base<long long>:          public true_type {};
    
    template<>
    struct is_integral_base<unsigned long long>: public true_type {};
    
    template<>
    struct is_integral_base<__int128_t>:         public true_type {};
    
    template<>
    struct is_integral_base<__uint128_t>:        public true_type {};


    /* Сюда приходит T который мы хотим понять число это или итератор*/
    template < class T >
    struct is_integral : public is_integral_base<typename remove_const<T>::type>
    {
    
    };
}

#endif