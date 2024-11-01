#include <iostream>
/*
	class �� memory �� �ö󰡸�
	member data �� �� class instance ���� ������ �ǰ�
	member function �� memory �� 1���� �ö� ����. (class ����� ���� �κп�)
		=> �׷��ٸ�, ������ �޸� �� �ִ� function �� ���ο��� ó���ϴ� x, y�� ��� 
		   instance �� x, y ���� �˱�??
			
		--> ���� �Ʒ� code ���� call Point::set(&p1, 10, 20) �� ���� ó���� this pointer �� �־ ����.
			("this call" �̶�� �θ�)
			
			void set (Point* this, int a, int b)
			{
				this->x = 0;
				this->y = 0; 
			}

			�� ���� �����.

			������ member function ���� ���� ���� ������� �ʴ� ���� �ִµ� �̳༮�� Static member function ��.
			Static �� compiler �� �������� �ʰ� �״�� �����.
			=> �� ���� ������ class ������ static function �� ��� class member data�� ������ �� ���ٴ� ��Ģ�� ����.
*/

class Point
{
	int x = 0;
	int y = 0;
public:
	void set(int a, int b)
	{
		x = 0;
		y = 0;
	}
};
int main()
{
	Point p1;
	Point p2;

	p1.set(10, 20);
}