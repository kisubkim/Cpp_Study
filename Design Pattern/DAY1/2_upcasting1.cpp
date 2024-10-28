// 7 page

class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Dog* p1 = &d; 
	int* p2 = &d;		// Error
	Animal* p3 = &d;	// 요게 upcasting


	/*
		핵심
		1. 기반 클래스 포인터에 파생 클래스 주소를 담을 수 있다. => upcasting
		   => 메모리 그림을 그려보면 이해가 쉬움.

		2. 컴파일러는 p3이 가리키는 곳에 실제 어떤 객체가 있는지 알 수 없다.
		   => 변수에 저장되는 부분은 실행 시간에 변경이 될 수 있음. 그래서 컴파일러가 확신할 수 없음
		   아래 code에서 p3 가 가리키는 곳은 실행시간에 변경될 수 있음.
		   따라서 컴파일러는 p3이 가리키는 곳에 어떤 객체가 있는지 알 수 없음
		   if (사용자 입력 == 1) p3 = &animal

		3. 기반 클래스로 파생클래스에 접근을 했으면 기반 클래스 멤버만 접근이 가능.
		   => 즉, Animal* 인 p3으로는 Animal 멤버만 저ㅂ근이 가능하고, Dog 고유 멤버는 접근이 안됨

		4. p3으로 Dog 고유 멤버에 접근 하려면 캐스팅 해야함. 이때 casting 하는 내용에 대해서 확신이 있어야함. 아니면 SW down됨.
		   => static_cast<Dog*>(p3)->color = 10
		  
	*/

}











