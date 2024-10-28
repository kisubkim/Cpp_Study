#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.

// TextView : 문자열을 보관하고 있다가 화면에 이쁘게 출력하는 기능 제공

class TextView
{
	// font 이름, 크기, 두께등 다양한 정보 관리
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};





//=================================================
class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// 도형편집기 예제에 문자열을 관리하는 클래스를 추가하고 싶다.!!
// => 예전에 구했던 "TextView" 를 여기에서 사용할수 있을까 ?
// => 사용할수 없다. "도형편집기는 draw" 를 요구하 는 데
//   TextView 는 show 를 제공

// TextView 를 도형편집기에서 사용할수 있게 바꾸는 도구를 만들자

class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	// 아래 부분이 "show" 라는 함수 이름을 "draw" 라는 이름으로 변경
	// 하는 코드. "어답터 패턴"의 핵심
	void draw() override
	{
		TextView::show();
	}
};


int main()
{
	std::vector<Shape*> v;

	Text tv("hello");
	v.push_back(&tv);

	v[0]->draw();
}

// Adapter 패턴
// => 기존 클래스의 인터페이스(함수이름)를 시스템에 요구사항에 맞도록
//    변경해주는 클래스를 만드는 패턴

// => 인터페이스의 불일치를 해결하는 패턴






