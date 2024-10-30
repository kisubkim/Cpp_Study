// 7_싱글톤1 - 123 page
#include <iostream>


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:

	/*
		C++11(Java, C#) 부터 static 지역변수의 생성자 호출은 MultiThread 에 안전함.
		아래 code에서 "Threaad A"가 먼저 도착해서 생성자를 호출하고 있을 때 "Thread B" 가 도착하면 A의 생성자 호출이 종료될 때까지 대기.
			=> 머 결론적으로 동기화 된다는 이야기임.
			=> 반대로..11 이전에는 안전하지 않다는 이야기..

			=> 동기화 되는 방법은 "spin lock(busy waiting)" 임.
			=> 생각해보면 이거 해당 class(static으로 선언되는 class) 이거 생성자 내부에 code 부분들도 동기화 보장함. 즉, 호출하는 순서가
						lock();
						생성자();
						unlock();
			   과 같은 식으로 진행이 됨.
	*/
	static Cursor& get_instance() {
		static Cursor instance;
		return instance;
	}
};


int main()
{
	
}






