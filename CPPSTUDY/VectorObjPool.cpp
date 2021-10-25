#include "stdafx.h"
#include <vector>
#include <queue>
#include "VectorObjPool.h"

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

class UserRequest
{
public:
	UserRequest() {}
	~UserRequest() {}

};

int a = 0;

UserRequest* obtainUserRequest(VectorObjPool<UserRequest, 100>& pool)
{
	UserRequest* request = pool.GetObject();
	++a;
	std::cout << "user request " << a << std::endl;
	return request;
}

void processUserRequest(VectorObjPool<UserRequest, 100>& pool, UserRequest* req)
{
	std::cout << "releaseObject" << std::endl;
	pool.ReturnObject(req);
}


int main()
{
	//VectorObjPool<UserRequest, 100> pool;

	//while (true) {
	//	UserRequest* req = obtainUserRequest(pool);
	//	//processUserRequest(pool, req);
	//}
	someMonster* melee1;
	someMonster* melee2;
	someMonster* melee3;
	someMonster* melee4;
	VectorObjPool<someMonster, 4> vecpool;
	melee1 = vecpool.GetObject();
	std::cout << vecpool.GetSize() << std::endl;
	melee2 = vecpool.GetObject();
	melee3 = vecpool.GetObject();
	std::cout << vecpool.GetSize() << std::endl;
	melee1->SetName("Orc");
	melee2->SetName("Badman");
	//melee1->SetName("Nothing");
	std::cout << melee1->GetName() << ' ' << melee2->GetName() << std::endl;
	vecpool.ReturnObject(melee1);
	vecpool.ReturnObject(melee2);
	std::cout << vecpool.GetSize() << std::endl;

	return 0;
}