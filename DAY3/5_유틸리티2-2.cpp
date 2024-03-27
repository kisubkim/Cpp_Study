#include <iostream> // 표준 입출력 스트림 (화면)
#include <fstream>  // 화일 스트림
#include <sstream>  //^ 메모리(스트링)스트림
#include <string>

// 한번 속도 측정을 해볼 필요는 있을 듯.
// cout 도 printf 에 비해서 너무 느려서 안씀.

int main()
{
	std::ostringstream oss;
	std::istringstream iss("to be or not to be");

	std::string s;
	//std::cin >> s;		// 표준 입력에서 한단어 입력
	//iss >> s;		// memory 에서 한단어 입력

	while(iss >> s)		// iss 에서 한단어씩 꺼내 s에 넣으면 true, 아니면 false
		std::cout << s << std::endl;
}
