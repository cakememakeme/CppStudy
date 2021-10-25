#pragma once

template <typename OBJ, uint32_t SIZE>
class ListObjPool
{
public:
	ListObjPool();
	~ListObjPool();
	bool Empty();
	void Push(OBJ PushValue);
	void Pop();
	OBJ Top();
	uint64_t Size();
private:
	NODE<OBJ>* m_rootNode = nullptr;
	uint64_t m_stackSize = 0;
};

template<typename OBJ, uint32_t SIZE>
inline ListObjPool<OBJ, SIZE>::ListObjPool()
{
}

template<typename OBJ, uint32_t SIZE>
inline ListObjPool<OBJ, SIZE>::~ListObjPool()
{
}
