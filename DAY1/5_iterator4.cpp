#include <iostream>
#include <list>   
#include <vector>

// 반복자 무효화
int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
	auto p = v.begin();

	std::cout << *p << std::endl;

	//v.resize(10);		// 새로운 memory 재할당 되니까..실제 p가 가리키던 memory는 유효 x --> iterator invalidata (반복자 무효화)
	v.resize(3);		// 작아지는 경우에는 memory 재할당 x. iterator invalidate 일어나지 않음.
	std::cout << *p << std::endl;		

	// iterator invalidate 되는 시점을 정확히 잘 알아야 함. (이거 잘알아야 문제가 생기지 않음.)
}



