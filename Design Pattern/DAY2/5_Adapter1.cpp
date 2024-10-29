#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.

// TextView : 문자열을 보관하고 있다가, 화면에 이쁘게 출력하는 기능
// 이게 아주 좋아서 어딘가에 저장해 놓은 code가 아래와 같이 있다고 생각하자.
// 어케든 이걸 활용하고 싶은 상황이라고 생각하자.

class TextView
{
	std::string data;
	// font name, size, color, etc. 많은 member가 있다고 가정.
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


/*
	도형편집기 예제에 "문자열" 을 출력하는 클래스가 필요하다! 면..
		=> 예전 부터 가지고 있던 "TextView"를 여기서 사용할 수 있을까?
		=> 안됨.
			1. 도형편집기는 "draw()" 요구, TextView는 "show()" 제공
			2. 도형편집기는 "Shape" 로 부터 파생된 클래스만 사용 가능.
		=> 결국, Interface(함수이름)의 불일치 때문에 안됨.

	Adapter Pattern
		=> 기존 클래스의 interface를 시스템이 요구하는 형태로 변경해 주는 class를 만드는 pattern
		=> "Interface 불일치 해결"
		=> "Interface(함수이름) 변경"
*/

// interface 불일치를 해결해 보자
class Text : public TextView,		// TextView의 모든 기능을 물려받고
			 public Shape			// 시스템(도형편집기)의 요구조건도 만족시키기 위해 shape도 상속받음
{
public:
	Text(const std::string& data) : TextView(data) {}

	// 핵심 : show() => draw() 로 함수 이름을 변경하는 부분
	// "인터페이스 불일치"를 해결하는 코드
	void draw() override {
		TextView::show();
	}
};

int main()
{
	std::vector<Shape*> v;
	//v.push_back(new TextView("hell0"));		// error
	v.push_back(new Text("hello"));		// ok
	v[0]->draw();
}







