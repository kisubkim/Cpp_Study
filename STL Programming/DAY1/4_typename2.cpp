#include <iostream>
#include <vector>
#include <list>

// void print_first_element(std::vector<int>& v)
// {
// 	int n = v.front();
// 	std::cout << n << std::endl;
// }


// template<typename T>
// void print_first_element(std::vector<T>& v)
// {
// 	T n = v.front();
// 	std::cout << n << std::endl;
// }

template<typename T>
void print_first_element(T& v)
{
	// auto 말고 아래를 수정하면?
	// T = list<double>
	// T::value_type : std::list<double>::value_type 이르모 "double" 임.
	// 그리고 template 에 사용되는 변수를 가져와서 사용할 때, 무조건 value로 처리하기 때문에 앞에 typename 필요,
	// 이거 dependent name 중요함!!

	typename T::value_type n = v.front();
	std::cout << n << std::endl;
}


int main()
{
//	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
//	std::vector<double> v = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<double> v = { 1,2,3,4,5,6,7,8,9,10 };
	print_first_element(v);
}


// 모든 template 기반의 컨테이너는 "자신이 저장하는 요소의 타입"이 있슴.
// 그 타입을 외부에서 알고 싶을 때 사용하게 하는 법이 있음.
// 

/*
template<typename T>
class list1 {
	public:
	using value_type = T; // 요게 핵심임.

};

std::list<int> s = {1,2,3};
std::list<int>::value_type n = s.front(); // n의 type??
*/

// class : member data + member function 
// class template (STL) : member data + member function + member type으로 구성. value_type 같은 개념.

// cppreference.com 에서 std::list 검색.
