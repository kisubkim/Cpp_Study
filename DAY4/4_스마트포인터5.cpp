#include <iostream>
#include <memory>


void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
	// 아래 코드는 동적 메모리 할당을 몇번하게 될까요 ?
	//? 2번의 메모리 할당. Point 할당. 참조계수 할당.
	//^ 1. new Point(1, 0);
	//^ 2. shared_ptr 의 costructor 에서 new control_block() - 참조계수
	//std::shared_ptr<Point> sp(new Point(1, 2));		//& 이렇게 사용하면 memory 할당이 떨어져서 생성되어 비효율!!

	//^ std::make_shared()
	//^ 1. operator new ( sizeof(Point) + sizeof(control_block) ) 으로 한번에 할당
	//^ 2. new (객체부분의 주소) Point (1,2); 로 생성자 호출 후
	//^ 3. std::shared_ptr 을 만들어서 반환.
	//& std::make_shared() 사용하게 되면 사용하는 memory 용량이 줄어듬. (보통은 8byte 줄어듬.)
	std::shared_ptr<Point> sp = std::make_shared<Point>(1,2);

	//^ std::make_shared() 의 장점
	//^ 1. 효율적인 메모리 사용 (객체 + 관리객체 한번에 할당)
	//^ 2. 안정성 향상 (RAII 기술)

	// B, A, C 순서로 실행되면 안전
	foo(std::shared_ptr<int>(new int), goo());
	//           A               B        C
	// c++20 이전은 함수 내부 인자에서 각자 호출되는 순서는 없었음.

	//& resource 를 획득했으면 관리 객체한테 빨리 넘겨!!
	//^ 위 code => 자원의 할당, 자원 관리 객체의 생성이 분리
	//^         -> 안전 X
	//^  => 결론적으로 자원과 자원 관리 객체의 생성은 한번에 같이!
	foo(std::make_shared<int>(), goo());
}

void foo( std::shared_ptr<int> sp, int n) {}

int goo() { return 10; }

