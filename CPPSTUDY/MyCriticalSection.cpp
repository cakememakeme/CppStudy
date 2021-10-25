#include "stdafx.h"
#include "MyCriticalSection.h"

#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include "myLock_Guard.h"
//#include "process.h"
//아토믹이 가장 빠르다고 한다.

//std::atomic atom; // ?
CRITICAL_SECTION g_cs;
std::vector<int> g_vec;
std::mutex mu;

MyCriticalSection myCrit;

void Test44()
{
	while (true)
	{
		{
			//std::lock_guard<std::mutex> lockl();			//???
			//mu.lock();
			//myCrit.LOCK();
			//myLock_Guard myGG();
			for (int i = 0; i < 10; i++)
			{
				std::cout << "넣는다" << g_vec.size() << ' ';
				g_vec.push_back(1);
			}
			//mu.unlock();
			//myCrit.UNLOCK();
		}
	}
}

void Test55()
{
	while (true)
	{
		{
			//std::lock_guard<std::mutex> locklock(mu);
			//mu.lock();
			//std::lock_guard<std::mutex> lockl(mu);			//???
			//myLock_Guard myGuard(myCrit);
			//myLock_Guard myG();
			for (int i = 0; i < g_vec.size(); i++)
			{
				std::cout << "지운다" << ' ';
				auto it = g_vec.begin();
				g_vec.erase(it);
			}
			//mu.unlock();
		}
	}
}

int main()
{
	std::thread th1(Test44);
	std::thread th2(Test55);
	while (true)
	{
		std::cout << std::endl;
	}
}