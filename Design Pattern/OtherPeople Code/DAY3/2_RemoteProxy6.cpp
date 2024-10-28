#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"


int main()
{
	ICalc* calc1 = load_proxy();

	calc1->AddRef(); // 규칙 1. 최초에 proxy 를 얻으면 참조 계수 증가

	ICalc* calc2 = calc1;
	calc2->AddRef(); // 규칙 2. proxy 의 포인터를 복사하면 참조 계수 증가


	calc2->Release(); // 규칙 3. 더이상 포인터를 사용하지 않으면 참조계수 감소

	std::cout << "--------------\n";

	calc1->Release(); // 결국, 이순간 proxy 객체 파괴 됩니다. 소멸자 호출

	std::cout << "--------------\n";

}

