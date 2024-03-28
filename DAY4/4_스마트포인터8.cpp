#include <string>
#include <iostream>
#include <memory>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	//std::shared_ptr<People> bf;

    People *bf;     // raw pointer 는 shared_ptr 의 참조계소에는 영향 X
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	std::shared_ptr<People> sp2(new People("lee"));

	sp1->bf = sp2.get();
	sp2->bf = sp1.get();

    //^ 안전하게 파괴는 되지만 문제가 있음.
    //^ 다음 문제에서 확인.
}


