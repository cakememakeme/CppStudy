#pragma once
#include "MyCriticalSection.h"

class myLock_Guard
{
private:
	MyCriticalSection& m_myCrit;
public:
	explicit inline myLock_Guard(MyCriticalSection& myCrit)
		: m_myCrit(myCrit)
	{
		m_myCrit.LOCK();
	}
	inline ~myLock_Guard()
	{
		m_myCrit.UNLOCK();
	}
	myLock_Guard(const myLock_Guard&) = delete;
};

