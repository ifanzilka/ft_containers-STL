#ifndef FT_XTREE
# define FT_XTREE

#include "../utils/pair.hpp"

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


// namespace ft
// {
//     // template <class Tr>
//     // class Tree;
//     // /* Параметры для дерева */
//     // struct tree_traits
//     // {
//     //     typedef T1  key_type;           /* Ключ в каждом элементе*/
//     //     typedef T2  value_type;         /* Тип значения в каждом элементе*/
//     //     typedef T3  allocator_type;     /* Аллокатор */
//     // };

//     /* Tree traits map/set  */
//     template <class Tree_traits>
//     class Tree_nod: public Tree_traits //Наследуем различные Параметры 
//     {
//         protected:
//         typedef typename Tree_traits::allocator_type    allocator_type;
// 		typedef typename Tree_traits::key_compare       key_compare;
// 		typedef typename Tree_traits::key_type	        key_type;
// 		typedef typename Tree_traits::value_compare	    value_compare;
// 		typedef typename Tree_traits::value_type		value_type;
		
//         /* Заменяем аллокатор чтобы было удобней рабоать */
//         typedef typename allocator_type::template       rebind<void>::other::pointer	Tree_ptr;

//         struct Node;
//         friend struct Node;

//         struct Node
//         {
//             /* Указатель на родителя, на левую часть, и на правую */
//             Tree_ptr    Left;
//             Tree_ptr    Parent;
//             Tree_ptr    Right;

//             value_type  Value;
//             char Color, Isnil;
//         };

//         Tree_nod(const key_compare & Parg, allocator_type Al): Tree_traits(Parg),  Alnode(Al)
//         {

//         };

// 		typename allocator_type::template  rebind<Node>::other Alnode;

//     };

//     template <class Tree_traits>
// 	class Tree_ptr : public Tree_nod<Tree_traits>
//     {
// 	protected:
// 		typedef typename Tree_nod<Tree_traits>::Node    Node;
// 		typedef typename Tree_traits::allocator_type    allocator_type;
// 		typedef typename Tree_traits::key_compare		key_compare;
		
//         typedef typename allocator_type::template       rebind<Node>::other::pointer	    nodeptr;
//         typedef typename allocator_type::template       rebind<Node>::other::const_pointer	const_nodeptr;


// 		Tree_ptr(const key_compare& Parg, allocator_type Al):Tree_nod<Tree_traits>(Parg, Al)
//         {

//         }
// 	};

//     /* Класс для хранения обьекта распределителя */
//     template <class Tree_traits>
// 	class Tree_val : public Tree_ptr<Tree_traits>
//     {
// 	protected:
// 		typedef typename Tree_traits::allocator_type    allocator_type;
// 		typedef typename Tree_traits::key_compare       key_compare;
        
		
//         Tree_val(const key_compare& Parg, allocator_type Al): Tree_ptr<Tree_traits>(Parg, Al), Alval(Al)
//         {

//         }
// 		allocator_type Alval;
// 	};
    

//     template <class Tree_traits>
//     class Tree : public Tree_val<Tree_traits>
//     {
//     public:
//         typedef Tree<Tree_traits>       Myt;
//         typedef Tree_val<Tree_traits>   Mybase;

//         typedef typename Tree_traits::key_type				    key_type;
// 		typedef typename Tree_traits::key_compare			    key_compare;
// 		typedef typename Tree_traits::value_compare		        value_compare;
//         typedef typename Tree_traits::value_type			    value_type;
// 		typedef typename Tree_traits::allocator_type		    allocator_type;
//         typedef typename allocator_type::size_type              size_type;
    

//         typedef typename allocator_type::template       rebind<Node>::other::pointer	Nodeptr;

//         /* Constructor */
//         Tree(const key_compare &Parg, allocator_type Al): Tree_value<Tree_traits>(Parg, Al)
//         {
// 		    //Init();
// 		};
		
//         /* Constructor */
// 		template <class It>
// 		Tree (const key_compare & Parg, allocator_type Al, It F, It L): Tree_value<Tree_traits>(Parg, Al)
//         {
// 		    //Init();
// 			//insert(F, L);
// 		};

//         /* Destructor */
// 		~xtree()
//         {
// 		    //AllFree(Root);
// 		    //FreeNode(NIL);
// 		};















//     protected:
//         typedef typename Tree_nod<Tree_traits>::Tree_ptr        Tree_ptr;
//         typedef typename Tree_nod<Tree_traits>::Node            Node;
//         enum RedBl {RED, BLACK};
//         //typedef typename allocator_type::template rebind::<Node>::





//     private:
//         Nodeptr		Leaf;
// 		Nodeptr 	Root;
// 		Nodeptr 	Begin;
		
//         size_type	Size;





//         void Init()
//         {
// 			Leaf = BuyNode();
// 			Leaf->Left = NIL;
// 			Leaf->Right = NIL;
// 			Leaf->Parent = NIL;
// 			Colour(Leaf) = Paint::Black;
// 			Root = NIL;
// 			Begin = NIL;
// 			Size = 0;
// 		}








//     };

// };



#include "../iterator/iterator.hpp"
#include "../utils/lexicographical_compare.hpp"

#define NIL Leaf

#define LEFT		1
#define RIGHT		2
#define ROOT		0
#define NOTCHILD	3


namespace ft
{

	template <class tree_traits>
		class iterator_pointers;

	template <class tree_traits>
		class tree_const_iterator;

	template <class tree_traits>
		class tree_iterator;
		
	template <class tree_traits>
	class xtree_node : public tree_traits
	{
		public:
			typedef typename tree_traits::allocator_type	allocator_type;
			typedef typename tree_traits::key_compare		key_compare;
			typedef typename tree_traits::key_type			key_type;
			typedef typename tree_traits::value_compare		value_compare;
			typedef typename tree_traits::value_type		value_type;
			typedef typename allocator_type::template 		rebind<void>::other::pointer	link_pointer;
			
			enum Palette {Red, Black};
			
			struct  Node
			{
				link_pointer Left, Parent, Right;
				value_type Value;
				Palette colour;
			};

			xtree_node (const key_compare & Parg, allocator_type Al): tree_traits(Parg), Alnode(Al)
			{

			};
			typename allocator_type::template rebind<Node>::other Alnode;
	};

	template <class tree_traits>
	class xtree_ptr : public xtree_node<tree_traits>
	{
		protected:
			typedef typename xtree_node<tree_traits>::Node				Node;
			typedef typename xtree_node<tree_traits>::allocator_type 	allocator_type;
			typedef typename xtree_node<tree_traits>::key_compare		key_compare;

			typedef typename allocator_type::template					rebind<Node>::other::pointer	nodeptr;

			typedef typename allocator_type::template					rebind<Node>::other::const_pointer	const_nodeptr;

			xtree_ptr(const key_compare& Parg, allocator_type Al):xtree_node<tree_traits>(Parg, Al)
			{

			}
		
	};

	template <class tree_traits>
	class xtree_value : public xtree_ptr<tree_traits>
	{
		protected:
			typedef typename tree_traits::allocator_type	allocator_type;
			typedef typename tree_traits::key_compare		key_compare;
			
			xtree_value(const key_compare& Parg, allocator_type Al): xtree_ptr<tree_traits>(Parg, Al), Alval(Al)
			{

			}
			allocator_type Alval;
	};

	template <class tree_traits>
	class xtree: public xtree_value<tree_traits>
	{
		public:
			typedef typename tree_traits::key_type					key_type;
			typedef typename tree_traits::key_compare				key_compare;
			typedef typename tree_traits::value_type				value_type;
			typedef typename tree_traits::allocator_type			allocator_type;
			typedef typename allocator_type::size_type				size_type;

			typedef typename xtree_node<tree_traits>::link_pointer	link_pointer;
			typedef typename xtree_ptr<tree_traits>::nodeptr		nodeptr;
			typedef typename xtree_ptr<tree_traits>::const_nodeptr	const_nodeptr;

			typedef typename xtree_node<tree_traits>::Palette		Palette;
			typedef xtree_node<tree_traits>							Paint;
			typedef typename xtree_node<tree_traits>::Node			Node;

			xtree(const key_compare &Parg, allocator_type Al):xtree_value<tree_traits>(Parg, Al)
			{
				Init();
			};
			
			template <class It>
			xtree (const key_compare & Parg, allocator_type Al, It F, It L): xtree_value<tree_traits>(Parg, Al)
			{
				Init();
				insert(F, L);
			};

			~xtree()
			{
				AllFree(Root);
				FreeNode(NIL);
			};
				/* Вспомогательные функции */
		protected:
				value_type&			Value(const nodeptr &node) const;
				value_type&			Value(const nodeptr &node);
				Palette&			Colour(const nodeptr &node);
				nodeptr				Left(const nodeptr &node) const;
				nodeptr				Right(const nodeptr &node) const;
				nodeptr				Left(const nodeptr &node);
				nodeptr				Right(const nodeptr &node);
				nodeptr				Parent(const nodeptr &node);
				nodeptr				Grandfather(const nodeptr &node);
				int					WhichChild(const nodeptr &node);
				nodeptr				Uncle(const nodeptr &node);
				nodeptr				Brother(const nodeptr &node);
				nodeptr				Min(nodeptr node);
				nodeptr				Max(nodeptr node) ;
				nodeptr				Rmost(nodeptr node);
				nodeptr				Lmost(nodeptr node);
				key_type			Key(nodeptr node) const;
				key_type			Key(const value_type& V) const ;
				void				RotateLeft (nodeptr node);
				void				RotateRight(nodeptr node);
				void				FixInsertion(nodeptr node);
				void				FixDelete(nodeptr node);
				nodeptr				FindRoot(nodeptr node);
		
		public:
				// Выводим граф на печать работает только c простыми типами и с объектами для которых определен оператор вывода в поток 
				void PrintGraphSet ();
				void PrintSubtreeSet(nodeptr Root, const std::string& prefix, bool tumbler);
				void PrintGraphMap ();
				void PrintSubtree(nodeptr Root, const std::string& prefix, bool tumbler);
				// Конец


			typedef typename allocator_type::difference_type Dift;
			typedef Dift difference_type;
			
			typedef typename allocator_type::template	rebind<value_type>::other::pointer 			Tptr;
			typedef typename allocator_type::template	rebind<value_type>::other::const_pointer 	Ctptr;
			typedef typename allocator_type::template	rebind<value_type>::other::reference 		Reft;
			
			typedef Tptr	pointer;
			typedef Ctptr	const_pointer;
			typedef Reft	reference;
			typedef typename allocator_type::template	rebind<value_type>::other::const_reference 	const_reference;
			
			typedef tree_const_iterator<tree_traits> 	const_iterator;
			typedef tree_iterator<tree_traits>			iterator;

			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
				

		private:

			typedef ft::pair<iterator, bool>					Pairib;
			typedef ft::pair<iterator, iterator>				Pairii;
			typedef ft::pair<const_iterator, const_iterator>	Paircc;

			public:

				iterator begin()
				{
					return(iterator(Lmost(Root)));
				}

				const_iterator begin() const
				{
					return(const_iterator(Begin));
				}

				iterator end()
				{
					return (iterator(NIL));
				}

				const_iterator end() const
				{
					return (const_iterator(NIL));
				}

				reverse_iterator rbegin()
				{
					return (reverse_iterator(end()));
				}

				reverse_iterator rend()
				{
					return (reverse_iterator(begin()));
				}

				const_reverse_iterator rbegin() const
				{
					return (const_reverse_iterator(end()));
				}

				const_reverse_iterator rend() const
				{
					return (const_reverse_iterator(begin()));
				}

				size_type max_size() const
				{
					return (this->Alnode.max_size());
				}

				size_type size() const
				{
					return (Size);
				}

				bool empty() const
				{
					return (size() == 0);
				}
			
			ft::pair<iterator, bool> insert(const value_type& V)
			{
				nodeptr node = BuyNode();
				if (Root == NIL) {
					Root = node;
					Colour(Root) = Paint::Black;
					ConstructV(Root, V);
					Leaf->Right = Root;
					Begin = Root;
					Size++;
					return Pairib(iterator(Root), true);
				}
					
				nodeptr tmp = Root;

				while (tmp != NIL)
				{
					if (this->comp(Key(V), Key(tmp))){
						if (Left(tmp) == NIL) {
							tmp->Left = node;
							node->Parent = tmp;
							ConstructV(node, V);
							break;
						};
						tmp = Left(tmp);
					} else if (this->comp(Key(tmp), Key(V))) {
						if (Right(tmp) == NIL) {
							tmp->Right = node;
							node->Parent = tmp;
							ConstructV(node, V);
							break;
						};
						tmp = Right(tmp);
					} else {
						FreeNode(node);
						return Pairib(iterator(tmp), false);
					}
				}

				FixInsertion(node);
				Begin = Lmost(Root);
				Size++;
				return Pairib(iterator(node), true);
			}

			template <class It>
			void insert(It F, It L)
			{
				for(; F != L; ++F)
					insert(*F);
			}

			iterator upper_bound(const key_type& K)
			{
				iterator it(begin());

				for (; it != end(); it++) {
					if (this->comp(K, Key(*it)))
						break;
				}

				return (it);
			}

			iterator lower_bound(const key_type& K)
			{
				iterator it(begin());

				for (; it != end(); it++) {
					if (this->comp(K, Key(*it)) || 
						(!this->comp(K, Key(*it)) && !this->comp(Key(*it), K)))
						break;
				}

				return (it);
			}
			const_iterator upper_bound(const key_type& K) const 
			{
				iterator it(begin());

				for (; it != end(); it++) {
					if (this->comp(K, Key(*it)))
						break;
				}

				return (it);
			}

			ft::pair<iterator, iterator> equal_range(const key_type & K)
			{
				return (Pairii(lower_bound(K), upper_bound(K)));
			}

			ft::pair<const_iterator, const_iterator> equal_range(const key_type & K) const
			{
				return (Paircc(lower_bound(K), upper_bound(K)));
			}

			const_iterator lower_bound(const key_type& K) const
			{
				iterator it(begin());

				for (; it != end(); it++) {
					if (this->comp(K, Key(*it)) || 
						(!this->comp(K, Key(*it)) && !this->comp(Key(*it), K)))
						break;
				}

				return (it);
			}

			size_type	erase(const key_type& V) ;  // size_type // должен принимать key_type
			iterator	erase(const const_iterator &P);
			iterator	erase(const_iterator F, const_iterator L);

			void		clear()
			{
				erase(begin(), end());
				Size = 0;
			};

			iterator find(const key_type& V)
			{
				return (iterator(Find(V)));
			}

			const_iterator find(const key_type& V) const {
				return (const_iterator(Find(V)));
			}

			void swap(xtree& X)
			{
				ft::swap(this->Root, X.Root);
				ft::swap(this->Leaf, X.Leaf);
				ft::swap(this->Size, X.Size);
				ft::swap(this->Begin, X.Begin);
			}

			private:

			nodeptr Find(const key_type & V) const
			{
				nodeptr out = Root;

				while (out != NIL)
				{
					if (this->comp(Key(out), V)) {
						out = Right(out);
					} else if (this->comp(V, Key(out))) {
						out = Left(out);
					} else {
						break ;
					}
				}
				return (out);
			}

			void Init()
			{
					Leaf = BuyNode();
					Leaf->Left = NIL;
					Leaf->Right = NIL;
					Leaf->Parent = NIL;
					Colour(Leaf) = Paint::Black;
					Root = NIL;
					Begin = NIL;
					Size = 0;
			}

			nodeptr BuyNode()
			{
				nodeptr out = this->Alnode.allocate(1);

				out->Left = NIL;
				out->Right = NIL;
				out->Parent = NIL;
				Colour(out) = Paint::Red;
				return (out);
			}

			void ConstructV(nodeptr &node, value_type V)
			{
				try {
				this->Alval.construct(&Value(node), V);
				} catch (...) {
					FreeNode(node);
					throw ;
				}
			}

			void FreeNode(const nodeptr &node)
			{
				this->Alnode.deallocate(node, 1);
			}

			void DestructValue(const nodeptr &node)
			{
				this->Alval.destroy(&Value(node));
			}

			void AllFree(const nodeptr &node)
			{
				if (node == NIL)
					return ;
					AllFree(Left(node));
					AllFree(Right(node));
					DestructValue(node);
					FreeNode(node);
			}
		
				nodeptr		Leaf;
				nodeptr 	Root;
				nodeptr 	Begin;
				size_type	Size;
		};

			template <class It1, class It2>
			bool operator == (const It1& X, const It2& Y)
			{
				return (X.Ptr == Y.Ptr);
			}

			template <class It1, class It2>
			bool operator != (const It1& X, const It2& Y)
			{
				return (!(X == Y));
			};
}




























#endif