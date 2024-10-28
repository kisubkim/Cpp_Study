#include <iostream>


// 오직 한개의 객체를 어느 메모리에 어떻게 만들것인가 ?

// #1. static 지역변수 - mayer's singleton

// #2. static 멤버 데이타

// #3. heap 

class Cursor
{
private:
	Cursor() { std::cout << "Cursor()\n"; }

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	//	Cursor instance; // error
	static Cursor instance; // ok

public:
	static Cursor& get_instance()
	{
//		static Cursor instance; 
		return instance;
	}
};
Cursor Cursor::instance; // C++ 에서는 static 멤버 데이타는 외부 정의 필요


int main()
{
	std::cout << "main\n";
	Cursor& c1 = Cursor::get_instance();
}

