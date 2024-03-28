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
                    //^ 참조계수 증가 X. 가리키던 곳이 파괴되었는지 조사할 수 없음.
                    //^ dangleing pointer 가능성 O.
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));

    // block 을 벗어나면서 sp2 가 해지됨.
    {
	    std::shared_ptr<People> sp2(new People("lee"));

	    sp1->bf = sp2.get();
	    sp2->bf = sp1.get();
    }

    if (sp1->bf != 0) {
        auto name = sp1->bf->name;
    }
}


