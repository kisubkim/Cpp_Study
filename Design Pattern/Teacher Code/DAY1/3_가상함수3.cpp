// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
	void test() {}
};
class Derived : public Base
{
public:
	// 1. 가상함수 override할 때, virtual은 있어도 되고, 없어도 문제 없음.
	virtual void foo() {}	// 요거와 void foo() 는 완전히 동일한 code임.
							// 다만 가독성을 위해서 붙이면 좋기는 함.

	// 2. 가상함수 재정의시 실수(오타)가 있어도...
	// ==> Error 아님
	// ==> 다른 함수를 추가한 것으로 처리됨.
	// virtual void fooo() {}
	// virtual void goo(double){}


	// 3. 위 문제가 많은 버그의 원인이 됨.
	// ==> 그래서 c++11에서 override 키워드 추가
	virtual void fooo() override {}			// 새로운 함수가 아닌
	virtual void goo(double) override {}	// override 하는 것이라고 알려주는 것.
	void test() override{}
};

int main()
{
}





