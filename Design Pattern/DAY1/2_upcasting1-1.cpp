// 7 page

#include <iostream>

class Animal
{
public:
	int age;
	virtual void cry() {}
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
	Dog* p1 = &d;
	//Animal* p = &a;
	Animal* p = &d;

	Dog* dog = static_cast<Dog*>(p);
	// static cast : 컴파일 시간 캐스팅. 실행시 오버헤드 없음.
	//				 컴파일 시간에는 p가 가리키는 곳을 조사할 수 없음.
	//				 그래서 무조건 casting 이 성공함. (요거는 개발자 책임)
	// Dynamic cast : 런타임 시간. 실행 시 오버헤드 있음.
	//				  실행시간에 p가 가리키는 곳을 조사해서 Dog가 아니면 0 리턴.
	//				  class, structor에 가상함수가 있으면 가상함수 table에 해당 type에 대한 정보가 기록된다.
	//					즉, dynamic_cast를 사용하려면 "객체 어딘가에 타입정보를 기록해야 한다"
	//					c++은 가상함수 테이블에 타입 정보를 기록. 따라서 dynamic_cast는 가상함수가 있는 타입만 가능.

	std::cout << dog << std::endl;

	dog->color = 10;		// 만일 p가 가리키던 곳이 Dog가 아니면 이 코드는 Error나고 비정상 종료도 될 수 있음.

	Dog* dog2 = dynamic_cast<Dog*>(p);
	std::cout << dog2 << std::endl;

}











