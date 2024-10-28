// 7 page
#include <iostream>
using namespace std;
class Animal
{
public:
	int age;
	virtual ~Animal() {} // 가상 소멸자 => 다음 시간에 계속..
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Animal a;
	Dog d;

	Animal* pa = &a;
	//dynamic casting - type을 runtime에 알아볼까
	//static casting - 컴파일타임에 코드에 따라 컴파일러가 타입이 맞는지 조사하지 않고 무조건 허용 -> 실행 시 overhead 0

	Dog* p = static_cast<Dog*>(pa); // = Dog* p = (Dog*)(pa);
	cout << pa << endl;
	cout << p << endl;

	// p->color = 22; // error undefined
	
	Dog* p1 = dynamic_cast<Dog*>(pa); // static으로 허락받지 않아서 일단은 에러. -> 가상함수 상속이 없기에 가상함수 테이블 참조로 타입을 알 수 없음. 가상함수 파트에서 확인쓰

	cout << p1 << endl; // 타입이 잘못되어 주소가 0으로 나와보린다
}