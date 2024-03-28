#include "chronometry.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

//& vector는 무조건 reserve() 사용해서 할당할 것. 속도차가 너무남.
//^ 이거 강사님께 문의해보니 memory 할당만 되고 생성자를 호출하지 않음.
//^ 그렇다면 생성자가 없는 경우에는 동일한가??

struct testNode {
	int a;
	float b;
};
const int testNum = 10000000;
void memoryallocCheck1(){
	std::vector<testNode, debug_alloc<testNode>> v1;
	v1.reserve(testNum);
	std::cout << "reserve \n";
	std::cout << v1.size() << ", " << v1.capacity() << std::endl;
	for(int i=0; i<testNum; i++)
		{
			v1.push_back(testNode{1,1.1});
		}
	std::cout << v1.size() << ", " << v1.capacity() << std::endl;
}

void memoryallocCheck2() {
	std::vector<testNode, debug_alloc<testNode>> v1(testNum);
	std::cout << "base define \n";
	std::cout << v1.size() << ", " << v1.capacity() << std::endl;
	for(int i=0; i<testNum; i++)
		v1[i] = testNode{1,1.1};
	std::cout << v1.size() << ", " << v1.capacity() << std::endl;
}

void memoryallocCheck3(){
	std::vector<testNode, debug_alloc<testNode>> v1;
	v1.resize(testNum);
	std::cout << "resize \n";
	std::cout << v1.size() << ", " << v1.capacity() << std::endl;
	for(int i=0; i<testNum; i++)
		v1[i] = testNode{1,1.1};
	std::cout << v1.size() << ", " << v1.capacity() << std::endl;
}


int main()
{
	
	chronometry(memoryallocCheck1);
	chronometry(memoryallocCheck2);
	chronometry(memoryallocCheck3);
	//chronometry([](){std})

	return 0;
}

