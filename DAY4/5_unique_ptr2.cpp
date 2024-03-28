#include <memory>
#include <iostream>

//^ shared_ptr : 자원을 공유할 수 있는 smart pointer
//^ weak_ptr   : 소유권이 없는 smart pointer
//^ unique_ptr : 자원을 독점하는 smart pointer

int main()
{
	std::unique_ptr<int> up1(new int); // ok
	//std::unique_ptr<int> up2 = up1;	// error
	std::unique_ptr<int> up2 = std::move(up1);	// ok

	std::unique_ptr<int> up3 = std::make_unique<int>();

	std::cout << sizeof(up1) << std::endl;		// raw pointer 와 동일한 크기.
}
