#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// list		: ��� ��Ұ� ���� Ÿ��.      �������� ����
// �޴�����  : ��� ��Ұ� ���� Ÿ�� �ƴ�. Tree ����


class PopupMenu; // ���� ����
class MenuItem;  

// �޴� �湮�� �������̽�
struct IMenuVisitor
{
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

	virtual void accept(IMenuVisitor* visitor) = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override
	{
		std::cout << get_title() << " �޴��� ���õ�" << std::endl;
		_getch();
	}


	void accept(IMenuVisitor* visitor)
	{
		// �ڽŸ� �湮�ڿ� ���� �ϸ� �˴ϴ�.
		// => ���� �޴� ����
		visitor->visit(this);
	}
};







class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:

	// �˾��޴��� �湮�ڰ� �湮 �Ҷ� - �ٽ�.. ���� �߿�!!
	void accept(IMenuVisitor* visitor)
	{
		// #1. �ڽ��� �湮�ڿ� ����
		visitor->visit(this);

		// #2. �ڽ��� ���� ���� �޴� ���� �ϸ� �ȵ˴ϴ�.
		// => �Ʒ� ó���ϸ� "�����ڽĸ޴��� ���޵˴ϴ�."
		/*
		for (auto m : v)
			visitor->visit(m);
		*/

		// #2. �湮�ڸ� �����޴��� �����ؾ� �մϴ�.
		// => �湮�ڰ� ���� �޴��� �ٽ� �湮
		for (auto m : v)
			m->accept(visitor);

	}





	PopupMenu(const std::string& title) : BaseMenu(title) {}

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

			std::cout << sz + 1 << ". ����" << std::endl;

			int cmd;
			std::cout << "�޴��� �����ϼ��� >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command();
		}

	}

};

// �� �ڵ�� ���� "�޴��� �湮�� ������ ����Ҽ� �ֵ��� ����"
// �Ǿ����ϴ�.

// ���� �پ��� �湮��(�Ѱ���ҿ� ���ѿ�������)�� ����� �˴ϴ�.

class TitleDecorateVisitor : public IMenuVisitor
{
	std::string popup_deco;
	std::string item_deco;
public:
	TitleDecorateVisitor(const std::string& s1, const std::string& s2)
		: popup_deco(s1), item_deco(s2) {}

	void visit(PopupMenu* m) override 
	{
		auto s = m->get_title();

		s = s + popup_deco;

		m->set_title(s);
	}
	void visit(MenuItem* m) override 
	{
		auto s = m->get_title();

		s = s + item_deco;

		m->set_title(s);
	}
};




int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("�ػ� ����");
	PopupMenu* pm2 = new PopupMenu("���� ����");

	root->add_menu(pm1);
	root->add_menu(pm2);


	pm1->add_menu(new MenuItem("HD",  11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));
	
//	TitleDecorateVisitor tdv(" >", "");
	TitleDecorateVisitor tdv(" >", "*");
	root->accept(&tdv);

	root->command();
}

// �޴� ����
// => TREE ���·� ���� �޴� ��ü�� ���� �ֽ��ϴ�.

// => ������ �ݺ��� ���� ���� �����Ƿ� �ܺο��� "for" ������ ���žȵ˴ϴ�.

// => ������, �湮�� ������ �����ǹǷ�
// => ��� ��ҿ� � �۾��� �Ϸ��� "�湮��"�� ���� ������ �˴ϴ�.  



