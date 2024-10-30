#include <vector>
#include <iostream>

template<typename T>
class take_view {
	T& c;
	int count;
public:
	take_view(T& c, int count) : c(c), count(count) {}

	auto begin() { return c.begin(); }
	auto end() { return c.begin() + count; }
};


/*

	아래 코드에서 vector는 10개의 자원을 가지고 있음.
	[1,2,3,4,5,6,7,8,9,10]

	take_view 는 & 와 count를 받음.
	c ----> [1,2,3,4,5,6,7,8,9,10]    // c 는 vector 를 가리키는 포인터
	begin() 과 end()를 다시 정의함에 따라서..begin()은 동일.
	하지만 end() 는 begin()에서 count 만큼만 이동한 부분을 end()로 정의함.

	for의 경우 항상 begin() 에서 end() 까지 반복하기 때문에 count 만큼만 보게됨.

*/

int main() {
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	take_view tv(v, 3);		// c++17부터는 type을 넣지 안아도 추론이 가능해서 <int>를 생략

	//for (auto e : v) {
	for (auto e : tv) {		// 생각해 보자.
		std::cout << e << ", ";
	}
	std::cout << "\n";



	auto first = v.begin();
	auto last = v.end();

	for (; first != last; ++first) {
		auto e = *first;
		//--------------
		std::cout << e << ",";		// 사용자 code
	}
}