#include <atomic>

int a = 0;
int b = 0;

//& code 상으로는 보장이 되는게 맞지만, compiler 가 어떻게 compile 되었는지에 따라
//& 안될 수도 있다. (최적화 때문에)

//^ 컴파일 최적화 시에 이전 code를 진행하지 않고, 아래 code 부터 처리할려고 하는 
//^ 작업을 막는 것이 fence 임.
//? 구글에서 "c++ dclp" 검색
//? 유툽에서 cppcon 에서 thread fence
// foo, goo 는 다른 스레드가 실행합니다.
void foo()
{
	a = b + 1;
	std::atomic_thread_fence(std::memory_order_seq_cst);		//^ 이렇게 되면, compile 시에 최적화로 인한 오류를 막을 수 있음.
	b = 1;
}

void goo()
{
	if (b == 1)
	{
		// a는 반드시 1일까요 ?
	}
}

int main()
{
}
