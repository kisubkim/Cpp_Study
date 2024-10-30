/*
	실제 구현 계층
	Point의 모든 구현은 이 클래스에 구현.
*/

// PointImpl.h
class PointImpl
{
	int x, y;
public:
	void print();
};

//------------------------------------------------------------
// 
// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { } // 구현 생략


//------------------------------------------------------------
// 
// 
// 추상층 (Bridge)
//		=> 사용자가 실제 사용하는 클래스
//		=> 구현은 "PointImpl" 의존.
// 포인트를 사용할 때는 헤더없이도 포인트는 선언해서 사용이 가능함. ---> 클래스 전방선언.
// 
// Point.h
class PointImpl;		// 클래스 전방선언
						// Header file 없어도 포인터 변수는 선언가능
class Point
{
	PointImpl* impl;		// 구현을 가리키는 포인터.
public:
	Point();
	void print();
};

//------------------------------------------------------------
// 
// Point.cpp
#include "PointImpl.h"		// 여기서는 헤더 필요
#include "Point.h"

void Point::print() { impl = new PointImpl; } // 구현 생략
void Point::print() { impl->print(); }


//------------------------------------------------------------
// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}

/*
	위 기술이 컴파일 시간 Bridge Pattern.
	C++ 에서는 "PIMPL" 이라는 "C++ IDioms"로 부름.

		장점
			1. 컴파일 속도 향상 (컴파일 시간 방화력)
			2. 완벽한 정보 은닉 (구현의 헤도를 노출할 필요 없다.
								추상층의 헤더만 노출하면 된다.)

*/
