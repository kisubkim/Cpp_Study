#include <iostream>
#include <memory>

class Car
{
public:
	void Go() {}
	~Car() {std::cout << "~Car" << std::endl;	}
};
int main()
{
	std::shared_ptr<Car> sp;
	std::weak_ptr<Car>   wp;
	{
		//std::shared_ptr<Car> p(new Car);
        std::shared_ptr<Car> p = std::make_shared<Car>();
        //* 아...이거 소멸자는 호출이 도고, 메모리만 나중에 해제구나..
	
		//sp = p; 
		wp = p; 
		
		std::cout << p.use_count() << std::endl; // 
	}

	std::cout << "------" << std::endl;
}

