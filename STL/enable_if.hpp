#ifndef FT42_ENABLE_IF_H__
# define FT42_ENABLE_IF_H__

namespace ft
{

    template<bool B, class T = void>
    struct enable_if
    {

    };
    
    template<class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
}

#endif