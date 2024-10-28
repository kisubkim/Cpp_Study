#include <iostream>

// 핵심 : "기반 클래스의 소멸자는 반드시 virtual" 이어야 함.
// 즉, 상속을 사용하면 최상위 또는 상위는 무조건 virtual 쓰도록 한다.

// 구글에서 c++ core guide line 검색
// 1번째 링크 --> c++ 창시자가 만들고 있는 "c++ 언어에서 지켜야 하는 규칙)

class Base
{
public:
	virtual ~Base() {}		// 가상 소멸자 문법
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	//Derived d;  // 아무 문제 없음

	//Derived* p = new Derived;		// 이 순간 생성자 호출
	//delete p;						// 이 순간 소멸자 호출. 아무 문제 없음.

	// 아래 code가 핵심. => 실행해서 결과를 보면 할당은 되는데 해지가 안됨.
	Base* p = new Derived;			// Derived 생성자 호출
	delete p;						// ?? 소멸자 호출 (Base의 소멸자만 호출됨.)
									// 이 때, Derived쪽에 다른 내용이 있으면 bug 가 될 수 있음.(정상적으로 소멸자가 호출이 되지 않았으니까..)

	// 소멸자 호출도 "함수 호출" 과정
	// => stattic binding 할지 dynamic binding 할지 정해야함.

	// static binding : pointer type으로 결정
	// dynamic binding : 실제 메모리에 있는 객체조사 후 결정.

	/*
		1. 컴파일러는 p가 base*라는 사실만 알 수 있음.
		2. 그래서 Base 클래스 선언을 조사해서 소멸자가 virtual 인지 조사
		3. base 소멸자가 virtual 아니면 static, virtual 이면 dynamic
		그래서 ~Derived() 가 아닌 ~Base() 만 호출됨. (왜? virtual 이 없었으니...)
	*/

}	
