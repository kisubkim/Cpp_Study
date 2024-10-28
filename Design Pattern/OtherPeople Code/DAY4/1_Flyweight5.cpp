#include <string>
#include <string_view> // C++17

int main()
{
	// std::string 은 문자열을 "소유" 합니다.
	std::string s = "abcd";

	// #1.
	std::string      ss = s; // s의 문자열을 ss도 별도로 복사.(깊은 복사)
	std::string_view sv = s; // sv가 ss의 문자열을 가리킴(const char* )

	// #2. literal 로 초기화 하는 경우
	// => 프로그램 실행시 "abcd" 는 일단 상수메모리(.rdata)에 있다!!
	std::string      ss1 = "abcd"; // abcd의 복사본을 만들어서 ss1이 소유
	std::string_view sv1 = "abcd"; // 상수 메모리에 있는 "abcd" 를 가리킨다
	// const char* 와 유사
}