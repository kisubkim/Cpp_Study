// 5번 복사해오세요
// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

/*
	6번 예제처럼 포인터를 직접 사용하면
		=> 규칙이 어렵지는 않지만
			1. 지루한 코드 반복
			2. 실수 할 수 있음.(실수로 Release(), AddRef() 호출 생략)

	Proxy Pattern : 기존 것을 사용하지 말고, 대신할 것을 만들자는 것.
					"진짜 포인터"를 사용하지 말고 "대신할 것"을 만들어서 사용.
*/

template<typename T> class sp {
	T* obj;
public:
	sp(T* p = nullptr) : obj(p) { if (obj != nullptr) obj->AddRef(); }
	sp(const sp& other) : obj(other.obj) { if (obj != nullptr) obj->AddRef(); }

	~sp() { if (obj != nullptr) obj->Release(); }

	// sp를 진짜 포인터 처럼 -> 와 * 를 사용할 수 있게 하려면 아래와 같이 연산자 재정의 필요.
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};
// 위 sp 가 c++에서 유명한 "smart pointer" 임.
// SP는 "smart proxy" 임. 즉, proxy pattern (포인터의 대행자)
// 실제 "Android 내부 소스에 sp" 가 있음.

int main()
{
	//sp<ICalc> calc1 = load_proxy2();		// 이거 되어야 할 것 같은데..왜 안되는 건지 한번 확인은 필요할 것 같음.
	sp<ICalc> calc1 = load_proxy();		// sp<ICalc> calc1(load_proxy()) 와 같이 처리됨
	sp<ICalc> calc2 = calc1;

	int n = calc1->Add(10, 20);		// calc1은 포인터를 대신하므로 ->와 * 연산이 되어야함.
								    // "연산자 재정의" 문법으로 만들면 됨.

	std::cout << n << std::endl;
}

//int main()
//{
//	ICalc* calc1 = load_proxy();
//	calc1->AddRef();
//
//	ICalc* calc2 = calc1;
//	calc2->AddRef();
//	calc1->Release();
//
//	std::cout << "---------------------" << std::endl;
//	calc2->Release();
//	std::cout << "---------------------" << std::endl;
//}
