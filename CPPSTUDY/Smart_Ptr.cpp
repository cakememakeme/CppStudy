#include "stdafx.h"

#include <memory>

#include <windows.h>
#pragma comment(lib, "winmm.lib")

class ptrTest
{
public:
	inline void testshow()
	{
		printf("hi\n");
	}
	void plusa()
	{
		++a;
	}
	void showa()
	{
		printf("%d\n", a);
	}
private:
	int a = 0;
	int b = 0;
};

int main()
{
	//std::unique_ptr<ptrTest> test(new ptrTest);
	//test->testshow();
	unsigned long ptime = 0;
	unsigned long time = 0;
	timeBeginPeriod(1);
	//ptime = timeGetTime() + 1000;
	while (1)
	{
		time = timeGetTime();
		if(time <= ptime) continue;
		std::cout << time / 1000 << std::endl;
		ptime = timeGetTime() + 1000;
		//std::cout << time << std::endl;
	}
	Sleep(1);
	timeEndPeriod(1);
	return 0;

	std::unique_ptr<int> foo(new int);
	std::unique_ptr<ptrTest> utest(new ptrTest);
	utest->plusa();
	utest->plusa();
	utest->showa();
	std::unique_ptr<ptrTest> upptest;
	upptest->plusa();
	upptest->showa();
	//힙 내의 다른 인스턴스를 가지고 있다. 2, 1로 나타나는 것은 당연함.
	return 0;
	std::shared_ptr<int> upt(new int(100));
	std::shared_ptr<int> uptest(upt);
	printf("%d\n", *uptest);
	return 0;
	auto bar = *foo;
	auto& baz = foo;
	*foo = 2;
	auto test = &foo;
	std::cout << utest.get() << std::endl;
	// 포인터 출력
	std::cout << foo.get() << std::endl;
	std::cout << &bar << std::endl; // 컴파일러가 bar의 데이터 타입을 int로 추정
	std::cout << baz.get() << std::endl; // 참조자로 선언하고 정의했기 때문에 별 문제없이 출력된다.
	
										 // 객체 출력
	std::cout << *foo << std::endl; // 3
	std::cout << bar << std::endl; // 3
	std::cout << *baz << std::endl; // 3

	return 0;
}