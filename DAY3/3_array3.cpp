#include "show.h"
#include <array>		//c++11 에서 추가된 array

int main() {
	std::array<int, 5> arr = {1,2,3,4,5};

	std::cout << arr.size() << std::endl;

	// std::array는 결국 raw array임.
	// raw array로 안되는 작업은 std::array도 안됨.
	//arr.push_back(0);		// error
	//arr.resize(20);			// error
}