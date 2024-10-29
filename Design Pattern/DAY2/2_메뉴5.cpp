#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

/*
	C ���   : �޸� ������ �����ϱ� ���� "�޸� �׸�"�� �׸��鼭 �н��մϴ�.
	��ü���� : �������� �����ϱ� ���� "Ŭ���� ���̾�׷�"�� �׸��鼭 �н��ϼ���
	
*/

class BaseMenu {
	std::string title;
public :
	BaseMenu(const std::string& title) : title(title) {}
	std::string get_title() { return title; }

	// ��� �޴��� ���õ� �� �ֽ��ϴ�.
	//   => ��� ���� Ŭ������ ������ Ư¡�� ���Ŭ�������� �־�� �մϴ�.
	virtual void command() = 0;
	virtual ~BaseMenu() {}
};

class MenuItem : public BaseMenu {
	int id;

public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override {
		std::cout << get_title() << " �޴� ����\n";
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
			std::cout << sz + 1 << ". ����" << std::endl;

			std::cout << "�޴��� �����ϼ��� >> ";

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
};


int main()
{
	MenuItem m1("��ġ ���", 11);
	MenuItem m2("�Ұ����ġ ���", 12);
	MenuItem m9("���", 19);

	PopupMenu kimbab("����");
	kimbab.add(&m1);
	kimbab.add(&m2);

	PopupMenu pm("������ ���� �޴�");
	pm.add(&kimbab);

	pm.add(&m9);

	pm.command();


}




