#include <iostream>
#include <mutex>

/*
	함수의 마지막 부분에서 자원 반납을 하면
		1. 중간에 예외가 나오면 함수 아래 부분이 실행 안됨.
		2. 실수 할 수 있음. (if 문에서 return 때린다든지..) --> 자원 반납하지 않고 돌아가는 경우 
	
	RAII IDiom
		=> 자원의 할당과 해지는 생성자/소멸자에 의존해야함.
		=> Resource Acquision Is (자원관리객체가) Initialization
		=> 핵심 : 소멸자에서 자원을 관리해라!!
*/

template<typename T> class lock_guard {
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock();	}
	~lock_guard() { mtx.unlock); }
};

class Cursor {
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;
	static std::mutex mtx;
public:
	/*
		일반적으로 함수 시작할 때 자원을 획득하고, 함수가 끝이 날 때 자원을 반납하는게 일반적인 개념임.
	*/

	static Cursor& get_instance() {
		{
			std::lock_guard<std::mutex> g(mtx);		// 1. g의 생성자에서 mtx.lock()
			// 2. 지역변수 g 파괴시 소멸자에서 mtx.unlock()
			// 장점
			//		1. 예외 발생해도 g의 소멸자는 호출하고 예외 핸들러로 이동
			//		2. 실수할 수 없음. g의 소멸자는 항상 호출됨.
//mtx.lock();
			if (sinstance == nullptr) {
				sinstance = new Cursor;
			}
		}
		//mtx.unlock();
		return *sinstance;
	}


};
std::mutex Cursor::mtx;
Cursor* Cursor::sinstance = nullptr;

int main()
{
	Cursor& c1 = Cursor::get_instance();

}








