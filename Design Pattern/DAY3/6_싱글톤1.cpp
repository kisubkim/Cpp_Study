// 7_싱글톤1 - 123 page
#include <iostream>

/*
	싱글톤
		오직 한개의 객체만 존재하는 것.
		프로그램의 어디에서도 동일한 방법으로 접근이 가능.

	=> 결국 "전역변수(Global variable)" 와 유사.
	=> 그런데, 전ㄴ역변수는 좋지 않다고 배움.
	=> 그래서, Singleton Pattern도 비판이 많음.
*/


class Cursor
{
	// 규칙 1. 생성자를 private 에 놓음.
private:
	Cursor() {}

	// 규칙 2. 컴파일러가 복사생성자와 대입연산자를 만들지 못하게 해야함
	// => 함수 삭제 문법 (C++11에서 도입)
	Cursor(const Cursor&) = delete;				// 복사 생성자를 만들지 말라
	Cursor& operator=(const Cursor&) = delete;	// 관례상 복사를 금지하면 대입도 금지

	// 규칙 3. 오직 한개의 객체만 만들어서 반환하는 멤버 함수
public:
	static Cursor& get_instance() {
		static Cursor instance;		// 핵심 : static 지역변수. static으로 만들면 처음에 한번만 만들고, 다음에는 그냥 return 만 함.
		return instance;
	}
};


int main()
{
	// Cursor c1, c2;		// error. private 생성자.
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

	// ★유일하게 외부에서 선언할 수 있는 방법★
	// 복사 생성자
	//Cursor c3 = c1;		// 사용자가 만들지 않으면 컴파이러가 자동으로 만들어서 제공
						// Error 나오게 해야함.
}

/*
		위 code (singleton pattern) 는 "Mayer's singleton" 임.
			=> Effective C++ 책 저자인 "scott mayer가 처음 제안한 코드"
			=> 오직 한개의 객체를 "static 지역변수" 로 만든 것이 특징.
			=> 현재 알려진 다양한 방법 중에서 최선의 코드로 평가됨.
*/







