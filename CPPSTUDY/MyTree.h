#pragma once
#include <utility>
#include <string>

template <typename TyF, typename TyS>
struct NODE
{
	TyF first = 0;
	TyS second = 0;
	NODE * leftptr = nullptr;
	NODE * rightptr = nullptr;
};

template <typename TyF, typename TyS>
class MyTree
{
private:
	NODE<TyF, TyS> * _rootPtr = nullptr;
	NODE<TyF, TyS> * _head = nullptr;
	NODE<TyF, TyS> * _tail = nullptr;
	unsigned int _numOfNode = 0;

private:
	inline NODE<TyF, TyS> * _makeNode(const std::pair<TyF, TyS> & pairValue)
	{
		NODE<TyF, TyS> * makePtr = new NODE<TyF, TyS>;
		makePtr->first = pairValue.first;
		makePtr->second = pairValue.second;
		makePtr->leftptr = nullptr;
		makePtr->rightptr = nullptr;
		return makePtr;
	}
	NODE<TyF, TyS> * _find(const TyF & first)const;

public:
	//class iterator;
	//template <typename TyF, typename TyS>
	class iterator
	{
		//friend class MyTree<TyF, TyS>;
	private:
	public:
		NODE<TyF, TyS> * currentPtr = nullptr;
		iterator(NODE<TyF, TyS> * iter)
			: currentPtr(iter) { }
		iterator();
		~iterator();
		inline TyF& operator*()
		{
			return currentPtr->first;
		}
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
	MyTree();
	~MyTree();

	inline int AT(TyF first)
	{
		int at = _find(first)->second;
		return at;
	}
	inline int COUNT(TyF & first)
	{
		NODE<TyF, TyS> checker = _find(first);
		if (checker != nullptr)
		{
			return 1;
		}
	}
	inline int SIZE()
	{
		return _numOfNode;
	}
	inline bool EMPTY()
	{
		if (_rootPtr == nullptr) return true;
		else					return false;
	}
	inline void SWAP(MyTree & right)
	{
		MyTree temp(std::move(*this));
		*this = std::move(right);
		right = std::move(temp);
	}
	void INSERT(const std::pair<TyF, TyS> & pairValue);
	//void INSERT(const std::pair<TyF, TyS> & pairValue);
	void ERASE(const TyF & key);
	void CLEAR();
	void MYPRINT();
	iterator BEGIN();
	inline TyS& operator[] (const TyF & key)
	{
		NODE<TyF, TyS> * targetPtr = _find(key);
		if (targetPtr == nullptr)
		{
			INSERT({ key, 0 });
			targetPtr = _find(key);
		}
		return targetPtr->second;
	}
};

template<typename TyF, typename TyS>
inline MyTree<TyF, TyS>::iterator::iterator()
{
}

template<typename TyF, typename TyS>
inline MyTree<TyF, TyS>::iterator::~iterator()
{
}
