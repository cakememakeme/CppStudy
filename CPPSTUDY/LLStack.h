#pragma once

#define SAFE_DELETE(Mem) if (Mem != nullptr) delete Mem; Mem = nullptr;

template <typename OBJ>
struct NODE
{
	OBJ value;
	NODE* upNode;
};

template <typename OBJ>
class LLStack
{
public:
	LLStack();
	~LLStack();
	bool Empty();
	void Push(OBJ PushValue);
	void Pop();
	OBJ Top();
	uint64_t Size();
private:
	NODE<OBJ>* m_rootNode = nullptr;
	uint64_t m_stackSize = 0;
};

template<typename OBJ>
inline LLStack<OBJ>::LLStack()
{
}

template<typename OBJ>
LLStack<OBJ>::~LLStack()
{
	while (m_rootNode != nullptr)
	{
		Pop();
	}
}

template<typename OBJ>
void LLStack<OBJ>::Push(OBJ PushValue)
{
	if (nullptr == m_rootNode) //reserve 시에, 이 조건을 어떻게 처리해야?
	{
		m_rootNode = new NODE<OBJ>;
		m_rootNode->value = PushValue;
		m_rootNode->upNode = nullptr;
	}
	else
	{
		NODE<OBJ>* makeNode = new NODE<OBJ>;
		makeNode->value = PushValue;
		makeNode->upNode = nullptr;

		NODE<OBJ>* tourNode = m_rootNode;
		while (tourNode->upNode != nullptr)
		{
			tourNode = tourNode->upNode;
		}
		tourNode->upNode = makeNode;
	}
	++m_stackSize;
}

template<typename OBJ>
void LLStack<OBJ>::Pop()
{
	if (m_rootNode == nullptr) return;

	NODE<OBJ>* tourNode = m_rootNode;
	NODE<OBJ>* preNode = m_rootNode;
	while (tourNode->upNode != nullptr)
	{
		preNode = tourNode;
		tourNode = tourNode->upNode;
	}
	SAFE_DELETE(tourNode);
	preNode->upNode = nullptr;
	if (m_stackSize == 1)
	{
		m_rootNode = nullptr;
	}
	--m_stackSize;
}

template<typename OBJ>
bool LLStack<OBJ>::Empty()
{
	if (m_rootNode != nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<typename OBJ>
OBJ LLStack<OBJ>::Top()
{
	if (m_rootNode == nullptr) return OBJ();

	NODE<OBJ>* tourNode = m_rootNode;
	while (tourNode->upNode != nullptr) {
		tourNode = tourNode->upNode;
	}
	return tourNode->value;
}

template<typename OBJ>
uint64_t LLStack<OBJ>::Size()
{
	return m_stackSize;
}