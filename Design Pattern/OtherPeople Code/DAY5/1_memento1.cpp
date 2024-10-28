﻿﻿// github.com/codenuri/ssdp 에서 "DAY5.zip" 

#include <iostream>


// 화면에 그림을 그릴때 사용하는 클래스
class Graphics
{
	// 수백가지의 그리는 함수를 제공합니다.
};

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// 선의 색상이나 두께 등을 변경하고 싶습니다.

	// 방법 #1. 함수 인자로 전달하자
	// => windows gdi+ 라이브러리
	g.DrawLine(0, 0, 100, 100, red, 20);
	g.DrawLine(0, 0, 100, 100, red, 20);


	// 방법 #2. Graphics 객체의 속성으로 지정하자
	// => ios 의 cocoa touch 라이브러리
	g.SetStrokeColor(red);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 100, 100);
}




