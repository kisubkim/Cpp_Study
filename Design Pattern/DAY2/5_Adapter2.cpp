#include <iostream>
#include <string>
#include <vector>

/*
	Adapter type
		Class Adapter : class �� Interface ����
		Object Adapter : Object �� Interface ����

	Class Adapter �� ��Ʈ�ϰ� �ܼ�Ʈ ���̿� ���Ǵ� Adapter (220v -> dc 12v) �� ����ϴ� �Ŷ�� ������ �ϸ� �ǰ�,
	Object Adapter �� �̱� ���� 110v ���� ����ϱ� ���� ����ϴ� ������ �����ϸ� �ȴ�.
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

// object adapter �� ����� ����
class ObjectAdapter : public Shape {
	TextView* tview;		// �ٽ� : ������ �Ǵ� ���� ��� ������
							// �ǵ� : �̹� ������� ��ü�� ����Ű�ڴ�!!

public:
	ObjectAdapter(TextView* t) : tview(t) {}

	void draw() {
		tview->show();
	}
};

int main()
{
	std::vector<Shape*> v;
	TextView tv("hello");		// TextView : class(data type), tv : ��ü(����)

	// �̹� ������ ��ü tv �� v �� �֤��� �� ���� ���?
	//v.push_back(&tv);		// error

	// tv �� v�� �ֱ� ���� Text �� ����� �� ������?
	// => �Ƶ�. Text �� class adapter ��.

	v.push_back(new ObjectAdapter(&tv));		// ������!

	v[0]->draw();
}

/*
	


*/







