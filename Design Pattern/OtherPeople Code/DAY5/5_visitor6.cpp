#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// list : 모든 요소가 동일타입							선형구조
// 메뉴 : 모든 요소가 동일타입아님(Popup 또는 MenuItem)	tree구조

class PopupMenu;
class MenuItem;

struct IMenuVisitor
{
	//	virtual void visit(BaseMenu* bm) = 0;
					// => PopupMenu, MenuItem 모두 받을수 있지만
					// => 같은 구현을 사용하겠다는 의도

	virtual void visit(PopupMenu* pm) = 0;
	virtual void visit(MenuItem* mi) = 0;

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

	virtual void accept(IMenuVisitor* visitor) = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}


	void accept(IMenuVisitor* visitor)
	{
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

	void add_menu(BaseMenu* p) { v.push_back(p); }



	void accept(IMenuVisitor* visitor)
	{
		// #1. 방문자에게 자신을 전달
		visitor->visit(this);

		/*
		// #2. 하위 메뉴도 방문자에게 전달 하면 안됩니다.
		// => 자신이 가진 메뉴만 전달되고,
		// => 그 하위 메뉴는 전달안됩니다.
		for (auto m : v)
			visitor->visit(m);
		*/

		// #2. 하위 메뉴에도 방문자를 방문시켜야 합니다.
		for (auto m : v)
			m->accept(visitor);

	}















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

class TitleChangeVisitor : public IMenuVisitor
{
	std::string deco_popup;
	std::string deco_menu;
public:
	TitleChangeVisitor(const std::string& s1, const std::string& s2)
		: deco_popup(s1), deco_menu(s2) {}

	// 결국 아래 함수에서는 "요소 한개" 에 대한 연산의 정의 입니다.
	void visit(PopupMenu* pm)
	{
		auto s = pm->get_title() + deco_popup;
		pm->set_title(s);
	}

	void visit(MenuItem* mi)
	{
		auto s = mi->get_title() + deco_menu;
		mi->set_title(s);
	}
};






int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);

	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));


	// root 가 가진 모든 메뉴에 대해서 타이틀을 변경해 봅시다.
	// 방법 #1. 외부에서 직접 열거하면서 타이틀 변경 - iterator 가 필요 합니다.
	// 방법 #2. 방문자(visitor) 패턴 사용

	TitleChangeVisitor tcv(" >", " *");

	root->accept(&tcv);


	root->command();

}



