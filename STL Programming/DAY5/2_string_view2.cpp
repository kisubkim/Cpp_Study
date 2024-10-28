#include <iostream>
#include <string>
#include <string_view>

//void bad(std::string s) { }		//^ call by value : 복사본이 overhead에 있음.
void good(const std::string& s) {}
void best(std::string_view   s) {}

//& 같은 문자열은 constanct memory 상에 1개만 있음.

int main()
{
	std::string s = "to be or not to be";

	//^ 요 아래 2개는 비슷하게 진행
	//good(s);
	//best(s);

	//^ 아래 2개는 차이가 많음.
	//& seq. 확실히 알아 둘 것.
	good("to be or not to be");		// 선언에서 string& 되어 있기 때문에 
									// 1. string 임시 객체를 만들고
									// 2. 상수메모리에서 임시 객체에 문자열 복사해 넣고
									// 3. 임시 객체를 함수에 전달
	best("to be or not to be");		// 1. string_view 임시 객체 생성
									// 2. 상수메모리 주소를 임시객체 *에 기입. 끝

	// C
	char ss[] = "to be or not to be";
	const char* = "to be or not to be";
}
