#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

/*

*/

class unsupported_operation {

};

class BaseMenu {
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	std::string get_title() { return title; }

	virtual void command() = 0;
	virtual ~BaseMenu() {}

	// 아래 2개의 멤버 하수는 "PopupMenu"만 필요함.
	// 그런데, 사용자의 편의성을 고려해서 BaseMenu에서 부터 제공

	// 아래처럼 만들면 필요없는 "MenuItem" 에서도 구현을 제공해야 함.
	// virtual void add(BaseMenu*) = 0;
	// virtual BaseMenu* submenu(int idx) = 0;

	virtual void add(BaseMenu*) { throw unsupported_operation(); }
	virtual BaseMenu* submenu(int idx) { throw unsupported_operation(); }
};

class MenuItem : public BaseMenu {
	int id;

public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override {
		std::cout << get_title() << " 메뉴 선택\n";
		_getch();
	}
};

class PopupMenu : public BaseMenu {
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add(BaseMenu* m) { v.push_back(m); }

	void command() override {

		while (1) {
			system("cls");

			auto sz = v.size();
			for (int i = 0; i < sz; i++) {
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료" << std::endl;

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1) {
				break;
			}

			if (cmd < 1 || cmd > sz + 1) {
				continue;
			}

			v[cmd - 1]->command();
		}
	}

	BaseMenu* submenu(int idx) { return v[idx]; }
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");
	PopupMenu* pm2 = new PopupMenu("해상도 변경");

	root->add(pm1);
	root->add(pm2);
	root->add(new MenuItem("재부팅", 12));
	//-------------------------------------------------

	auto m1 = root->submenu(0);	

	// 캐스팅 없이 사용!!!
	root->submenu(1)->add(new MenuItem("HD", 21));	// ok 정상동작.

	try {
		root->submenu(2)->add(new MenuItem("HD", 21));	// 컴파일은 되지만, MenuItem에 대해 add 호출이므로 실행 시 예외
	}
	catch (unsupported_operation& e) {
		std::cout << "예외 발생" << std::endl;
	}

	static_cast<PopupMenu*>(root->submenu(1))->add(new MenuItem("HD", 21));


	root->command();
}


/*
	compile error : 개발 중 발생하므로 "안전"하다.
	runtime error : 개발 후 배포된 상태에서도 발생할 수 있으므로 안전하지 않다.

	메뉴7.cpp : 안전성을 중시하는 모델
	메뉴8.cpp : 편의성을 중시하는 모델

	2개 방식 모두 널리 사용하고, 장단점이 있음.

		=> pthon, C#, java 등 사용하기 쉬운 언어들은 "메뉴8" 방시으로 많이 되어 있음.

*/
