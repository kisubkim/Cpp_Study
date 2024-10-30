// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"


int main()
{
	ICalc* calc = load_proxy();
	// DLL 안에서 "new Calc" 하게 됨.
	// 사용 후 delete 해야 되지 않을까?

	int n1 = calc->Add(1, 2);

	delete calc;		// 이렇게 해도 될까??  ==> 결론 금지!! 위험함.
	// 

	/*
		만약에 server 개발자는 linux 에서 개발하고, client 개발자가 windows 에서 개발했다고 하면
		여기서 delete 하면 난리난다. 

		결론, 동적으로 할당을 하게 해주면 해준 놈이 delete 하도록 해야함. 즉, dll 내부에 해지하는
		내용이 들어가 있어야 함.

		강사님 주석
		DLL을 만들 때 사용한 컴파일러와 Client를 만들 때 사용한 compiler가 다를 수 있음.
		(동일 compiler도 version 이 다르면 문제 생김)
		DLL에서 new 한 것을 exe에서 delete 하는 것은 안전하지 않음.
		DLL에서 new 한 것은 DLL 이 delete 해야 함.
	*/

}
