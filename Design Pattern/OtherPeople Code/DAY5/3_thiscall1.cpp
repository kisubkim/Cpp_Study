#include <iostream>

// �ٽ� : ��� �Լ��� ȣ������� ������ ���ô�.

// �ٽ� #1. ��� �Լ��� ���ڷ� "this" �� �߰��˴ϴ�. "this call" �̶�� �մϴ�.

// �ٽ� #2. static ��� �Լ��� "this"�� �߰����� �ʽ��ϴ�. �߿�!


class Point
{
	int x = 0;
	int y = 0;
public:
	void set(int a, int b) // void set( Point* this, int a, int b)
	{						// {
		x = a;				//		this->x = a;
		y = b;				//		this->y = b;
	}						// }

};
int main()
{
	Point p1;
	Point p2;

	p1.set(10, 20); // set(&p1, 10, 20) ���� ����˴ϴ�.
	p2.set(10, 20); // set(&p2, 10, 20)
}
