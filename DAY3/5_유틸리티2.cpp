#include <iostream> // 표준 입출력 스트림 (화면)
#include <fstream>  // 화일 스트림
#include <sstream>  //^ 메모리(스트링)스트림
#include <string>

//^ C++ 3개의 stream을 가짐.
//^ 

// namespace  std
// {
// 	class ostream {};		// 표준 출력 stream
// 	class ofstream {};		// file 출력
// 	class ostringstream() {};	// 메모리(string)에 출력

// 	ostream cout; // 미리 객체가 생성 O. 전역
// 	//^ file 출력은 정해지지 않았기 때문에 미리 선언 X
	
// } // namespace  std

int main()
{
	std::ostringstream oss;

	std::cout << "hhhh";
	oss << "hello";		// oss가 내부적으로 가진 버퍼 (string)에 출력

	// oss 가 가진 문자열 꺼내기
	std::string s = oss.str();

	std::cout << s << std::endl;

}
