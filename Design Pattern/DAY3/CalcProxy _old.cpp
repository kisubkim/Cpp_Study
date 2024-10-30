#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"


// ICalc.h 만들고 아래 interface 추가

class Calc : public ICalc {
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }
	int Add(int a, int b) override { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) override { return ec_send_server(server, 2, a, b); }
};

/*
	dll 을 가져다가 쓰는 사람들은 내부에서 사용되는 class 이름을 알면 안됨.
	즉, new 해서 할당하는 내용이 dll 내부에 있어야함.

	DLL 안에 있는 Proxy class name은 Client 개발자가 알 수 없고, 알 필요도 없고, 사용해도 안됨.(강한 결합)
	DLL 내부에 약속된 함수를 만들고, 그 안에서 객체를 생성해야함.
*/

extern "C" __declspec(dllexport)		// DLL 안에 함수 만들 때 필요.
ICalc* create() {
	return new Calc;
}


/*
	새로운 Procy DLL을 만들 때도 규칙("create" 함수가 있어야 한다는)을 지켜야 함. 

	DLL 을 만들어 보자. (★★중요★★)
	C++ Compiler
		Llinux 용 : g++
		Windows 용 Visual Studio Compiler : cl.exe
			Windows 시작 > 검색에서 developer command 검색해서 실행
			현재 소스가 있는 곳으로 이동.
			cl CalcProcy.cpp /LD => LD가 DLL로 빌드하라는 option임.
*/

/*
	다른 건 몰라도..이거 dll 규측관련해서는 잘 기억하도록 하자. 결국 binary 로 배포할 때 기존에 제공하던
	getInstance() 이거가 create() 이거 있어야 한다는 거랑 유사한 부분임.

	마찬가지로 나중에 cfg 사용해서 dll 내부에서 class 같은 거를 변경할 수도 있음.

	위 규칙을 잘 사용하면 header 포함하게 해서 engine 변경될 때마다 build 다시 할 필요 없음.
*/