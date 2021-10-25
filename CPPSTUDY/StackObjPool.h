#pragma once

//언젠가... 프리리스트 참고

template <typename OBJ, uint32_t SIZE>
class StackObjPool
{
public:
	static StackObjPool<OBJ, SIZE>* GetInstance();
	OBJ* GetObject();
	void ReturnObject(OBJ* object);
	uint32_t GetSize();
	void Destory();
	StackObjPool();
	~StackObjPool();
private:
	LLStack<OBJ*> m_stack;
	uint32_t m_size = 0;

	static StackObjPool* m_instance;
};

template <typename OBJ, uint32_t SIZE>
StackObjPool<OBJ, SIZE>* StackObjPool<OBJ, SIZE>::m_instance = nullptr;

template <typename OBJ, uint32_t SIZE>
StackObjPool<OBJ, SIZE>* StackObjPool<OBJ, SIZE>::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new StackObjPool<OBJ, SIZE>;
	}

	return m_instance;
}

template<typename OBJ, uint32_t SIZE>
OBJ* StackObjPool<OBJ, SIZE>::GetObject()
{
	if (m_size >= SIZE)
	{
		throw std::out_of_range("excess error!");
	}
	++m_size;
	if (m_stack.Empty() == true)
	{
		return new OBJ;
	}
	else
	{
		OBJ* objSource = m_stack.Top();
		m_stack.Pop();
		return objSource;
	}
}

template<typename OBJ, uint32_t SIZE>
void StackObjPool<OBJ, SIZE>::ReturnObject(OBJ* object)
{
	m_stack.Push(object);
	--m_size;
}

template<typename OBJ, uint32_t SIZE>
uint32_t StackObjPool<OBJ, SIZE>::GetSize()
{
	return m_size;
}

template <typename OBJ, uint32_t SIZE>
void StackObjPool<OBJ, SIZE>::Destory()
{
	if (m_instance != nullptr)
	{
		for (int i = m_size; i < 0; --i)
		{
			m_stack.Pop();
		}
		delete m_instance;
		m_instance = nullptr;
	}
}

template<typename OBJ, uint32_t SIZE>
inline StackObjPool<OBJ, SIZE>::StackObjPool()
{
}

template<typename OBJ, uint32_t SIZE>
inline StackObjPool<OBJ, SIZE>::~StackObjPool()
{
}