#ifndef _FT42ITERATOR_TAG
# define _FT42ITERATOR_TAG

namespace ft
{	
	struct input_iterator_tag;
	struct output_iterator_tag;
	struct forward_iterator_tag;
	struct bidirectional_iterator_tag;
	struct random_access_iterator_tag;
	typedef long int ptrdiff_t ;

struct output_iterator_tag{};

struct input_iterator_tag {};

/* Однонаправленный */
struct forward_iterator_tag 
	: public input_iterator_tag {};

/* Можно итерироваться назад */
struct bidirectional_iterator_tag
	: public forward_iterator_tag {};

/* Хоть как можно */
struct random_access_iterator_tag
	: public bidirectional_iterator_tag {};
	
	template <class It>
		struct iterator_traits ;
	
	template <class T>
		struct iterator_traits<T *> ;

	template <class RanIt>
		class reverse_iterator;

	template <class C>
		class back_insert_iterator ;
	
	template <class C>
		class front_insert_iterator ;

	template <class C>
		class insert_iterator ;
}

#endif