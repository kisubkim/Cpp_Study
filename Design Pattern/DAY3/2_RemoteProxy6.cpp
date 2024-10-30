// 5번 복사해오세요
// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc1 = load_proxy();

	calc1->AddRef();		// 규칙 1. Proxy를 생성한 후는 참조계수 증가.

	ICalc* calc2 = calc1;
	calc2->AddRef();		// 규칙 2. Proxy Pointer 복사하면 참조계수 증가

	calc1->Release();		// 규칙 3. 더이상 포인터 사용하지 않으면 참조계수 감소

	std::cout << "---------------------" << std::endl;

	calc2->Release();		// 여기서 Procy가 delte

	std::cout << "---------------------" << std::endl;
}
