// 15page ~ 
#include <iostream>
#include <vector>

class Shape {
	int color;
public:
	virtual ~Shape() {};
};

struct Rect : public Shape {
	void draw() {
		std::cout << "draw Rect\n";
	}
};

struct Circle : public Shape {
	void draw() {
		std::cout << "draw Circle\n";
	}
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
				if (dynamic_cast<Rect*>(s) != nullptr)  // 다이나믹 캐스트 사용시 좋지 않은 디자인이 될 가능성이 상당히 높습니다                      
					static_cast<Rect*>(s)->draw();
				else if (dynamic_cast<Circle*>(s) != nullptr)
					static_cast<Circle*>(s)->draw();
		}

	}
}