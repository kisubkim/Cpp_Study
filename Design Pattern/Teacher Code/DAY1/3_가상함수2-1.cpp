#include <iostream>

// 1. 기반 클래스의 소멸자는 기본적으로 virtual 이어야 함.
// 2. 그런데, virtual 함수가 있으면
//   ==> 가상함수 테이블이 메모리에 놓이게 됨. (메모리 사용량 ↑)
//   ==> 호출 시, 메모리 조사때문에 약간의 성능저하가 있음.
// 3. 아래 같은 코드가 없다면 소멸자를 virtual 로 하지 않아도 됨.
// Base* p = new Derived;
// delete p;	//	<---- 요부분
// 4. 3번처럼 사용했을 때 컴파일 에러나게 해보자!!
//    ==> protected 소멸자.

// 결국 이건 상위 클래스를 따로 사용하지 않을 때만 이렇게 사용하면 좋음.
// abstract 사용할 때 이 규칙은 중요할 듯함.

class Base
{
protected:
	~Base() {}
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	Base* p = new Derived;	
	delete p;		// 이 순간 가상소멸자가 아니므로 ~Base를 호출해야 하는데..
					// protected에 있어서 Error!

	delete static_cast<Derived*>(p);		// 이 code는 OK. 요건 ~Derived() 호출
}
