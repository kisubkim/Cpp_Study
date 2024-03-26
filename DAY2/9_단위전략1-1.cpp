#include <iostream>
#include <mutex>
// multithread 관련 선택가능하게.
// 그리고 safe 하게 만들어 보자.


//^ 단위 전략 (Policy base design)
//^ => class가 사용하는 다양한 정책을 교체할 수 있게 하기 위해서
//^ => 템플릿인자로 정책을 담은 class를 전달하는 디자인 기법
//^ => 성능저하없이 교체 가능
//^ => C++ 진영에서 아주 널리 사용하는 기술
//^ => STL의 container가 대부분 이 디자인 사용.
// => STL은 이 디자인을 동기화를 위해 사용하지는 않음. 주로 web brower ㅇ서 사용

//& 주의 : STL의 List는 동기화를 고려해서 디자인 되지는 않았음.
// => 다른 용도로 이 기술 사용

//* 템플릿 인자도 default 값을 가질 수 있음.
template<typename T, typename ThreadModel = NoLock> class List
{	
	// 여기서 ThreadModel 이 lock, unlock 에서 뭘 하는지에 따라서 
	// 동작을 제어 가능함.
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		//..
		tm.unlock();
	}
};

//& 동기화 정책 클래스
//& => 규칙은 반드시 lock/unlock 이 있어야 함.

class NoLock{
	public:
		inline void lock() {}
		inline void unlock() {}
};

class MutexLock{
	std::mutex m;
	public:
		inline void lock() { m.lock(); std::cout<< "lock\n"; }
		inline void unlock() { m.unlock(); std::cout << "unlock\n"; }
};

List<int, NoLock> st1;	
//List<int> st1;			// 이것도 윗 문장과 동일한 효과.	
List<int, MutexLock> st2;	

int main()
{

	st1.push_front(10);

}


