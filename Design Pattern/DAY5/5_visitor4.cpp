#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

/*
	List	: ��� ��Ұ� ���� Ÿ��
			  ��� ��Ұ� ��������.

	�޴�����	: ��� ��Ұ� �ٸ� Ÿ�� (���� Ÿ�� �ƴ�)
			  ��� ��Ұ� ������(Ʈ��)

*/

class PopupMenu;
class MenuItem;

// �湮�� �������̽�
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
		// #1 �ڽ��� ����ڿ� ����.
		visitor->visit(this);
	}

	void command() override
	{
		std::cout << get_title() << " �޴��� ���õ�" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	/*
		popup menu �� �湫�ڰ� �湮�� ��
		�� �κ��� ���� �߿���
	*/
	void accept(IMenuVisitor* visitor) {
		// #1 �ڽ��� ����ڿ� ����.
		visitor->visit(this);

		// #2 �ڽ��� ������ �湮�ڿ� �ڽ� �����ϸ� X.
		//		=> �Ʒ�ó�� �ϸ� "�����ڽĸ޴��� ������"
		/*for (auto e : v) {
			visitor->visit(e);
		}*/

		// #2 �湮�ڸ� �����޴��� ������ �ؾ���.
		//		=> �湮�ڰ� ���� �޴��� �ٽ� �湮.
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

	
	TitleChangeVisitor tcv(" >", "");
	root->accept(&tcv);

	root->command();
}

/*
	Menu Structure
		=> Tree ���·� ���� �޴� ��ü�� ���� ����.
		=> ������ Iterator ���� ���� ���� �ܺο��� "for" ������ ���� �ȵ�.
		=> ������, Visitor Pattern �� ���������� ��� ��ҿ� � �۾��� �Ϸ��� "Visitor"�� ���� ������ ��.
*/



