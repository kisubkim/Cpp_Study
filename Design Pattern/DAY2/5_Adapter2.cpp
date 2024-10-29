#include <iostream>
#include <string>
#include <vector>

/*
	Adapter type
		Class Adapter : class 의 Interface 변경
		Object Adapter : Object 의 Interface 변경

	Class Adapter 는 노트북과 콘센트 사이에 사용되는 Adapter (220v -> dc 12v) 를 사용하는 거라고 생각을 하면 되고,
	Object Adapter 는 미국 가면 110v 에서 사용하기 위해 사용하는 돼지코 생각하면 된다.
*/

class TextView
{
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


/*
	
*/

class Text : public TextView,
	public Shape
{
public:
	Text(const std::string& data) : TextView(data) {}

	void draw() override {
		TextView::show();
	}
};

// object adapter 를 만들어 보자
class ObjectAdapter : public Shape {
	TextView* tview;		// 핵심 : 포인터 또는 참조 멤버 데이터
							// 의도 : 이미 만들어진 객체를 가리키겠다!!

public:
	ObjectAdapter(TextView* t) : tview(t) {}

	void draw() {
		tview->show();
	}
};

int main()
{
	std::vector<Shape*> v;
	TextView tv("hello");		// TextView : class(data type), tv : 객체(변수)

	// 이미 생성된 객체 tv 를 v 에 넣ㅇ르 수 있을 까요?
	//v.push_back(&tv);		// error

	// tv 를 v에 넣기 위해 Text 를 사용할 수 있을까?
	// => 아됨. Text 는 class adapter 임.

	v.push_back(new ObjectAdapter(&tv));		// 돼지코!

	v[0]->draw();
}

/*
	


*/







