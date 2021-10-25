#pragma once

//메모리풀 메모리계산만 잘하면 된다.
//메모리풀도 만들어보자.
//

template <typename OBJ, uint32_t SIZE>
class VectorObjPool
{
public:
	VectorObjPool();
	~VectorObjPool();
	OBJ* GetObject();
	void ReturnObject(OBJ* obj);
	uint32_t GetSize();

private:
	void MemAlloc();
	void DelArrObj(OBJ* obj);

private:
	std::queue<OBJ*> m_freeList; //얘도직접구현
	std::vector<OBJ*> m_objArr;	//벡터말고동적배열
	uint32_t m_size;
};

template <typename OBJ, uint32_t SIZE>
VectorObjPool<OBJ, SIZE>::VectorObjPool()
{
	if (SIZE <= 0)
	{
		throw std::invalid_argument("0 이하는 ㄴㄴ");
	}
	MemAlloc();
}

template<typename OBJ, uint32_t SIZE>
VectorObjPool<OBJ, SIZE>::~VectorObjPool()
{
	for (auto& it : m_objArr)
	{
		DelArrObj(it);
	}
}

template <typename OBJ, uint32_t SIZE>
void VectorObjPool<OBJ, SIZE>::MemAlloc()
{
	OBJ* newObjects = new OBJ[SIZE];
	//OBJ* newObjects = new OBJ;
	m_objArr.push_back(newObjects);
	for (int i = 0; i < SIZE; ++i) {
		m_freeList.push(&newObjects[i]);
	}
}

template <typename OBJ, uint32_t SIZE>
void VectorObjPool<OBJ, SIZE>::DelArrObj(OBJ* obj)
{
	delete[] obj;
}

template <typename OBJ, uint32_t SIZE>
OBJ* VectorObjPool<OBJ, SIZE>::GetObject()
{
	if (m_size >= SIZE)
	{
		throw std::out_of_range("초과!");
	}
	++m_size;
	if (m_freeList.empty()) {
		MemAlloc();
	}
	OBJ* obj = m_freeList.front();
	m_freeList.pop();
	return obj;
}

template <typename OBJ, uint32_t SIZE>
void VectorObjPool<OBJ, SIZE>::ReturnObject(OBJ* obj)
{
	--m_size;
	m_freeList.push(obj);
}

template<typename OBJ, uint32_t SIZE>
inline uint32_t VectorObjPool<OBJ, SIZE>::GetSize()
{
	return m_size;
}
