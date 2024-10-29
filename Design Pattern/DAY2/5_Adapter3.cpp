#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// 1. C++ 표준 라이브러리인 STL 에는 이미 list가 있습니다.
// 2. 그런데, stack 이 필요합니다.


// decorator 와 adapter 는 코드가 유사해 보임.
// decorator
class ZipDecorator : public Stream {
	Stream* origin;
public:
	ZipDecorator(Stream* s) : origin(s) {}
	void write(const std::string& s) {
		auto s2 = "[" + s + "]" + "압축됨";		// 압축기능 추가
		origin->write(s2);
	}
};

// adapter
class ObjectAdapter : public Shape {
	TextView* tview;

public:
	ObjectAdapter(TextView* t) : tview(t) {}

	void draw() {
		tview->show();
	}
};

int main()
{
	// Pattern을 정확히 이해하기 시작하면서 느끼게 되는 것은
	// 다양한 pattern이 "동일(유사)"해 보이기 시작함.
	// 
	// 이럴 땐 항상 의도를 생각하자. (비슷해 보여도 확실히 다름!)

	// decorator 목적 : 기능의 추가
	FileStream fs("a.txt");
	ZipDecorator zd(&fs);

	fs.write("abcd");
	zd.write("abcd");		// 원본과 동일한 함수 이름이지만 압축 기능의 추가

	// Adapter의 목적 : Interface의 변경
	TextView tv("hello");
	ObjectAdapter oa(&tv);

	tv.show();		// 원래 함수의 이름을 
	oa.draw();		// 이렇게 변경하는 것. (기능은 동일)
}
