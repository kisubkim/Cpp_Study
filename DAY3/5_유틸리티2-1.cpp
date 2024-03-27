#include <iostream> // 표준 입출력 스트림 (화면)
#include <fstream>  // 화일 스트림
#include <sstream>  //^ 메모리(스트링)스트림
#include <string>


int main()
{
	double d = 3.1415;

	// "d = 3.1415" 라는 문자열을 만드어 보자.

	// c언어
	char s[32];
	sprintf(s, "d = %lf", d);		// buffer overflow 발생 가능성 있음. d가 정확도가 높을 경우
	snprintf(s, 32, "d = %lf", d);	// data 손실 가능성 있음. 32자리 넘을 경우

	std::ostringstream oss;
	oss << "d = " << d;
	std::string ss = oss.str();		// 손실 가능성 없음. 그런데 속도는?

}
