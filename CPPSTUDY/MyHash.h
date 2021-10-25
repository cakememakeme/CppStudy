#pragma once
#include <list>
#include <string>
#include <vector>

//template<typename TF, typename TS>
struct hashValue
{
	std::string first;
	int second = 0;
};

//template<typename TF, typename TS>
class MyHash
{
private:
	int numOfHash = 0;
	std::vector<std::list<hashValue>> bucket;
	int hashfunc(const std::string & first);

public:
	class iterator
	{
	private:
		hashValue * currentHash; // ????????
	public:
		iterator(hashValue * iter)
			: currentHash(iter) { }
		iterator();
		~iterator();
		//inline iterator operator= (const MyTree & tree)
		//{
		//	currentPtr = tree;
		//}
		//inline iterator operator++ ()
		//{
		//	
		//}
		//inline iterator operator++ (const iterator & iter)
		//{
		//	
		//}
		//inline iterator operator-- ()
		//{
		//	
		//}
		//inline iterator operator-- (const iterator & iter)
		//{
		//	
		//}
	};
public:
	MyHash();
	~MyHash();
	std::list<hashValue>::iterator FIND(const std::string & first);
	//int BUCKET(TF key)
	//int BUCKET_COUNT()
	//int BUCKET_SIZE(TF key)
	//int COUNT(const TF & key);
	//inline int SIZE()
	//{
	//	return numOfHash;
	//}
	//bool EMPTY();
	void INSERT(const std::pair<std::string, int> & pairTest);
	//void INSERT(const std::pair<??, ??> & pairTest);
	void ERASE(const std::string & key);
	//void ERASE(const TF & key);
	//void CLEAR();
	//void RESERVE(int bucketSize);
	//void SWAP(MyHash right);
	void PRINT();
	/*inline TS & operator[] (const TF & key)
	{
		hashValue<TF, TS> * targetPtr = ...;
		if (targetPtr == nullptr)
		{
			INSERT({ key, 0 });
			targetPtr = ...;
		}
		return targetPtr->second;
	}*/
};

