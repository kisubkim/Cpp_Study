#include <iostream>

class Counter
{
public:
	int cnt = 0;

	Counter& increment() //����Ÿ���� ����
	{
		++cnt;
		return *this;
	}
	~Counter() { std::cout << " �Ҹ�� \n "; }
};

int main()
{
	Counter c;
	c.increment().increment().increment().increment().increment().increment().increment(); // ��������������������������
	//c.increment();
	//c.increment().increment().increment().increment().increment().increment().increment().increment().increment();
	std::cout << c.cnt << std::endl;
}