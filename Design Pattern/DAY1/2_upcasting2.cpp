// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	// upcasting 활용 #1	
	std::vector<Dog*>    v1;		// Dog 객체만 보관 가능한 컨테이너. 다른 동물은 불가.

	std::vector<Animal*> v2;		// 모든 동물 객체 보관 가능.
									// 동종(동일한 기반 클래스를 가지는 타임)을 보관하는 컨테이너.
}
