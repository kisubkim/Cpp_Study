// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"
/*
	Client 개발자는 "Server 개발자" 에게 2개의 파일을 받아와야 함.

	ICalc.h : Interface가 있는 Header
	CalcProcy.dll : Proxy가 담긴 동적 모듈 (Class가 미리 컴파일 된 것)
*/

/*
	Proxy Update 시 규칙
		1. DLL 의 이름을 변경하면 안됨. ("CalcProxy.dll" 유지)
		2. DLL 안에 "create" 가 있어야함.
*/

//


int main()
{
	ICalc* calc = load_proxy();

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
}
