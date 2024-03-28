#include <iostream>

// 아래처럼 하면, Hash라는게 template 이라는걸 선언한 것임.
template<typename T>
struct Hash;

//& Template Specialization(특수화) 문법.
// 아래는 Hash<int>를 사용하면 아래를 사용하라는 이야기.
template<>
struct Hash<int> {
	int operator()(int n) const {
		std::cout << "int를 위한 hash algorithm\n";
		return 0;
	}
};

// 아래는 Hash<double> 에 대한 Hash Function 임.
// 즉, 다른 type에 대한 hash도 만들지 않았으면 사용하면 Error 남.
template<>
struct Hash<double> {
	int operator()(int n) const {
		std::cout << "int를 위한 hash algorithm\n";
		return 0;
	}
};

//* 결국 std::hash< > 에서 사용할 수 있는 hash function은 언어 자체에 있는 type 만 되어 있음.
//* 사용자정의 type은 모두 만들어야함.

int main() {
	Hash<int> hi;
	int n = hi(10);
}