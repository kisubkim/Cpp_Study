#include <string>
#include <iostream>
#include <memory>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	//std::shared_ptr<People> bf;
    //People *bf;

	//^ 소유권이 없는 smart pointer
	//^ 참조계수 증가 X, 객체 파괴 여부 확인 O
	std::weak_ptr<People> bf;
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));

    {
	    std::shared_ptr<People> sp2(new People("lee"));

	    sp1->bf = sp2;
	    sp2->bf = sp1;
    }

    if (sp1->bf.expired()) {
        std::cout << "객체 파괴됨\n";
    }
	else {
		// 파괴되지 않은 경우.
		//auto name = sp1->bf->name;		//& error 남. weak_ptr은 객체에 접근이 불가
		//& wp 가 사용하다가 data 가 날라갈 수 있어서 wp로 객체 접근은 불가
		//& weak_ptr 은 실제로는 shared_ptr의 control_block 의 특정 부분을 가리킴.
		
		
		// weak_ptr 을 사용 -> shared_ptr 을 다시 하나 생성 -> 접근
		std::shared_ptr<People> sp = sp1->bf.lock();		// weak_ptr 의 lock() 은 실제 mutex 사용해서 lock 함. (파괴를 막기 위해)
		//^ 하지만 weak_ptr이 lock 하기 직전에 sp2가 파괴될 수도 있음. 그래서 아래에서 if () 사용해서 확인함.
		// 위의 bf.expired() 는 실제로 필요가 없음.

		// 다시 sp 확인 후 사용.
		if (sp)
		{
			// sp 사용
			auto name = sp->name;
		}
	}

	//& shared_ptr 에서 객체가 파괴되는 순간 : 참조계수가 0일 때
	//& shared_ptr 에서 관리 객체가 파괴되는 순간 : 객체가 파괴되고, weak_ptr 도 없을 때.
	//& 	==> shared_ptr 의 weak_ptr을 관리하는 참조계수도 있다는 이야기.

	//* std::make_shaerd() 로 memory 할당을 하게 되면 객체와 관리객체가 동시에 할당.
	//*   ==> 파괴되는 시점은 관리 객체가 파괴되는 시점임.
	//*   ==> 객체는 메모리할당이 해지되지는 않지만, 소멸자가 호출은 된 상태로 남아 있을 수 있음.
	std::shared_ptr<People> sp = sp1->bf.lock();		// weak_ptr 의 lock() 은 실제 mutex 사용해서 lock 함. (파괴를 막기 위해)
	if (sp)
	{
		// sp 사용
		auto name = sp->name;
	}

}


