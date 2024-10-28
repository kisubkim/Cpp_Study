#include <iostream>

class Counter
{
public:
	int cnt = 0;

	Counter& increment() //리턴타입이 값임
	{
		++cnt;
		return *this;
	}
	~Counter() { std::cout << " 소멸띠 \n "; }
};

int main()
{
	Counter c;
	c.increment().increment().increment().increment().increment().increment().increment(); // 오류오류오류오류오류오류섬
	//c.increment();
	//c.increment().increment().increment().increment().increment().increment().increment().increment().increment();
	std::cout << c.cnt << std::endl;
}