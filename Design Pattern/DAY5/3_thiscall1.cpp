#include <iostream>
/*
	class 가 memory 에 올라가면
	member data 는 각 class instance 별로 생성이 되고
	member function 은 memory 에 1개만 올라가 있음. (class 선언과 같은 부분에)
		=> 그렇다면, 실제로 메모리 상에 있는 function 은 내부에서 처리하는 x, y는 어느 
		   instance 의 x, y 인지 알까??
			
		--> 실제 아래 code 에서 call Point::set(&p1, 10, 20) 과 같이 처음에 this pointer 를 넣어서 보냄.
			("this call" 이라고 부름)
			
			void set (Point* this, int a, int b)
			{
				this->x = 0;
				this->y = 0; 
			}

			과 같이 변경됨.

			하지만 member function 에서 위와 같이 변경되지 않는 것이 있는데 이녀석이 Static member function 임.
			Static 은 compiler 가 변경하지 않고 그대로 사용함.
			=> 요 이유 때문에 class 내부의 static function 의 경우 class member data에 접근할 수 없다는 규칙이 생김.
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