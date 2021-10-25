#include "stdafx.h"
#include "LLStack.h"
#include "StackObjPool.h"
#include <string>

class someMonster
{
public:
	std::string GetName()
	{
		return m_name;
	}
	void SetName(std::string&& name)
	{
		m_name = name;
	}
private:
	std::string m_name;
};

int main()
{
	using ObjPool = StackObjPool<someMonster, 3>;//생성자에서
	someMonster* melee1;
	someMonster* melee2;
	someMonster* melee3;
	someMonster* melee4;
	melee2 = ObjPool::GetInstance()->GetObject();
	std::cout << ObjPool::GetInstance()->GetSize() << std::endl;
	melee1 = ObjPool::GetInstance()->GetObject();
	melee3 = ObjPool::GetInstance()->GetObject();
	//melee4 = ObjPool::GetInstance()->GetObject();
	std::cout << ObjPool::GetInstance()->GetSize() << std::endl;
	melee1->SetName("Orc");
	melee2->SetName("Badman");
	melee1->SetName("Orc");
	std::cout << melee1->GetName() << ' ' << melee2->GetName() << std::endl;
	std::cout << ObjPool::GetInstance()->GetSize() << std::endl;
	ObjPool::GetInstance()->ReturnObject(melee1);
	std::cout << ObjPool::GetInstance()->GetSize() << std::endl;
	ObjPool::GetInstance()->ReturnObject(melee2);
	std::cout << ObjPool::GetInstance()->GetSize() << std::endl;

	ObjPool::GetInstance()->Destory();

	return 0;
}