#include <string>
#include <iostream>
#include <memory>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	std::shared_ptr<People> bf;
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	std::shared_ptr<People> sp2(new People("lee"));

	//^ 아래처럼 쓰면 소멸자가 호출되지 않음. ==> 누수!! 왜??
	sp1->bf = sp2;
	sp2->bf = sp1;

	std::cout << sizeof(sp1) << std::endl;
	//? bf 가 shard_ptr 이 아닌 자원 People 객체를 가리킨다고함.. 진짜?? 확인해보자
	//^ 상호 참조, 원형 참조라고 함. (cycle reference)

}


