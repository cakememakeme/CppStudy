#pragma once
#include <Windows.h>

class MyCriticalSection
{
private:
	CRITICAL_SECTION m_CritSec;
	bool isLock = false;
public:
	inline MyCriticalSection()
	{
		::InitializeCriticalSection(&m_CritSec);
	}
	inline ~MyCriticalSection()
	{
		::DeleteCriticalSection(&m_CritSec);
	}
	inline void LOCK()
	{
		::EnterCriticalSection(&m_CritSec);
	}
	inline void UNLOCK()
	{
		::LeaveCriticalSection(&m_CritSec);
		isLock = false;
	}
	inline bool TRY_LOCK()
	{
		if (isLock == true) return false;

		::EnterCriticalSection(&m_CritSec);
		return true;
	}
	MyCriticalSection(const MyCriticalSection&) = delete;
};