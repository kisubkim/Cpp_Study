// 8_메멘토 - 178
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

	/*
		방법
			1. 함수의 인자로 전달.
				=> Windows os gdi+ Library 방식

			2. Graphics 객체의 속성으로 전달.
				=> IOS의 cocoa touch
	*/

	// 방법 1
	g.DrawLine(0, 0, 100, 100, red, 10, 점선스타일);		// 추가된 3개는 색상, 두께, 스타일
	g.DrawLine(0, 0, 100, 100, red, 10, 점선스타일);

	// 방법 2
	g.SetStrokeColor(red);		// property 만들어서 set 하는 방식.
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 100, 100);
}









