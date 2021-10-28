#include "FixedDeque.h"

#include <iostream>
#include <vector>
#include <deque>

#include <unordered_map>

int main()
{
	FixedDeque<int> fd(5);
	fd.PushBack(5);
	fd.PushFront(4);
	fd.PushBack(6);
	fd.PushFront(3);
	fd.PushBack(7);
	fd.Print();
	std::cout << fd.IsEmpty() << '\n';
	std::cout << fd.isFull() << '\n';
	return 0;
	std::deque<int> d;
	d.push_front(2);
	//d.em
	std::unordered_map<int, int> adbd;
	adbd.insert({1, 2});
	std::cout << adbd.at(1);
	//adbd.insert(3, 4);
	return 0;
}