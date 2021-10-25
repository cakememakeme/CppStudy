#include "stdafx.h"

#include <iostream>
#include <map>
#include <stack>

#include "MyTree.h"

template<typename TyF, typename TyS>
constexpr void SAFE_DELETE(NODE<TyF, TyS> * targetPtr)
{
	if (targetPtr != nullptr) delete targetPtr;
	targetPtr = nullptr;
}

//const int& MyTree::operator[](int idx)
//{
//	if (rootPtr == nullptr)	return 0;
//
//	NODE * tourPtr = rootPtr;
//	while (1)
//	{
//		if (tourPtr == nullptr)	return 0;
//			
//		if (tourPtr->first == idx)
//		{
//			return tourPtr->second;
//		}
//		if (idx < tourPtr->first)
//		{
//			tourPtr = tourPtr->leftptr;
//		}
//		else if (tourPtr->first < idx)
//		{
//			tourPtr = tourPtr->rightptr;
//		}
//	}
//}


//template<typename TyF, typename TyS>
//void MyTree<TyF, TyS>::INSERT(const std::pair<TyF, TyS>& pairValue)
//{
//
//}

template<typename TyF, typename TyS>
NODE<TyF, TyS>* MyTree<TyF, TyS>::_find(const TyF & first)const
{
	if (_rootPtr == nullptr) return nullptr;
	NODE<TyF, TyS> * tourPtr = _rootPtr;
	while (1)
	{
		if (tourPtr == nullptr)	return nullptr;

		if (first == tourPtr->first) //if HIT
		{
			return tourPtr;
		}

		else if (first < tourPtr->first)
		{
			tourPtr = tourPtr->leftptr;
		}
		else if (tourPtr->first < first)
		{
			tourPtr = tourPtr->rightptr;
		}
	}
}

template<typename TyF, typename TyS>
MyTree<TyF, TyS>::MyTree()
{
}

template<typename TyF, typename TyS>
MyTree<TyF, TyS>::~MyTree()
{
}

template<typename TyF, typename TyS>
void MyTree<TyF, TyS>::INSERT(const std::pair<TyF, TyS>& pairValue)
{
	if (_rootPtr == nullptr)
	{
		_rootPtr = new NODE<TyF, TyS>;
		_rootPtr->first = pairValue.first;
		_rootPtr->second = pairValue.second;
		_rootPtr->leftptr = nullptr;
		_rootPtr->rightptr = nullptr;
		++_numOfNode;
	}
	else
	{
		NODE<TyF, TyS> * tourPtr = _rootPtr;
		while (1)
		{
			if (tourPtr->first < pairValue.first && tourPtr->rightptr == nullptr)
			{
				NODE<TyF, TyS> * madeNode = _makeNode(pairValue);
				tourPtr->rightptr = madeNode;
				++_numOfNode;
				break;
			}
			else if ((pairValue.first < tourPtr->first && tourPtr->leftptr == nullptr))
			{
				NODE<TyF, TyS> * madeNode = _makeNode(pairValue);
				tourPtr->leftptr = madeNode;
				++_numOfNode;
				break;
			}

			if (pairValue.first == tourPtr->first)
			{
				tourPtr->second = pairValue.second;
				break;
			}
			else if (pairValue.first < tourPtr->first)
			{
				tourPtr = tourPtr->leftptr;
			}
			else if (tourPtr->first < pairValue.first)
			{
				tourPtr = tourPtr->rightptr;
			}
		}
	}
}

//template<typename TyS>
//void MyTree<TyF, TyS>::INSERT(const std::pair<std::string, TyS>& pairValue)
//{
//
//}

template<typename TyF, typename TyS>
void MyTree<TyF, TyS>::ERASE(const TyF & key)
{
	if(_rootPtr == nullptr) return;
	
	NODE<TyF, TyS> * tourPtr = _rootPtr;
	NODE<TyF, TyS> * parentPtr = nullptr;
	bool isParentLegLeft = true;
	
	if (_rootPtr->first == key)
	{
		if (_rootPtr->leftptr == nullptr)
		{
			_rootPtr = _rootPtr->rightptr;
		}
		else
		{
			_rootPtr = _rootPtr->leftptr;
		}
	}
	
	while (1)
	{
		if (tourPtr == nullptr) return;

		if (key == tourPtr->first) //if HIT
		{
			NODE<TyF, TyS> * leftChildPtr = tourPtr->leftptr;
			NODE<TyF, TyS> * rightChildPtr = tourPtr->rightptr;
			
			//부모 노드에 대한 상속은 hit노드의 왼쪽 노드가 받는다
			//없으면 오른쪽 노드가 이어받는다
			if (parentPtr != nullptr) 
			{
				if (isParentLegLeft == true)
				{
					leftChildPtr != nullptr ? parentPtr->leftptr = leftChildPtr : parentPtr->leftptr = rightChildPtr;
				}
				else
				{
					leftChildPtr != nullptr ? parentPtr->rightptr = leftChildPtr : parentPtr->rightptr = rightChildPtr;
				}
			}

			if (leftChildPtr != nullptr)
			{
				while (leftChildPtr->rightptr != nullptr)
				{
					leftChildPtr = leftChildPtr->rightptr;
				}
				leftChildPtr->rightptr = rightChildPtr;
			}
				
			tourPtr->first = 0;
			tourPtr->second = 0;
			SAFE_DELETE(tourPtr);
			--_numOfNode;
			return;
		}

		else if (key < tourPtr->first)
		{
			parentPtr = nullptr;
			parentPtr = tourPtr;
			isParentLegLeft = true;
			tourPtr = tourPtr->leftptr;
		}
		else if (tourPtr->first < key)
		{
			parentPtr = nullptr;
			parentPtr = tourPtr;
			isParentLegLeft = false;
			tourPtr = tourPtr->rightptr;
		}
	}
}

template<typename TyF, typename TyS>
void MyTree<TyF, TyS>::CLEAR()
{

}

template<typename TyF, typename TyS>
void MyTree<TyF, TyS>::MYPRINT()
{
	if (_rootPtr == nullptr) return;

	NODE<TyF, TyS> * tourPtr = _rootPtr;
	std::stack<NODE<TyF, TyS>*> printStack;
	printStack.push(_rootPtr);
	while (!printStack.empty())
	{
		std::cout << printStack.top()->first << ' ' << printStack.top()->second << std::endl;
		NODE<TyF, TyS> * temp = printStack.top();
		printStack.pop();
		if (temp->rightptr != nullptr)
			printStack.push(temp->rightptr);
		if (temp->leftptr != nullptr)
			printStack.push(temp->leftptr);
	}
}

template<typename TyF, typename TyS>
typename MyTree<TyF, TyS>::iterator MyTree<TyF, TyS>::BEGIN()
{
	if (_rootPtr == nullptr) return nullptr;

	typename MyTree<TyF, TyS>::iterator it;
	it.currentPtr = _rootPtr;
	//it->
	return it;
}

//
//template<typename TyF, typename TyS>
//MyTree<TyF, TyS>::iterator * MyTree<TyF, TyS>::BEGIN()
//{
//	if (_rootPtr == nullptr) return nullptr;
//
//	_head = _rootPtr;
//	MyTree<TyF, TyS>::iterator it;
//
//	return it;
//}

int main()
{
	std::map<std::string, int> test;
	std::pair<std::string, int> pairT = { "test0", 5 };
	test.insert(pairT);
	test.insert({ "check", 7 });
	//std::cout << sizeof(test["test0"]) << std::endl;
	////test.at();
	//test.begin();
	//test.end();
	//test.emplace();
	//test.max_size();
	////test.upper_bound();
	////test.lower_bound();
	//test.key_comp();
	//test.value_comp();
	
	
	MyTree<int, double > tree;
	//std::pair<std::string, double> pairTest;
	//pairTest.first = "test0";
	//pairTest.second = 8.4;
	//tree.INSERT(pairTest);
	tree.INSERT({ 6, 7.2 });
	tree.INSERT({ 5, 7.2 });
	tree.INSERT({ 10, 7.2 });
	tree.INSERT({ 0, 7.2 });
	//tree.operator[](6) = 0.5;
	tree[6] = 5.5;
	std::cout << tree[11] << std::endl;

	//tree.ERASE(6);
	//MyTree<int, double> testTree;
	//testTree.INSERT({ 5, 9.7 });
	//tree.SWAP(testTree);
	tree.MYPRINT();
	//std::cout << tree.SIZE() << std::endl;
	//testTree.MYPRINT();


	////MyTree<int, double>::iterator it;
	////std::map<std::string, int>::iterator itt;
	////it = tree.BEGIN();
	////itt = test.begin();
	//std::cout << std::endl;
	//std::string tmp = { "whyy" };
	//std::cout << tmp << std::endl;
	////std::cout << itt->first << "why" << std::endl;
	////std::cout << *itt-> << std::endl;
	//std::cout << std::endl << std::endl;
	//std::cout << it.currentPtr->first << ' ' << it.currentPtr->second << std::endl;


	//std::cout << test.at(5);
	//it = tree.AT(6);
	/*pairTest.first = 2;
	pairTest.second = 6;
	tree.INSERT(pairTest);
	pairTest.first = 4;
	pairTest.second = 2;
	tree.INSERT(pairTest);
	pairTest.first = 3;
	pairTest.second = 1;
	tree.INSERT(pairTest);
	pairTest.first = -1;
	pairTest.second = 0;
	tree.INSERT(pairTest);
	pairTest.first = 5;
	pairTest.second = 6;
	tree.INSERT(pairTest);
	pairTest.first = 9;
	pairTest.second = 1;
	tree.INSERT(pairTest);
	pairTest.first = 7;
	pairTest.second = 10;
	tree.INSERT(pairTest);
	pairTest.first = 10;
	pairTest.second = 0;
	tree.INSERT(pairTest);
	pairTest.first = -2;
	pairTest.second = 0;
	tree.INSERT(pairTest);
	pairTest.first = 0;
	pairTest.second = 0;
	tree.INSERT(pairTest);*/
	//tree.operator=(15);
	//tree[15] = 3;
	//tree.PRINT();
	//tree.ERASE(-1);
	//std::cout << std::endl;
	//tree.MYPRINT();
	
	//std::cout << tree[7] << ' ' << tree[11] << std::endl;
	return 0;
}