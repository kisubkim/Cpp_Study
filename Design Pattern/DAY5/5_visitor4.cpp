#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

/*
	List	: 모든 요소가 같은 타입
			  모든 요소가 선형적임.

	메뉴예제	: 모든 요소가 다른 타입 (같은 타입 아님)
			  모든 요소가 비선형임(트리)

*/

class PopupMenu;
class MenuItem;

// 방문자 인터페이스
struct IMenuVisitor {
	virtual void visit(PopupMenu* m) = 0;
	virtual void visit(MenuItem* m) = 0;
	virtual ~IMenuVisitor() {}
};



class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	void set_title(const std::string& s) { title = s; }

	virtual void command() = 0;
	virtual void accept(IMenuVisitor* p) {}
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void accept(IMenuVisitor* visitor) {
		// #1 자신을 방운자에 전달.
		visitor->visit(this);
	}

	void command() override
	{
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	/*
		popup menu 에 방무자가 방문할 때
		이 부분이 제일 중요함
	*/
	void accept(IMenuVisitor* visitor) {
		// #1 자신을 방운자에 전달.
		visitor->visit(this);

		// #2 자식이 있으면 방문자에 자식 전달하면 X.
		//		=> 아래처럼 하면 "직계자식메뉴만 전달함"
		/*for (auto e : v) {
			visitor->visit(e);
		}*/

		// #2 방문자를 하위메뉴에 전달을 해야함.
		//		=> 방문자가 하위 메뉴를 다시 방문.
		for (auto m : v)
			m->accept(visitor);
	}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". 종료" << std::endl;

			int cmd;
			std::cout << "메뉴를 선택하세요 >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command();
		}

	}

};


class TitleChangeVisitor : public IMenuVisitor {
	std::string popup_deco;
	std::string item_deco;
public:
	TitleChangeVisitor(const std::string& s1, const std::string& s2) : popup_deco(s1), item_deco(s2) {}
	void visit(PopupMenu* m) override {
		std::string s = m->get_title();
		s = s + popup_deco;
		m->set_title(s);
	}

	void visit(MenuItem* m) override {
		std::string s = m->get_title();
		s = s + item_deco;
		m->set_title(s);
	}
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);


	pm1->add_menu(new MenuItem("HD",  11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));

	
	TitleChangeVisitor tcv(" >", "");
	root->accept(&tcv);

	root->command();
}

/*
	Menu Structure
		=> Tree 형태로 많은 메뉴 객체가 놓여 있음.
		=> 하지만 Iterator 같은 것이 없어 외부에서 "for" 등으로 열거 안됨.
		=> 하지만, Visitor Pattern 이 지원됨으로 모든 요소에 어떤 작업을 하려면 "Visitor"를 만들어서 넣으면 됨.
*/



