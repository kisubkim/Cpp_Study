// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// 가상한수 override시 virtual을 붙이든 말든 상관없다.
	virtual void foo() {}
	// void foo() {} 위 코드와 동일, 가독성 위해 붙이는 것이 좋다.

	// 가상함수 override때 오타가 있어도, 에러가 아님.
	virtual void fooo() {}     // 그냥 다른 함수 -> 버그의 원인이 되기 쉽다.
	virtual void goo(double){} // 오버로드

	// c++ 11부터 virtual 대신 override 키워드가 추가되었다.
	virtual void fooo()      override {}     // 그냥 다른 함수 -> 버그의 원인이 되기 쉽다.
	virtual void goo(double) override {}     // 오버로드

};

int main()
{
}





