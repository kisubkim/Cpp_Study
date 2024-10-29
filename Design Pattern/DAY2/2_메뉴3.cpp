#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

/*
	������� �ٽ�
		=> �޴� ���α׷��� ���� ���� ��� ���� Ÿ������ ���� �����Ѵٴ� ��.
		=> "MenuItem", "PopupMenu", etc.

*/

class MenuItem {
	std::string title;
	int id;

public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() { return title; }


	void command() {
		std::cout << get_title() << " �޴� ����\n";
		_getch();
	}
};

class PopupMenu {
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add(MenuItem* m) { v.push_back(m); }

	// �ٽ� : POpupMenu�� ���õ� �� ������ �����غ�����.
	// 1. ���
	// 2. ���
	// 3. ����
	// �޴��� �����ϼ���.
	void command() {

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
	MenuItem m1("���", 11);
	MenuItem m2("���", 11);

	PopupMenu pm("������ ���� �޴�");
	pm.add(&m1);
	pm.add(&m2);

	pm.command();		// PopupMEnu�� ������ �� ������ �����غ���.


}




