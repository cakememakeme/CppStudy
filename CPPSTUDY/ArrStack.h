#pragma once
template <typename T>
class ArrStack
{
public:
	ArrStack();
	~ArrStack();
	bool Empty();
	void Push(T& PushValue);
	void Pop();
	void Reserve(uint64_t& cap);
	T Top();
	uint64_t Size();
private:
	T* m_stackArr = nullptr;
	uint64_t m_capacity = 8;
	uint64_t m_stackSize = 0;
};

