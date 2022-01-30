#include "../STL/map/map1.hpp"
#include <iostream>
//#include <assert.h>
#include <map>

int main () {

	ft::map<int, char> map;
	ft::map<int, char> copy_map;
	ft::map<int, char> empty;
	ft::map<int, char> dup;

	for (int i = 0; i < 30; i++)
		map.insert(ft::make_pair(i, 'b'));

	for (int i = 0; i < 30; i++)
		dup.insert(ft::make_pair(i, 'a'));

	ft::map<int, char> copy_map2(map);
	copy_map = map;

	assert(map != dup);
	// assert(map == copy_map);
	// assert(map == copy_map2);
	// assert(map >= copy_map);
	// assert(map <= copy_map);
	// assert(map > empty);
	// assert(empty < map);
	

	// ft::map<int, char>::value_compare value_compare = map.value_comp();
	// assert(value_compare(ft::make_pair(4,'a'), ft::make_pair(5, 'b')));

	// ft::map<int, char>::key_compare key_compare = map.key_comp();
	// assert(key_compare(4, 6));

	// try
	// {
	// 	map.at(77) = 'l';
	// 	assert(0);
	// }
	// catch(...)
	// { }
	
	// assert(empty.empty());

	// for (int i = 0; i < 26; i++)
	// 	empty[i] = 'a' + i;

	
	// empty[0] = 'z';
	// assert('z' == empty[0]);
	// ft::map<int, char>::iterator it = empty.begin();

	// while(it != empty.end())
	// 	empty.erase(it++);
	
	// assert(empty.empty());
	
	// ft::pair<ft::map<int, char>::iterator, bool> PairItB;
	// ft::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator> PairItIt;

	// map.erase(map.begin(), map.end());

	// assert(map.empty());
	// assert(!copy_map.empty());

	// assert(copy_map.size() == 30);

	// ft::map<int, char>::iterator it1 = copy_map.find(25);
	// it = copy_map.find(5);


	// map.insert(it, it1);

	// it++;
	// it++;
	// it++;

	// PairItB = map.insert(*it);

	// assert(PairItB.second == false);
	// assert(PairItB.first == map.find(8));

	// it = copy_map.find(0);

	// PairItB = map.insert(*it);

	// assert(PairItB.second == true);
	// assert(!value_compare(*PairItB.first, *it));

	// it = map.find(5);
	// it1 = map.find(5);

	// assert(it == it1);
	// assert(map.size() == 21); 

	// it1 = map.find(8);

	// assert(it1 != map.end());
	// assert(it != map.end());
	// assert(key_compare(it->first, it1->first));

	// ft::map<int, char>::size_type count = 0;

	// for(ft::map<int, char>::iterator itt = it; itt != it1; itt++)
	// 	count++;

	// ft::map<int, char>::size_type size = map.size() - count;

	// it = map.erase(it, it1);

	// assert(it == map.find(8));
	// assert(map.size() == size);

	// map.clear();

	// it = map.begin();

	// map[0] = 'a';
	// map[1] = 'b';
	// map[2] = 'c';
	// map[3] = 'd';

	// it--;

	// map[4] = 'e';
	// assert(it->second == map[3]);
	// assert(it++ != map.end());
	// assert(++it == map.end());
	

	// // Если эти значения не совпадают со стандартным это не является ошибкой, просто разные модели
	// // распределения памяти для одной ноды
	// std::cout << map.max_size() << std::endl;
	// std::map<int, char> stdmap;
	// std::cout << stdmap.max_size() << std::endl;

	// map.clear();
	// copy_map.clear();
	// copy_map2.clear();
	// empty.clear();

	// char a = 'a';
	// for (int i = 0; i < 75; i += 3, a++)
	// 	map[i] = a, stdmap[i] = a;

	// assert(map.lower_bound(4)->first == stdmap.lower_bound(4)->first);
	// assert(map.upper_bound(30)->first == stdmap.upper_bound(30)->first);

	// PairItIt = map.equal_range(47);

	// assert(map.equal_range(47).first->first == stdmap.equal_range(47).first->first);
	// assert(map.equal_range(47).second->first == stdmap.equal_range(47).second->first);

	// ft::map<int, char>::reverse_iterator rit(map.rbegin());
	// ft::map<int, char>::const_reverse_iterator crit = map.rbegin();

	// size = 0;

	// for (; rit != map.rend(); rit++)
	// 	size++;
	// assert(map.size() == size);

	// size = 0;
	// for (; crit != map.rend(); crit++)
	// 	size++;
	// assert(map.size() == size);

	// it = rit.base();
	// rit--;
	// rit->second = 'S';
	// assert(it == map.begin());
	// return (0);
}