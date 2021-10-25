#include "stdafx.h"

#include <iostream>
#include <unordered_map>

#include "MyHash.h"
MyHash::MyHash()
{
}


MyHash::~MyHash()
{
}

int MyHash::hashfunc(const std::string & first)
{
	if (bucket.capacity() == 0)
	{
		bucket.resize(10);
	}
	//std::cout << *first.c_str() % bucket.capacity() << std::endl;
	return *first.c_str() % bucket.capacity();
}

void MyHash::INSERT(const std::pair<std::string, int>& hashPair)
{
	int index = hashfunc(hashPair.first);

	if (bucket[index].empty() != true)
	{
		for (auto & it : bucket[index])
		{
			if (it.first == hashPair.first)
			{
				it.second = hashPair.second;
				return;
			}
		}	
	}
	
	hashValue temp;
	temp.first = hashPair.first;
	temp.second = hashPair.second;
	bucket[index].push_back(temp);
}

void MyHash::ERASE(const std::string & key)
{
	int index = hashfunc(key);

	if (bucket[index].empty() != true)
	{
		for (auto it = bucket[index].begin(); it != bucket[index].end(); ++it)
		{
			if (it->first == key)
			{
				bucket[index].erase(it);
				return;
			}
		}
		printf("NOTHING\n");
		return;
	}
	return;
}

std::list<hashValue>::iterator MyHash::FIND(const std::string & key)
{
	int index = hashfunc(key);
	if (bucket[index].empty() != true)
	{
		for (auto it = bucket[index].begin(); it != bucket[index].end(); ++it)
		{
			if (it->first == key)
			{
				return it;
			}
		}
		bool errorCase = 0;
		throw errorCase;
		//return ;
	}
	//return;
}

void MyHash::PRINT()
{
	if (bucket.empty() == true) return;

	for (int i = 0; i < bucket.size(); ++i)
	{
		if (bucket[i].empty() == true) continue;

		for (auto & it : bucket[i])
		{
			std::cout << it.first << ' ' << it.second << std::endl;
		}
	}
}

int main()
{
	std::unordered_map<int, int> test;
	for (int i = 0; i < test.bucket_count(); ++i)
	{
		test[i] = i * 10 + 1;
		std::cout << test.bucket(i) << ' ' << test.bucket_size(i) << std::endl;
		std::cout << test[i] << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < test.bucket_count(); ++i)
	{
		std::cout << test.bucket(i) << ' ' << test.bucket_size(i) << std::endl;
	}
	std::cout << std::endl;
	std::cout << test.bucket(0) << std::endl;
	std::cout << "bucket count :" << test.bucket_count() << std::endl;

	std::cout << std::endl;
	std::cout << "new" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 9; ++i)
	{
		test[i] = i;
		std::cout << test.bucket(i) << ' ' << test.bucket_size(i) << std::endl;
	}
	std::cout << std::endl;
	std::cout << test.bucket(0) << std::endl;
	std::cout << "bucket count :" << test.bucket_count() << std::endl;
	std::unordered_map<int, int>::iterator itt(test.begin());
	int a(10);

	/*MyHash hash;
	std::pair<std::string, int> temp;
	temp.first = "check";
	temp.second = 6;
	hash.INSERT(temp);
	hash.INSERT({"Check", 7});
	hash.INSERT({"china", 100});
	hash.PRINT();
	hash.ERASE("check");
	std::cout << std::endl;
	hash.PRINT();
	std::cout << hash.FIND("china")->second << std::endl;
	hash.FIND("china")->second = 85;
	std::cout << std::endl;
	hash.PRINT();
	try
	{
		std::cout << hash.FIND("case")->second << std::endl;
	}
	catch (bool errorCase)
	{
		printf("ERROR\n");
	}*/


	/*std::unordered_map<int, int> test;
	test[6] = 10;
	std::cout << test.find(3)->second << std::endl;*/
	//std::string temp = "5";
	//printf("%d",*temp.c_str());
	return 0;
}
