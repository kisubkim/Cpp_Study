// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	std::vector<Dog*>       v1; // 여기에는 또그만 들어갈수가 있는 상태인 것이다.
	std::vector<Animal*>    v2; // 여기에는 모오든 동물이 들어갈 수가 있는 상태인 것이다..
	                            // 동종( 같은 기반 크래스를 가진 타입 ) 을 보관하는 컨떼이너
}
