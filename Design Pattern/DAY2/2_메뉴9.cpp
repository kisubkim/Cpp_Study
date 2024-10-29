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
	~PopupMenu() {
		for (auto e : v)
			delete e;
	}
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

	// 모든 메뉴 객체는 사용 후 delete 되어야 한다고 해보자.
	/*
		방법
			1. 스마트 포인터 사용 (std::shared_ptr) <-- 이거 사용할 줄 알면, 이게 제일 좋음
			2. root만 delete
				=> root의 소멸자 (~PopupMenu()) 에서
				   자신이 가진 하위 메뉴를 다시 delete
	*/

	root->command();

	delete root;
}


/*
	

*/
