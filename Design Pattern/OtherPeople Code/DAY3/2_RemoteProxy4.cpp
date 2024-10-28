// Client 제작자는 서버제작자에게 2개의 파일을 받아야 합니다.

// ICalc.h       : 인터페이스가 있는 헤드
// CalcProxy.dll : Proxy 기계어 코드가 있는 동적모듈

#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	// dll delete또한 header가 지원해야함.
	
	std::cout << n1 << ", " << n2 << std::endl;

}


