// 5번 복사해오세요
// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// c++ 표준에 있는 std::shared_ptr 을 사용하면 아니되나요??

int main()
{
	std::shared_ptr<ICalc> p1(load_prox());
	// p1의 소멸자에서 "delete" 함.
	// 즉, DLL에서 new 한 것을 exe 에서 delete 한 case가 되어버림.
	// 우리가 원하는 것은 delete 가 니라 Release() 호출임.

	sp<ICalc> p2(load_prox());
	// p2는 소멸자에서 "보관된포인터->Release()" 호출
	// 즉, DLL 내부에서 delete

	/*
		그래서, C++ 표준에 스마트 포인터가 이미 있지만 위와 같은 이유로 많은 오픈소스가 자신만의 스마트 포인터를 만들어 사용.
	*/
	
}
