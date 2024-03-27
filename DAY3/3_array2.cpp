#include <vector>
#include <algorithm>
#include "show.h"

template<typename T, std::size_t N>
struct array
{
	T buff[N];

	int size() const { return N;}

	// STL의 규칙 지키기
	using value_type = T;
	using iterator = T*;

	iterator begin() { return buff; }
	iterator end() { return buff+N; }	//^ 요거 확실히 이해할 것.
};

int main()
{
	// 구조체 내부에 array 있으면 아래처럼 초기화도 가능.
	// memory struct가 처음부터 data들이 쌓이듯 만들어지기 때문.
	array<int, 5> arr = {1, 2, 3, 4, 5};

	std::cout << arr.size() << std::endl;

}
