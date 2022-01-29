#ifndef FT_XTREE
# define FT_XTREE

/*Page 518 */



/* Красно Черные Деревья
** 1) Корень всегда -> черный
** 2) конечные узлы тоже -> черные
** 3) Дочерние от красного -> черные
** 4) Все пуьт до NULL умеет одинаковое кол во черных узлов
*/ 

// struct dsdf
// {
//     static int b;
//     typedef int mytype;
// };

// template <class A>
// struct xtree
// {
//    typedef typename A::b kkk;
// };


namespace ft
{
    // template <class Tr>
    // class Tree;
    // /* Параметры для дерева */
    // struct tree_traits
    // {
    //     typedef T1  key_type;           /* Ключ в каждом элементе*/
    //     typedef T2  value_type;         /* Тип значения в каждом элементе*/
    //     typedef T3  allocator_type;     /* Аллокатор */
    // };

    /* Tree traits приходит из вне  */
    template <class Tree_traits>
    class Tree_nod: public Tree_traits //Наследуем различные Параметры 
    {
        protected:
        typedef typename Tree_traits::allocator_type    allocator_type;
		typedef typename Tree_traits::key_compare       key_compare;
		typedef typename Tree_traits::key_type	        key_type;
		typedef typename Tree_traits::value_compare	    value_compare;
		typedef typename Tree_traits::value_type		value_type;
		
        /* Заменяем аллокатор чтобы было удобней рабоать */
        typedef typename allocator_type::template       rebind<void>::other::pointer	Tree_ptr;

        struct Node;
        friend struct Node;

        struct Node
        {
            /* Указатель на родителя, на левую часть, и на правую */
            Tree_ptr    Left, Parent, Right;
            value_type  Value;
            char Color, Isnil;
        };

        Tree_nod(const key_compare & Parg, allocator_type Al): Tree_traits(Parg), Al    node(Al)
        {

        };

		typename allocator_type::template  rebind<Node>::other Alnode;

    };

    template <class Tree_traits>
	class Tree_ptr : public Tree_nod<Tree_traits>
    {
	protected:
		typedef typename Tree_nod<Tree_traits>::Node    Node;
		typedef typename Tree_traits::allocator_type    allocator_type;
		typedef typename Tree_traits::key_compare		key_compare;
		
        typedef typename allocator_type::template       rebind<Node>::other::pointer	    nodeptr;
        typedef typename allocator_type::template       rebind<Node>::other::const_pointer	const_nodeptr;


		Tree_ptr(const key_compare& Parg, allocator_type Al):Tree_nod<Tree_traits>(Parg, Al)
        {

        }
	};


    template <class Tree_traits>
	class Tree_val : public Tree_ptr<Tree_traits>
    {
	protected:
		typedef typename Tree_traits::allocator_type    allocator_type;
		typedef typename Tree_traits::key_compare       key_compare;
		
        Tree_val(const key_compare& Parg, allocator_type Al): Tree_ptr<Tree_traits>(Parg, Al), Alval(Al)
        {

        }
		allocator_type Alval;
	};
    

    template <class Tree_traits>
    class Tree : public Tree_val<Tree_traits>
    {
    public:
        typedef Tree<Tree_traits>       Myt;
        typedef Tree_val<Tree_traits>   Mybase;

        typedef typename Tree_traits::key_type				    key_type;
		typedef typename Tree_traits::key_compare			    key_compare;
		typedef typename Tree_traits::value_compare		        value_compare;
        typedef typename Tree_traits::value_type			    value_type;
		typedef typename Tree_traits::allocator_type		    allocator_type;
    
    protected:
        typedef typename Tree_nod<Tree_traits>::Tree_ptr        Tree_ptr;
        typedef typename Tree_nod<Tree_traits>::Node            Node;
        enum RedBl {RED, BLACK};
        //typedef typename allocator_type::template rebind::<Node>::

    };

};

#endif